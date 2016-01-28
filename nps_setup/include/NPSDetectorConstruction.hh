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

#ifndef NPSDetectorConstruction_h
#define NPSDetectorConstruction_h 1

#include "globals.hh"
#include "SimpleField.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4ThreeVector.hh"
#include "G4VisAttributes.hh"
#include "G4LogicalVolumeStore.hh"

// attempt to use the GDML parser
#include <vector>
#include "G4GDMLParser.hh"

class G4LogicalVolumeStore;
class G4LogicalVolume;
class G4VPhysicalVolume;
class G4Material;
class G4Mag_UsualEqRhs;
class G4MagIntegratorStepper;
class G4ChordFinder;
class G4UniformMagField;
class G4UserLimits;

/// Detector construction class to define materials and geometry.

class NPSDetectorConstruction : public G4VUserDetectorConstruction
{
public:
  NPSDetectorConstruction();
  NPSDetectorConstruction(G4VPhysicalVolume *aworld,
			  G4LogicalVolume *scoring,
			  G4LogicalVolume *meas)
  {
    G4cout << "We are using GDML..."<<G4endl;
    physWorld =  aworld;
    fScoringVolume = scoring;
    fMeas = meas;
  };
  
  virtual ~NPSDetectorConstruction();
  virtual G4VPhysicalVolume* Construct();
  virtual void ConstructSDandField();
  G4LogicalVolume* GetScoringVolume() const { return fScoringVolume; }

  
protected:
    G4LogicalVolume*  fScoringVolume;

private:
  //! define needed materials
  void DefineMaterials();
  void DefineBasicGeometry();
  void ConstructMagnet();
  //! initialize geometry parameters
  ///void ComputeParameters();
  //! Construct geometry of the Beam Telescope
  ///G4VPhysicalVolume* ConstructTelescope();
  //! Construct geometry of the Electromagnetic Calorimeter
  ///G4VPhysicalVolume* ConstructEMCalo();
  //! Construct geometry of the hadronic Calorimeter
  ///G4VPhysicalVolume* ConstructHadCalo();
  //! Construct the magnetic field of the setup
  void ConstructField();
  //  const G4VPhysicalVolume* GetEnvelope() const          {return physiWorld;};           
  
  private:
  SimpleField *fField;
  ////G4UniformMagField *fField;
  G4Mag_UsualEqRhs *fEquation;
  G4double minStepMagneticField;
  G4MagIntegratorStepper* fStepper;
  G4ChordFinder*          fChordFinder;

  // Materials
  //  G4Material* world_material;
  //  G4Material* env_material;
  //  G4Material* coil_material;
  //  G4Material* coilinsert_material;
  //  G4Material* core_material;
  //  G4Material* concrete_shield;
  //  G4Material* beamline_material;
  //  G4Material* beam_material;
  //  G4Material* radiator_material;
  
  // Volumes & their sizes
  G4double env_size[3];
  G4double world_size[3];
  G4LogicalVolume * logicWorld;
  G4VPhysicalVolume* physWorld;
  G4LogicalVolume* logicEnv;
  ////  G4VPhysicalVolume* aMagnet;
  ////  G4double halfWorldLength;
  G4LogicalVolume *fMeas;
  G4UserLimits* fStepLimit;            // pointer to user step limits
 };

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
