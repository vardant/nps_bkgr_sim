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
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include <TH1D.h>
#include <TFile.h>
#include <TTree.h>
#include <CLHEP/Units/SystemOfUnits.h>

#include "NPSHistoManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

NPSHistoManager::NPSHistoManager()
  :fRootFile(0), fNtuple(0),
   //   fEvent(-1), fTrackID(-1), fID(-1), fX(0), fY(0), fZ(0),
   //   fPx(0), fPy(0), fPz(0), fDist(0), fKE(0), fVol(-1)
   fCol(-1), fRow(-1), fCharge(-999), fEdep(-1.), fX(0), fY(0), fZ(0)
{
  fRootFileName="nps_setup.root";
  // histogram(s)
  for (G4int k=0; k<MaxHisto; k++) fHisto[k] = 0;
    
  // ntuple
  fNtuple = 0;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

NPSHistoManager::NPSHistoManager(char *aname)
:fRootFile(0), fNtuple(0),
 // fEvent(-1), fTrackID(-1), fID(-1), fX(0), fY(0), fZ(0),
 // fPx(0), fPy(0), fPz(0), fDist(0), fKE(0), fVol(-1)
 fCol(-1), fRow(-1), fCharge(-999), fEdep(-1.), fX(0), fY(0), fZ(0)
{
  fRootFileName=aname;  
  // histogram(s)
  for (G4int k=0; k<MaxHisto; k++) fHisto[k] = 0;
    
  // ntuple
  fNtuple = 0;

  // rad budget ntuple
  // fNtuple2 = 0;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

NPSHistoManager::~NPSHistoManager()
{
  if ( fRootFile ) delete fRootFile;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void NPSHistoManager::book()
{ 
 // Creating a tree container to handle histograms and ntuples.
 // This tree is associated to an output file.
 //
 fRootFile = new TFile(fRootFileName,"RECREATE");
 if(!fRootFile) {
   G4cout << " ***** HistoManager::book :" 
          << " problem creating the ROOT TFile *****"
          << G4endl;
   return;
 }
   
 // fHisto[1] = new TH1D("h1", "Total Edep(GeV)", 100, 0., 5*CLHEP::GeV);
 fHisto[1] = new TH1D("h1", "Total Edep(MeV)", 100, 0., 5000.);
 if (!fHisto[1]) G4cout << "\n can't create histo 1" << G4endl;

 // create an ntuple in subdirectory "tuples"
 //
 fNtuple = new TTree("rem", "rem");
 /*
 fNtuple->Branch("event", &fEvent, "event/I");
 fNtuple->Branch("track", &fTrackID, "track/I");
 fNtuple->Branch("ID", &fID, "ID/I");
 fNtuple->Branch("x", &fX, "x/D");
 fNtuple->Branch("y", &fY, "y/D");
 fNtuple->Branch("z", &fZ, "z/D");
 fNtuple->Branch("px", &fPx, "px/D");
 fNtuple->Branch("py", &fPy, "py/D");
 fNtuple->Branch("pz", &fPz, "pz/D");
 fNtuple->Branch("vol", &fVol, "vol/I");
 fNtuple->Branch("dist", &fDist, "dist/D");
 fNtuple->Branch("KE", &fKE, "KE/D");
 */
 /* 
 fNtuple2 = new TTree("rem", "rem");
 fNtuple2->Branch("event", &fEvent, "event/I");
 fNtuple2->Branch("vol", &fNtrack, "vol/I"); ???
 fNtuple2->Branch("ID", &fID, "ID/I");
 fNtuple2->Branch("dist", &fDist, "dist/D");
 fNtuple2->Branch("KE", &fKE, "KE/D");
 */
 fNtuple->Branch("col", &fCol, "col/I");
 fNtuple->Branch("row", &fRow, "row/I");
 fNtuple->Branch("charge", &fCharge, "charge/I");
 fNtuple->Branch("edep", &fEdep, "Edep/D");
 fNtuple->Branch("x", &fX, "x/D");
 fNtuple->Branch("y", &fY, "y/D");
 fNtuple->Branch("z", &fZ, "z/D");
 G4cout << "\n----> Root file is opened in " << fRootFileName << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void NPSHistoManager::save()
{ 
  if (fRootFile) {
    fRootFile->Write();       // Writing the histograms to the file
    fRootFile->Close();        // and closing the tree (and the file)
    G4cout << "\n----> Histogram Tree is saved \n" << G4endl;
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void NPSHistoManager::FillHisto(G4int ih, G4double xbin, G4double weight)
{
  if (ih >= MaxHisto) {
    G4cout << "---> warning from HistoManager::FillHisto() : histo " << ih
           << " does not exist. (xbin=" << xbin << " weight=" << weight << ")"
           << G4endl;
    return;
  }
 if  (fHisto[ih]) { fHisto[ih]->Fill(xbin, weight); }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void NPSHistoManager::Normalize(G4int ih, G4double fac)
{
  if (ih >= MaxHisto) {
    G4cout << "---> warning from HistoManager::Normalize() : histo " << ih
           << " does not exist. (fac=" << fac << ")" << G4endl;
    return;
  }
  if (fHisto[ih]) fHisto[ih]->Scale(fac);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

//void NPSHistoManager::FillNtuple(G4int anEvent, G4int nTrack, G4int aTrackID,
//G4int aID,  G4ThreeVector pos,
//G4ThreeVector mom, G4int aVol, G4double aDist,
//G4double aKE)

void NPSHistoManager::FillNtuple(G4int col, G4int row, G4int charge,
				 G4double edep,  G4ThreeVector pos)
{

  //  fEvent=anEvent;
  //  fNtrack=nTrack;
  //  fTrackID=aTrackID;
  //  fID=aID;
  //  //  fX=pos.getX()/mm;
  //  //fY=pos.getY()/mm;
  //  //fZ=pos.getZ()/mm;
  //  //fPx=mom.getX()/MeV;
  //  //fPy=mom.getY()/MeV;
  //  //fPz=mom.getZ()/MeV;
  //  fX=pos.getX();
  //  fY=pos.getY();
  //  fZ=pos.getZ();
  //  fPx=mom.getX();
  //  fPy=mom.getY();
  //  fPz=mom.getZ();
  //  fVol=aVol;
  //  fDist=aDist;
  //  fKE=aKE;
  fCol = col;
  fRow = row;
  fCharge = charge;
  fEdep = edep;
  fX=pos.getX();
  fY=pos.getY();
  fZ=pos.getZ();

  if (fNtuple) {
    //    G4cout <<"filling ntuple right now!\n";
    fNtuple->Fill();
  }

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void NPSHistoManager::PrintStatistic()
{
  if(fHisto[1]) {
    G4cout << "\n ----> print histograms statistic \n" << G4endl;
    
    /*
    G4cout 
    << " EAbs : mean = " << G4BestUnit(fHisto[1]->GetMean(), "Energy") 
    << " rms = " << G4BestUnit(fHisto[1]->GetRMS(),  "Energy") << G4endl;
    */
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
