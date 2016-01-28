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

#include "NPSRunAction.hh"
#include "NPSPrimaryGeneratorAction.hh"
#include "NPSDetectorConstruction.hh"
#include "NPSRun.hh"
#include "NPSHistoManager.hh"

#include "G4RunManager.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include <ctime>

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

NPSRunAction::NPSRunAction(NPSHistoManager* histo)
  : G4UserRunAction(), fHistoManager(histo), fAutoSeed(true)
{ 
  // add new units for dose
  // 
  const G4double milligray = 1.e-3*gray;
  const G4double microgray = 1.e-6*gray;
  const G4double nanogray  = 1.e-9*gray;  
  const G4double picogray  = 1.e-12*gray;
   
  new G4UnitDefinition("milligray", "milliGy" , "Dose", milligray);
  new G4UnitDefinition("microgray", "microGy" , "Dose", microgray);
  new G4UnitDefinition("nanogray" , "nanoGy"  , "Dose", nanogray);
  new G4UnitDefinition("picogray" , "picoGy"  , "Dose", picogray);        
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

NPSRunAction::~NPSRunAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4Run* NPSRunAction::GenerateRun()
{
  return new NPSRun; 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void NPSRunAction::BeginOfRunAction(const G4Run*)
{ 
  //initialize cumulative quantities

  //  fSumEAbs = fSum2EAbs =fSumEGap = fSum2EGap = 0.;
  //  fSumLAbs = fSum2LAbs =fSumLGap = fSum2LGap = 0.;
  
  //inform the runManager to save random number seed
  //  G4RunManager::GetRunManager()->SetRandomNumberStore(false);
  //  G4RunManager::GetRunManager()->SetRandomNumberStoreDir("random/");
 
  if (fAutoSeed) {
    // automatic (time-based) random seeds for each run
    G4cout << "*******************" << G4endl;
    G4cout << "*** AUTOSEED ON ***" << G4endl;
    G4cout << "*******************" << G4endl;
    long seeds[2];
    time_t systime = time(NULL);
    seeds[0] = (long) systime;
    seeds[1] = (long) (systime*G4UniformRand());
    G4Random::setTheSeeds(seeds);
    G4Random::showEngineStatus();
  } else {
    G4Random::showEngineStatus();
  }

  /*
  if (fSaveRndm > 0)    {
    std::ostringstream os;
    os<<"beginOfRun_"<<G4Threading::G4GetThreadId()<<".rndm";
    G4Random::saveEngineStatus(os.str().c_str());
  }
  */

  //histograms

  fHistoManager->book(); 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void NPSRunAction::fillPerEvent(G4double EAbs, G4double EGap,
                                  G4double LAbs, G4double LGap)
{
  //accumulate statistic
  //
  //  fSumEAbs += EAbs;  fSum2EAbs += EAbs*EAbs;
  //fSumEGap += EGap;  fSum2EGap += EGap*EGap;
  
  //fSumLAbs += LAbs;  fSum2LAbs += LAbs*LAbs;
  //fSumLGap += LGap;  fSum2LGap += LGap*LGap;  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void NPSRunAction::EndOfRunAction(const G4Run* run)
{
  G4int nofEvents = run->GetNumberOfEvent();
  if (nofEvents == 0) return;

  //compute statistics: mean and rms
  //
  ///fSumEAbs /= NbOfEvents; fSum2EAbs /= NbOfEvents;
  ///G4double rmsEAbs = fSum2EAbs - fSumEAbs*fSumEAbs;
  ///if (rmsEAbs >0.) rmsEAbs = std::sqrt(rmsEAbs); else rmsEAbs = 0.;
  //print
  //
  //  G4cout
  //   << "\n--------------------End of Run------------------------------\n"
  //   << "\n mean Energy in Absorber : " << G4BestUnit(fSumEAbs,"Energy")
  //   << " +- "                          << G4BestUnit(rmsEAbs,"Energy")  
  //   << "\n mean Energy in Gap      : " << G4BestUnit(fSumEGap,"Energy")
  //   << " +- "                          << G4BestUnit(rmsEGap,"Energy")
  //   << G4endl;
  
  const NPSRun* b1Run = static_cast<const NPSRun*>(run);

  // Compute dose

  G4double edep  = b1Run->GetEdep();
  G4double edep2 = b1Run->GetEdep2();
  G4double rms = edep2 - edep*edep/nofEvents;
  if (rms > 0.) rms = std::sqrt(rms); else rms = 0.;

  const NPSDetectorConstruction* detectorConstruction
   = static_cast<const NPSDetectorConstruction*>
     (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
  G4double mass = detectorConstruction->GetScoringVolume()->GetMass();
  G4double dose = edep/mass;
  G4double rmsDose = rms/mass;

  // Run conditions
  //  note: There is no primary generator action object for "master"
  //        run manager for multi-threaded mode.

  const NPSPrimaryGeneratorAction* generatorAction
   = static_cast<const NPSPrimaryGeneratorAction*>
     (G4RunManager::GetRunManager()->GetUserPrimaryGeneratorAction());

  G4String runCondition;

  if (generatorAction)
  {
    const G4ParticleGun* particleGun = generatorAction->GetParticleGun();
    runCondition += particleGun->GetParticleDefinition()->GetParticleName();
    runCondition += " of ";
    G4double particleEnergy = particleGun->GetParticleEnergy();
    runCondition += G4BestUnit(particleEnergy,"Energy");
  }
        
  // Print

  if (IsMaster()) {
    G4cout
     << G4endl
     << "--------------------End of Global Run-----------------------";
  }
  else {
    G4cout
     << G4endl
     << "--------------------End of Local Run------------------------";
  }
  
  G4cout
     << G4endl
     << " The run consists of " << nofEvents << " "<< runCondition
     << G4endl
     << " Dose in scoring volume : " 
     << G4BestUnit(dose,"Dose") << " +- " << G4BestUnit(rmsDose,"Dose")
     << G4endl
     << "------------------------------------------------------------"
     << G4endl
     << G4endl;

  //save histograms
  //
  fHistoManager->PrintStatistic();
  fHistoManager->save();   
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
