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

#include "NPSCalorimeterSD.hh"
#include "G4HCofThisEvent.hh"
#include "G4Step.hh"
#include "G4ThreeVector.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

NPSCalorimeterSD::NPSCalorimeterSD(const G4String& name,
				   const G4String& hitsCollectionName) 
 : G4VSensitiveDetector(name),
   fHitsCollection(0), lastID(-1)
{
  collectionName.insert(hitsCollectionName);

  //  G4cout << "NPSCalorimeterSD::NPSCalorimeterSD: constructed" << G4endl;
  //  getchar();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

NPSCalorimeterSD::~NPSCalorimeterSD() 
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void NPSCalorimeterSD::Initialize(G4HCofThisEvent* hce)
{
  // Create hits collection

  fHitsCollection 
  = new NPSCalorimeterHitsCollection(SensitiveDetectorName, collectionName[0]); 

  // Add this collection in hce

  G4int hcID 
    = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);
  hce->AddHitsCollection( hcID, fHitsCollection ); 

  //  G4cout << "NPSCalorimeterSD::Initialize: initialized" << G4endl;
  //  getchar();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4bool NPSCalorimeterSD::ProcessHits(G4Step* step, G4TouchableHistory*)
{
  G4int col = step->GetPreStepPoint()->GetTouchableHandle()->GetCopyNumber();
  G4int row = step->GetPreStepPoint()->GetTouchableHandle()->GetCopyNumber(1);
  G4int charge = step->GetTrack()->GetDynamicParticle()->GetCharge();
  G4double edep = step->GetTotalEnergyDeposit();
  G4ThreeVector pos = step->GetPreStepPoint()->GetPosition();

  NPSCalorimeterHit* hit = new NPSCalorimeterHit(col, row, charge, edep, pos);
  fHitsCollection->insert( hit );
  //  hit->Print();
  //  getchar();

  return true;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void NPSCalorimeterSD::EndOfEvent(G4HCofThisEvent*)
{
  //  if ( verboseLevel>1 ) { 
  //  G4int nofHits = fHitsCollection->entries();
  //   G4cout << G4endl
  //          << "-------->Hits Collection: in this event they are " << nofHits 
  //          << " hits in the tracker chambers: " << G4endl;
  //  for ( G4int i=0; i<nofHits; i++ ) (*fHitsCollection)[i]->delete();
  //}

  //  G4cout << "NPSCalorimeterSD::EndOfEvent: end of event" << G4endl;
  //  getchar();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
