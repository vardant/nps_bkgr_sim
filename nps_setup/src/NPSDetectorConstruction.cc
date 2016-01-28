//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//

#include "NPSDetectorConstruction.hh"
#include "NPSTrackerSD.hh"

// **** Magnetic field ******
// New include files - used for magnetic field
#include "G4MagneticField.hh"
#include "G4UniformMagField.hh"
#include "SimpleField.hh"
#include "G4FieldManager.hh"
#include "G4TransportationManager.hh"
#include "G4MagIntegratorStepper.hh"
#include "G4Mag_UsualEqRhs.hh"
#include "G4ClassicalRK4.hh"
#include "G4ExplicitEuler.hh"
#include "G4ChordFinder.hh"
#include "G4EqMagElectricField.hh"
#include "G4PropagatorInField.hh"
#include "G4UserLimits.hh"

// Shapes...
#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4UnionSolid.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4TwoVector.hh"
#include "G4ExtrudedSolid.hh"
#include "UExtrudedSolid.hh"
#include "G4SystemOfUnits.hh"

// Others...
#include "G4AutoDelete.hh"

using namespace std;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

NPSDetectorConstruction::NPSDetectorConstruction()
  : G4VUserDetectorConstruction(), fField(0), fEquation(0), fStepper(0),
    fChordFinder(0), fScoringVolume(0), fMeas(0)
{ }
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
// the more involved constructor is in the .hh file!

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

NPSDetectorConstruction::~NPSDetectorConstruction()
{
  delete fField;
  delete fEquation;
  delete fStepper;
  delete fChordFinder;
  delete fScoringVolume;
  delete fMeas;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* NPSDetectorConstruction::Construct()
{
  /*
  G4bool checkOverlaps = true;
  G4cout << "Using hard-coded geometry!"<<G4endl;
  DefineMaterials();
  DefineBasicGeometry();
  ConstructMagnet();
  //
  */

  // Setup Magnetic Field here!!!
  ConstructField();

  // Setup sensitive detector!
  ConstructSDandField();

  //always return the physical World
  return physWorld;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void NPSDetectorConstruction::DefineMaterials()
{
  ///#include "AmagnetDefineMaterials.icc"
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
/*
void NPSDetectorConstruction::DefineBasicGeometry()
{
  // GN 2015
  // Define the geometry of our world!
  // Mother volume & envelope parameters mostly.
  // Envelope parameters
  //
  env_size[0] = 150.*cm;
  env_size[1] = 150.*cm;
  env_size[2] = 150.*cm;

  // Option to switch on/off checking of volumes overlaps
  //
  G4bool checkOverlaps = true;

  //     
  // World dimensions
  //
  world_size[0] = 200.*cm;
  world_size[1] = 200.*cm;
  world_size[2] = 200.*cm;
   
  G4Box* solidWorld =    
    new G4Box("World",                       //its name
	      world_size[0], world_size[1], world_size[2]);     //its size
      
  logicWorld =                         
    new G4LogicalVolume(solidWorld,          //its solid
                        world_material,           //its material
                        "World");            //its name
                                   
  physWorld = 
    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(),       //at (0,0,0)
                      logicWorld,            //its logical volume
                      "World",               //its name
                      0,                     //its mother  volume
                      false,                 //no boolean operation
                      0,                     //copy number
                      checkOverlaps);        //overlaps checking                   
  //     
  // Envelope
  //  
  G4Box* solidEnv =    
    new G4Box("Envelope",                    //its name
        0.5*env_size[0], 0.5*env_size[1], 0.5*env_size[2]); //its size
      
  logicEnv =                         
    new G4LogicalVolume(solidEnv,            //its solid
                        env_material,             //its material
                        "Envelope");         //its name
               
  new G4PVPlacement(0,                       //no rotation
                    G4ThreeVector(),         //at (0,0,0)
                    logicEnv,                //its logical volume
                    "Envelope",              //its name
                    logicWorld,              //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking
   
}
*/
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
/*
void NPSDetectorConstruction::ConstructMagnet()
{
  // GN 2015
  // Construct the magnet itself!
  //
  // Option to switch on/off checking of volumes overlaps
  //
  G4bool checkOverlaps = true;

  G4Color red(1.0,0.0,0.0),yellow(1.0,1.0,0.0), blue(0.,0.,0.7),
    copper(0.5,0.5,0.0);
  G4Color green(0,1.,0.), orange(1.0,0.5,0.0);

  //
  // GN: Attempt to Model the Amagnet...
  // the stuff below works but it is a lot !! of pain. 
  // 

  //////////////////////////////////////////////////////////////////////////////////////
  // COIL
  //////////////////////////////////////////////////////////////////////////////////////
  // long box
  G4double coilx_size=3.5*cm, coily_size=3.5*cm, coilz_size=37.*cm;
  G4double coil2y_size=7.*cm;
  G4double coil2y_offset=20.*cm, arc_offset=0.5*cm;
  G4Box *Coil1part=new G4Box("coil1part", coilx_size, coily_size, coilz_size);
  // short box
  G4Box *Coil2part=new G4Box("coil2part", coilx_size, coil2y_size, coilx_size);
  // arcs
  G4double r1=3.*cm, r2=10.*cm, phis=0.*deg, phif=90.*deg, arc_size=3.5*cm;
  G4Tubs *Arc1part=new G4Tubs("arc1part", r1, r2, arc_size, phis, phif);
  G4Tubs *Arc2part=new G4Tubs("arc1part", r1, r2, arc_size, 90.*deg, phif);
  // First Arc
  G4RotationMatrix *yRot = new G4RotationMatrix;  // Rotates X and Z axes only
  yRot->rotateY(M_PI/2.*rad);                     // Rotates 90 degrees
  G4ThreeVector zTrans(0, -coil2y_size+arc_offset, coilz_size);
  G4RotationMatrix invRot = yRot->invert();
  G4Transform3D transform(invRot, zTrans);  
  G4UnionSolid *Coil1 = new G4UnionSolid("Coil 1", Coil1part, Arc1part, transform);
  // Arc at the other end of the long box
  zTrans.set(0.,-coil2y_size+arc_offset,-coilz_size);
  G4Transform3D transform2(invRot, zTrans);
  G4UnionSolid *Coil2 = new G4UnionSolid("Coil 2", Coil1, Arc2part, transform2);
  // now position the upright part of the coil
  zTrans.set(0.,-2.*coil2y_size+arc_offset,r2-r1+coilz_size-arc_offset);
  // -2*coil2y_size
  G4UnionSolid *Coil3 = new G4UnionSolid("Coil 3", Coil2, Coil2part, 0, zTrans);
  G4RotationMatrix *RotateFlip = new G4RotationMatrix;
  RotateFlip->rotateY(M_PI*rad);
  RotateFlip->rotateZ(M_PI*rad);
  zTrans.set(0.,-2.*coily_size-coil2y_offset,0.);
  G4UnionSolid *CoilFinal = new G4UnionSolid("Coil 1", Coil3, Coil3, RotateFlip, zTrans);
  // finished coils                      
  G4LogicalVolume* logicCoil =                         
    new G4LogicalVolume(CoilFinal,         //its solid
                        coil_material,          //its material
                        "Coil1");           //its name
  logicCoil->SetVisAttributes(new G4VisAttributes(red));
  G4double maxStep = 1.*cm;
  G4double maxTime = 1*ms;
  G4UserLimits *fStepLimit=NULL;
  fStepLimit = new G4UserLimits(DBL_MAX,DBL_MAX,maxTime,1.*MeV,maxStep);
  logicCoil->SetUserLimits(fStepLimit);
  //
  G4double coil_Xdist=16.5*cm;
  //  G4double coil_Ydist=17.*cm;
  G4ThreeVector pos1 = G4ThreeVector(coil_Xdist, coil2y_size+r2-coily_size, 0);
  G4ThreeVector pos2 = G4ThreeVector(-coil_Xdist, coil2y_size+r2-coily_size, 0);
  // Place Coils
  
  new G4PVPlacement(0,                       //no rotation
                    pos1,                    //at position
                    logicCoil,             //its logical volume
                    "Coil1",                //its name
                    logicEnv,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking
  new G4PVPlacement(0,                       //no rotation
                    pos2,                    //at position
                    logicCoil,             //its logical volume
                    "Coil2",                //its name
                    logicEnv,                //its mother  volume
                    false,                   //no boolean operation
                    1,                       //copy number
                    checkOverlaps);          //overlaps checking

  /////////////////////////////////////////////////////////////////////////////////////
  // Now the Solid Core of the Magnet (assumed to be Fe for now)
  /////////////////////////////////////////////////////////////////////////////////////
  G4double coreZ_size = 40.*cm, coreX_offset=0.*cm;;
  std::vector<G4TwoVector> coilXY(4);
  coilXY[0]=G4TwoVector(-13.*cm, 10.*cm);
  coilXY[1]= G4TwoVector(-1.*cm,2.*cm);
  coilXY[2]= G4TwoVector(-1.*cm,-2.*cm);
  coilXY[3]= G4TwoVector(-13.*cm,-10.*cm);
  G4ExtrudedSolid *CoreFinal = new G4ExtrudedSolid("Core1", coilXY, coreZ_size, G4TwoVector(0, 0), 1.0, G4TwoVector(0, 0), 1.0);
 G4ThreeVector core_pos1 = G4ThreeVector(coreX_offset, 0, 0);
  G4ThreeVector core_pos2 = G4ThreeVector(-coreX_offset, 0, 0);
  // finished core material
  G4LogicalVolume* logicCore =                         
    new G4LogicalVolume(CoreFinal,         //its solid
                        core_material,          //its material
                        "Core1");           //its name
  logicCore->SetVisAttributes(new G4VisAttributes(blue));
  logicCore->SetUserLimits(fStepLimit);
  // Place Iron Core           
  new G4PVPlacement(0,                       //no rotation
                    core_pos1,                    //at position
                    logicCore,             //its logical volume
                    "Core1",                //its name
                    logicEnv,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking

  G4RotationMatrix *yRotCore = new G4RotationMatrix;  // Rotates X and Z axes only
  yRotCore->rotateY(M_PI*rad);                     // Rotates 180 degree
  new G4PVPlacement(yRotCore,                       //no rotation
                    core_pos2,                    //at position
                    logicCore,             //its logical volume
                    "Core2",                //its name
                    logicEnv,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking

  //////////////////////////////////////////////////////////////////
  // INSERT (for shielding) assume Lead for now
  //////////////////////////////////////////////////////////////////
  G4double insertZ_size = 50.*cm, insertX_offset=0.*cm;;
  std::vector<G4TwoVector> insertXY(6);
  insertXY[0]= G4TwoVector(-13.*cm, 17.*cm);
  insertXY[1]= G4TwoVector(13.*cm,17.*cm);
  insertXY[2]= G4TwoVector(13.*cm,10.*cm);
  insertXY[3]= G4TwoVector(1.*cm,2.*cm);
  insertXY[4]= G4TwoVector(-1.*cm,2.*cm);
  insertXY[5]= G4TwoVector(-13.*cm,10.*cm);
  
  G4ExtrudedSolid *CoilInsertFinal = new G4ExtrudedSolid("CoilInsert", insertXY, insertZ_size, G4TwoVector(0, 0), 1.0, G4TwoVector(0, 0), 1.0);
  G4ThreeVector coilinsert_pos1 = G4ThreeVector(insertX_offset, 0, 0);
  G4ThreeVector coilinsert_pos2 = G4ThreeVector(-insertX_offset, 0, 0);
  // finished core material
  G4LogicalVolume* logicCoilInsert =                         
    new G4LogicalVolume(CoilInsertFinal,         //its solid
                        coilinsert_material,          //its material
                        "CoreInsert");           //its name
  logicCoilInsert->SetUserLimits(fStepLimit);
  //  logicCoilInsert->SetVisAttributes(new G4VisAttributes(blue));
  // Place Coil Insert
  new G4PVPlacement(0,                       //no rotation
                    coilinsert_pos1,                    //at position
                    logicCoilInsert,             //its logical volume
                    "CoilInsert1",                //its name
                    logicEnv,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking
  
  G4RotationMatrix *zRotCoilInsert = new G4RotationMatrix;  // Rotates X and Z axes only
  zRotCoilInsert->rotateZ(M_PI*rad);                     // Rotates 180 degree
  new G4PVPlacement(zRotCoilInsert,                       //no rotation
                    coilinsert_pos2,                    //at position
                    logicCoilInsert,             //its logical volume
                    "CoilInsert2",                //its name
                    logicEnv,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking
  //////////////////////////////////////////////////////////////////////////////////////
  // Concrete shielding
  //////////////////////////////////////////////////////////////////////////////////////
  //  box1
  G4double conc1x_size=7.5*cm, conc1y_size=17.*cm, conc1z_size=50.*cm;
  G4double conc1_offset=20.*cm;
  G4Box *ConcreteBox1=new G4Box("concreteBox1", conc1x_size, conc1y_size, conc1z_size);
  G4ThreeVector conc1_pos1 = G4ThreeVector(conc1_offset+conc1x_size, 0, 0);
  G4ThreeVector conc1_pos2 = G4ThreeVector(-conc1_offset-conc1x_size, 0, 0);
  // finished core material
  G4LogicalVolume* logicConcreteBox1 =                         
    new G4LogicalVolume(ConcreteBox1,         //its solid
                        concrete_shield,          //its material
                        "Conc1");           //its name
  logicConcreteBox1->SetVisAttributes(new G4VisAttributes(yellow));
  logicConcreteBox1->SetUserLimits(fStepLimit);
  // Place concrete box
  new G4PVPlacement(0,                       //no rotation
                    conc1_pos1,                    //at position
                    logicConcreteBox1,             //its logical volume
                    "ConcreteBox11",                //its name
                    logicEnv,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
		    checkOverlaps);          //overlaps checkin
   new G4PVPlacement(0,                       //no rotation
                    conc1_pos2,                    //at position
                    logicConcreteBox1,             //its logical volume
                    "ConcreteBox12",                //its name
                    logicEnv,                //its mother  volume
                    false,                   //no boolean operation
                    1,                       //copy number
                    checkOverlaps);          //overlaps checking
  //////////////////////////////////////////////////////////////////////////////////////
  // Concrete shielding
  //////////////////////////////////////////////////////////////////////////////////////
  //  box2
  G4double conc2x_size=35*cm, conc2y_size=6.5*cm, conc2z_size=50.*cm;
  G4double conc2_offset=17.*cm;
  G4Box *ConcreteBox2=new G4Box("concreteBox2", conc2x_size, conc2y_size, conc2z_size);
  G4ThreeVector conc2_pos1 = G4ThreeVector(0,conc2_offset+conc2y_size, 0);
  G4ThreeVector conc2_pos2 = G4ThreeVector(0,-conc2_offset-conc2y_size, 0);
  // finished core material
  G4LogicalVolume* logicConcreteBox2 =                         
    new G4LogicalVolume(ConcreteBox2,         //its solid
                        concrete_shield,          //its material
                        "Conc2");           //its name
  logicConcreteBox2->SetVisAttributes(new G4VisAttributes(yellow));
  logicConcreteBox2->SetUserLimits(fStepLimit);
  // Place concrete box
  new G4PVPlacement(0,                       //no rotation
                    conc2_pos1,                    //at position
                    logicConcreteBox2,             //its logical volume
                    "ConcreteBox21",                //its name
                    logicEnv,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
		    checkOverlaps);          //overlaps checkin
   new G4PVPlacement(0,                       //no rotation
                    conc2_pos2,                    //at position
                    logicConcreteBox2,             //its logical volume
                    "ConcreteBox22",                //its name
                    logicEnv,                //its mother  volume
                    false,                   //no boolean operation
                    1,                       //copy number
                    checkOverlaps);          //overlaps checking

  //////////////////////////////////////////////
  // Define radiator
  // Assume 10% radiator made out of W
  // ~ 0.03534 cm
  //////////////////////////////////////////////
  //  box
  G4double radiatorx_size=2.5*cm, radiatory_size=2.5*cm, radiatorz_size=0.01767*cm;
  G4double radiator_offset=52.*cm;
  G4Box *Radiator=new G4Box("Radiator", radiatorx_size, radiatory_size, radiatorz_size);
  G4ThreeVector radiator_pos = G4ThreeVector(0, 0,-radiator_offset);
  // finished radiator material
  G4LogicalVolume* logicRadiator =                         
    new G4LogicalVolume(Radiator,         //its solid
                        radiator_material,          //its material
                        "Rad");           //its name
  logicRadiator->SetVisAttributes(new G4VisAttributes(orange));
  // Place Radiator
  new G4PVPlacement(0,                       //no rotation
                    radiator_pos,                    //at position
                    logicRadiator,             //its logical volume
                    "Radiator",                //its name
                    logicEnv,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
		    checkOverlaps);          //overlaps checking
   ///////////////////////////////////////////////////////
   // BeamLine
   //////////////////////////////////////////////////////
   // Assume a tube with outer radius 1 cm and inner radius 2 mm
   G4double r1beam=2.*mm, r2beam=1.*cm;
   G4Tubs *BeamLine=new G4Tubs("BeamLine", r1beam, r2beam, 1.2*conc1z_size, 0.*deg, 360.*deg);
   G4LogicalVolume* logicBeamLine =                         
     new G4LogicalVolume(BeamLine,         //its solid
			 beamline_material,          //its material
			 "BeamTube");           //its name
   logicBeamLine->SetVisAttributes(new G4VisAttributes(green));
   // Place Beam tube
   new G4PVPlacement(0,                       //no rotation
		     G4ThreeVector(0.,0.,1.2*conc1z_size-radiator_offset+1.*mm),                    //at position
		     logicBeamLine,             //its logical volume
		     "BeamLine",                //its name
		     logicEnv,                //its mother  volume
		     false,                   //no boolean operation
		     0,                       //copy number
		     checkOverlaps);          //overlaps checking
   
   G4Tubs *Beam=new G4Tubs("Beam",0., r1beam, 1.199*conc1z_size, 0.*deg, 360.*deg);
   G4LogicalVolume* logicBeam =                         
     new G4LogicalVolume(Beam,         //its solid
			 beam_material,          //its material
			 "Beam");           //its name
   // Place Beam tube
   new G4PVPlacement(0,                       //no rotation
		     G4ThreeVector(0.,0.,1.2*conc1z_size-radiator_offset+1.*mm),                    //at position
		     logicBeam,             //its logical volume
		     "Beam",                //its name
		     logicEnv,                //its mother  volume
		     false,                   //no boolean operation
		     0,                       //copy number
		     checkOverlaps);          //overlaps checking

  ///////////////////////////////////////////////
  // We should be done defining geometry here!
  ///////////////////////////////////////////////
  
  // Change this once we figure out what our scoring area is
  fScoringVolume = logicCoil;
  
}
*/
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void NPSDetectorConstruction::ConstructField() 
{
  static G4TransportationManager* trMgr= 
    G4TransportationManager::GetTransportationManager(); 

  // A field object is held by a field manager
  // Find the global Field Manager
  G4FieldManager* globalFieldMgr= trMgr->GetFieldManager();

  static G4bool fieldIsInitialized = false;
  if(!fieldIsInitialized)    {

    fField = new SimpleField();

    //The ChordFinder is an helper class to track particles 
    //in magnetic fields, it sets the accuracy to be used.

    fEquation = new G4Mag_UsualEqRhs (fField);
    fStepper = new G4ClassicalRK4 (fEquation);
    fChordFinder = new G4ChordFinder(fField,1e-4*m,fStepper);
    globalFieldMgr->SetChordFinder(fChordFinder);
    globalFieldMgr->SetDetectorField(fField);
    globalFieldMgr->GetChordFinder()->SetDeltaChord(1e-4*m);
    globalFieldMgr->SetDeltaIntersection(1e-4*m);
    globalFieldMgr->SetDeltaOneStep(1e-4*m);
     
    G4cout << "Magnetic field has been constructed " << 
      "in NPSDetectorConstruction::ConstructField()" << G4endl;
    fieldIsInitialized = true; 
  }
   
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.....

void NPSDetectorConstruction::ConstructSDandField()
{
  // Sensitive detectors

  G4String NPSSDname = "BeamPipeSD";
  NPSTrackerSD* npsSD = new NPSTrackerSD(NPSSDname, "BeamPipeHitsCollection");
  // Register the field messenger for deleting
  //  G4AutoDelete::Register(amagSD);
  
  // Setting SD to all logical volumes with the same name 
  // of "BeamPipe_LV".
  //  SetSensitiveDetector("BeamPipeVol", npsSD, true);
  SetSensitiveDetector("BeamPipeEnv", npsSD, true);

  // Create global magnetic field messenger.
  // Uniform magnetic field is then created automatically if
  // the field value is not zero.
  //  G4ThreeVector fieldValue = G4ThreeVector();
  //fMagFieldMessenger = new G4GlobalMagFieldMessenger(fieldValue);
  //fMagFieldMessenger->SetVerboseLevel(1);
  
  // Register the field messenger for deleting
  //G4AutoDelete::Register(fMagFieldMessenger);
}
