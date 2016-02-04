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

#ifndef NPSHistoManager_h
#define NPSHistoManager_h 1

#include "globals.hh"
#include "G4ThreeVector.hh"

class TFile;
class TTree;
class TH1D;

const G4int MaxHisto = 5;

class NPSHistoManager {

public:
  
  NPSHistoManager();
  NPSHistoManager(char*);
  ~NPSHistoManager();
   
  void book();
  void save();

  void FillHisto(G4int id, G4double bin, G4double weight = 1.0);
  void Normalize(G4int id, G4double fac);    

  void FillNtuple(G4int col, G4int row, G4int pid, G4double edep,
		  G4ThreeVector pos);

  void PrintStatistic();
        
private:

  char*    fRootFileName;
  TFile*   fRootFile;
  TH1D*    fHisto[MaxHisto];            
  TTree*   fNtuple;

  //  G4int fEvent, fNtrack, fTrackID, fID, fVol;
  //  G4double fX, fY, fZ;
  //  G4double fPx, fPy, fPz;
  //  G4double fDist, fKE;
  G4int         fCol;
  G4int         fRow;
  G4int         fPID;
  G4double      fEdep;
  G4double      fX, fY, fZ;

};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
