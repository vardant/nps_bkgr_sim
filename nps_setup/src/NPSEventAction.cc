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

#include "NPSEventAction.hh"
#include "NPSRun.hh"
#include "NPSRunAction.hh"
#include "NPSHistoManager.hh"
#include "NPSCalorimeterHit.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4HCofThisEvent.hh"
#include "G4VHitsCollection.hh"
#include "G4TrajectoryContainer.hh"
#include "G4SDManager.hh"
#include "G4Trajectory.hh"
#include "G4ios.hh"
#include "G4PrimaryVertex.hh"
#include "G4PrimaryParticle.hh"
#include "G4SystemOfUnits.hh"    

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

NPSEventAction::NPSEventAction(NPSHistoManager *histo)
  : G4UserEventAction(), fHistoManager(histo), fPrintModulo(0),
    fEdep(0.), fCalorimeterCollID(-1), fEvtNo(-1)
{
  //  fPrintModulo = 100000;
  fPrintModulo = 1;
} 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

NPSEventAction::~NPSEventAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void NPSEventAction::BeginOfEventAction(const G4Event* evt)
{
  fEvtNo = evt->GetEventID();
  if (fEvtNo%fPrintModulo == 0)     G4cout << "event: " << fEvtNo << G4endl;

  G4SDManager * SDman = G4SDManager::GetSDMpointer();

  if(fCalorimeterCollID<0)
  {
    //    G4String colNam;
    //    fCalorimeterCollID = 
    //      SDman->GetCollectionID(colNam="CalorimeterHitsCollection");
    fCalorimeterCollID = SDman->GetCollectionID("CalorimeterHitsCollection");
  }

  // initialization of per event quantities
  fEdep = 0.;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void NPSEventAction::EndOfEventAction(const G4Event* event)
{   
  // Accumulate statistics in NPSRun.
  NPSRun* run = static_cast<NPSRun*>(
		       G4RunManager::GetRunManager()->GetNonConstCurrentRun() );
  run->AddEdep(fEdep);

  // Fill histogram with event's energy deposition.
  fHistoManager->FillHisto(1, fEdep/MeV);

  // get number of stored trajectories

  G4TrajectoryContainer* trajectoryContainer = event->GetTrajectoryContainer();
  G4int n_trajectories = 0;
  if (trajectoryContainer) n_trajectories = trajectoryContainer->entries();

  //  G4cout << "NPSEventAction::EndOfEventAction: n_trajectories = " 
  //	 << n_trajectories << G4endl;
  //  getchar();

  // periodic printing
  //G4int eventID = event->GetEventID();

  // Hit collection for this event.

  G4HCofThisEvent * HCE = event->GetHCofThisEvent();
  NPSCalorimeterHitsCollection* CC = 0;
  if(HCE) {
    CC = (NPSCalorimeterHitsCollection*)(HCE->GetHC(fCalorimeterCollID));
    //    G4cout << "  Found hit collection." << G4endl;
  }

  if(CC) {
    int n_hit = CC->entries();
    //    G4cout << "  n_hit = " << n_hit << G4endl;

    for(int i=0;i<n_hit;i++) {
      G4int col =(*CC)[i]->GetCol();
      G4int row =(*CC)[i]->GetRow();
      G4int pid =(*CC)[i]->GetPID();
      G4double edep=(*CC)[i]->GetEdep();
      G4ThreeVector pos=(*CC)[i]->GetPos();
      fHistoManager->FillNtuple(col, row, pid, edep/MeV, pos);
    }

    //    getchar();
  }


  //---------------------------------------------------------------------------

  // Add the primary vertex for safe keeping
  //
  // temporarily remove to get more neutron hits for the event generator
  //
  /*
  G4int eventID = event->GetEventID();
  fHistoManager->FillNtuple(eventID,
    0,
    event->GetPrimaryVertex()->GetPrimary(0)->GetTrackID(),
    event->GetPrimaryVertex()->GetPrimary(0)->GetPDGcode(),
    event->GetPrimaryVertex()->GetPosition(),
    event->GetPrimaryVertex()->GetPrimary(0)->GetMomentum(),-1, -1.,-1.);
  */

  //
  // get number of stored trajectories
  //
  /*
  G4TrajectoryContainer* trajectoryContainer = event->GetTrajectoryContainer();
  G4int n_trajectories = 0;
  if (trajectoryContainer) n_trajectories = trajectoryContainer->entries();
  // periodic printing
  G4int eventID = event->GetEventID();
  //
  G4HCofThisEvent * HCE = event->GetHCofThisEvent();
  AmagnetTrackerHitsCollection* BPC = 0;
  if(HCE)
    {
      BPC = (AmagnetTrackerHitsCollection*)(HCE->GetHC(fBeamPipeCollID));
    }
  
  if(BPC)
    {
      int n_hit = BPC->entries();
      if (n_hit==0) {
	AmagnetTrackerHit* newHit= new AmagnetTrackerHit();
	// Add the primary vertex if the event has otherwise zero hits!
	//G4cout<<"primary = "<<event->GetPrimaryVertex()->GetPrimary(0)->GetPDGcode()<<G4endl;
	///	  G4cout << "Adding primary vertex to the output!\n";
	newHit->SetTrackID  (event->GetPrimaryVertex()->GetPrimary(0)->GetTrackID());
	newHit->SetID (event->GetPrimaryVertex()->GetPrimary(0)->GetPDGcode());
	newHit->SetMom (event->GetPrimaryVertex()->GetPrimary(0)->GetMomentum());
	newHit->SetPos (event->GetPrimaryVertex()->GetPosition());
	BPC->insert(newHit);
      }
      n_hit = BPC->entries();
      //
      // Keep the human interested
      //
        if ( eventID % fPrintModulo == 0) {
	  G4cout << ">>> Event: " << eventID  << " Beam Pipe hits: " << n_hit<<" <<<"<<G4endl;
	  ///   G4cout << "    " << n_trajectories
	  ///         << " trajectories stored in this event." << G4endl;
	  // hit collection
	  ///G4VHitsCollection* hc = event->GetHCofThisEvent()->GetHC(0);
	  ///G4cout << hc->GetSize() << " hit(s) stored in this event" << G4endl;
	}
      ///      G4cout << G4endl;
      ////G4cout << "Beam Pipe Tracker hits " <<
      ///	"--------------------------------------------------------------" 
      ///	     << G4endl;
      ///G4cout << n_hit << " hit(s) are stored in BeamPipeTrackerHitsCollection." 
      ///	     << G4endl;
      // GN Fill ntuple
      for(int i=0;i<n_hit;i++) {
	crtID =(*BPC)[i]->GetID();
	crtTrackID =(*BPC)[i]->GetTrackID();
	crtPos=(*BPC)[i]->GetPos();
	crtMom=(*BPC)[i]->GetMom();
	fHistoManager->FillNtuple(eventID, n_hit, crtTrackID, crtID, crtPos, crtMom);
	///	    G4cout <<"id = "<<(*BPC)[i]->GetID() << " mom = "<<(*BPC)[i]->GetMom().getX()<<G4endl;
      }
    }
  */
  
   //
  // thx (based on code from Tst33VisEventAction.cc, ahoward
  ///    for (G4int i=0; i<n_trajectories; i++)  { 
  ///  G4Trajectory* trj = 0;
  ///  trj = dynamic_cast<G4Trajectory*>((*trajectoryContainer)[i]);
  ///  if (trj) {
  ///	G4cout << "ID = "<<trj->GetPDGEncoding()<<G4endl;
  ///	G4bool charged=false;
  ///	charged = std::fabs(trj->GetCharge()) > 0;
  ///	if (drawFlag == "all") {
  ///	  DrawTrajectory(*trj);
  ///	}
  ///	else if ((drawFlag == "charged")&&(charged)) {
  ///	  DrawTrajectory(*trj);
  ///	}
  ///	else if ((drawFlag == "neutral")&&(!charged)) {
  ///	  DrawTrajectory(*trj);
  ///	}
  ///      }
  ///  else {
  ///	G4cerr << " Amagnet::EndOfEventAction: failed to dynamic cast to G4Trajectory!" << G4endl;
  ///  }
  ///  }
  /// G4VHitsCollection* hc = event->GetHCofThisEvent()->GetHC(0);
  ///G4cout << "    "
  ///       << hc->GetSize() << " hits stored in this event" << G4endl;
  /// }
  //fill histograms
  //
  /// fHistoManager->FillHisto(1, fEnergyAbs);
  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
