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

#ifndef NPSTrackerHit_h
#define NPSTrackerHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "tls.hh"

// Tracker hit class for the beam pipe.
// It defines data members to store the trackID, particle id,
//  Momentum and position - fTrackID, fID, fMom, fPos.

class NPSTrackerHit : public G4VHit {

public:

  NPSTrackerHit();
  NPSTrackerHit(const NPSTrackerHit&);
  virtual ~NPSTrackerHit();
  
  // operators
  const NPSTrackerHit& operator=(const NPSTrackerHit&);
  G4int operator==(const NPSTrackerHit&) const;
  
  inline void* operator new(size_t);
  inline void  operator delete(void*);
  
  // methods from base class
  virtual void Draw();
  virtual void Print();
  
  // Set methods
  void SetTrackID  (G4int track)      { fTrackID = track; };
  void SetID       (G4int id)         { fID = id; };
  void SetMom      (G4ThreeVector mom){ fMom = mom; };
  void SetPos      (G4ThreeVector xyz){ fPos = xyz; };
  
  // Get methods
  G4int GetTrackID() const     { return fTrackID; };
  G4int GetID() const   { return fID; };
  G4ThreeVector GetMom() const { return fMom; };
  G4ThreeVector GetPos() const { return fPos; };
  
private:
  
  G4int         fTrackID;
  G4int         fID;
  G4ThreeVector fMom;
  G4ThreeVector fPos;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

typedef G4THitsCollection<NPSTrackerHit> NPSTrackerHitsCollection;

extern G4ThreadLocal G4Allocator<NPSTrackerHit>* NPSTrackerHitAllocator;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

inline void* NPSTrackerHit::operator new(size_t)
{
  if(!NPSTrackerHitAllocator)
    NPSTrackerHitAllocator = new G4Allocator<NPSTrackerHit>;
  return (void *) NPSTrackerHitAllocator->MallocSingle();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

inline void NPSTrackerHit::operator delete(void *hit)
{
  NPSTrackerHitAllocator->FreeSingle((NPSTrackerHit*) hit);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
