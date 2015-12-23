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
/// \file persistency/gdml/G01/load_gdml.cc
/// \brief Main program of the persistency/gdml/G01 example
//
//
// $Id: load_gdml.cc 82284 2014-06-13 14:50:49Z gcosmo $
//
//
// --------------------------------------------------------------
//      GEANT 4 - load_gdml
//
// --------------------------------------------------------------

#include <vector>

#include "G4RunManager.hh"
#include "G4UImanager.hh"

#include "G4LogicalVolumeStore.hh"
#include "G4TransportationManager.hh"

#include "G01PrimaryGeneratorAction.hh"
#include "G01DetectorConstruction.hh"
#include "FTFP_BERT.hh"

#ifdef G4VIS_USE
#include "G4VisExecutive.hh"
#endif

#ifdef G4UI_USE
#include "G4UIExecutive.hh"
#endif

#include "G4GDMLParser.hh"

int main(int argc,char **argv)
{
   G4cout << G4endl;
   G4cout << "Usage: load_gdml <intput_gdml_file:mandatory>"
          << " <output_gdml_file:optional>" << G4endl;
   G4cout << G4endl;

   if (argc<2)
   {
      G4cout << "Error! Mandatory input file is not specified!" << G4endl;
      G4cout << G4endl;
      return -1;
   }

   G4GDMLParser parser;

// Uncomment the following if wish to avoid names stripping
// parser.SetStripFlag(false);

   parser.Read(argv[1]);
   
   if (argc>4)
   {
      G4cout << "Error! Too many arguments!" << G4endl;
      G4cout << G4endl;
      return -1;
   }

   G4RunManager* runManager = new G4RunManager;

   runManager->SetUserInitialization(new G01DetectorConstruction(
                                     parser.GetWorldVolume()));
   runManager->SetUserInitialization(new FTFP_BERT);
   runManager->SetUserAction(new G01PrimaryGeneratorAction);

   runManager->Initialize();

   if (argc>=3)
   {
      parser.Write(argv[2], G4TransportationManager::GetTransportationManager()
      ->GetNavigatorForTracking()->GetWorldVolume()->GetLogicalVolume());
   }

   G4UImanager* UImanager = G4UImanager::GetUIpointer();
 
   ///////////////////////////////////////////////////////////////////////
   //
   // Example how to retrieve Auxiliary Information
   //
   const G4LogicalVolumeStore* lvs = G4LogicalVolumeStore::GetInstance();
   std::vector<G4LogicalVolume*>::const_iterator lvciter;
   for( lvciter = lvs->begin(); lvciter != lvs->end(); lvciter++ ) {

     G4GDMLAuxListType auxInfo = parser.GetVolumeAuxiliaryInformation(*lvciter);
     std::vector<G4GDMLAuxPairType>::const_iterator ipair = auxInfo.begin();
     for( ipair = auxInfo.begin(); ipair != auxInfo.end(); ipair++ ) {

       G4String str=ipair->type;
       G4String val=ipair->value;
       G4cout << " Auxiliary Information is found for Logical Volume :  "
              << (*lvciter)->GetName() << G4endl;
       G4cout << " Name of Auxiliary type is     :  " << str << G4endl;
       G4cout << " Associated Auxiliary value is :  " << val << G4endl;

       G4VisAttributes *ttt = 
	 new G4VisAttributes((*lvciter)->GetVisAttributes());

       if (str.compare("Color")==0) {

	 G4Color red(1.0,0.0,0.0), yellow(1.0,1.0,0.0), blue(0.,0.,0.7),
	   copper(0.5,0.5,0.0), green(0,1.,0.), orange(1.0,0.5,0.0);

	 // can't use switch on strings so we need this ugly thing!
	 if (val.contains("trans")) {
	   ttt->SetVisibility(false);
	   (*lvciter)->SetVisAttributes(ttt);
	 }
	 if (val.contains("red")) {
	   (*lvciter)->SetVisAttributes(new G4VisAttributes(red));
	 }
	 if (val.contains("yellow")) {
	   (*lvciter)->SetVisAttributes(new G4VisAttributes(yellow));
	 }
	 if (val.contains("green")) {
	   (*lvciter)->SetVisAttributes(new G4VisAttributes(green));
	 }
	 if (val.contains("blue")) {
	   (*lvciter)->SetVisAttributes(new G4VisAttributes(blue));
	 }
	 if (val.contains("copper")) {
	   (*lvciter)->SetVisAttributes(new G4VisAttributes(copper));
	 }
	 if (val.contains("orange")) {
	   (*lvciter)->SetVisAttributes(new G4VisAttributes(orange));
	 }
	 if (val.contains("cyan")) {
	   (*lvciter)->SetVisAttributes(new G4VisAttributes(G4Colour::Cyan));
	 }
	 if (val.contains("wire")) {
	   ttt->SetVisibility(true);
	   ttt->SetForceWireframe(true);
	   (*lvciter)->SetVisAttributes(ttt);
	 }

       }  //color

     }    //for ipair

   }      //for lvciter

   //
   // End of Auxiliary Information block
   //
   ////////////////////////////////////////////////////////////////////////

   if (argc==4)   // batch mode  
   {
     G4String command = "/control/execute ";
     G4String fileName = argv[3];
     UImanager->ApplyCommand(command+fileName);
   }
   else           // interactive mode
   {
#ifdef G4UI_USE
     G4UIExecutive* ui = new G4UIExecutive(argc, argv);
#ifdef G4VIS_USE
     G4VisManager* visManager = new G4VisExecutive;
     visManager->Initialize();
     UImanager->ApplyCommand("/control/execute vis.mac");
#endif

     if (ui->IsGUI()) {
       ///         UImanager->ApplyCommand("/control/execute gui.mac");
     }     

     ui->SessionStart();
#ifdef G4VIS_USE
     delete visManager;
#endif
     delete ui;
#endif
   }

   delete runManager;

   return 0;
}
