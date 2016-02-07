#define nps_setup_cxx
#include "nps_setup.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>

using namespace std;

//#define NCOL 31
//#define NROW 36
#define NCOL 32
#define NROW 37

void nps_setup::LoopEdepMap()
{
  //  TH2D* he = new TH2D("he","Edeps(MeV)",31,1,31,36,1,36);
  TH2D* he = new TH2D("he","Edeps(MeV)/e",
		      NCOL+1,-0.5,NCOL+0.5,NROW+1,-0.5,NROW+0.5);

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nevents = 0;

   Long64_t nbytes = 0, nb = 0;
   double Etot =0.;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {

     //      Long64_t ientry = LoadTree(jentry);
     //      if (ientry < 0) break;
     //     cout << "jentry = " << jentry << "  edep = " << edep << "  col = "
     //	  << col << "  row = " << row << endl;

     he->Fill(col+1,row+1,edep);

      nb = fChain->GetEntry(jentry);   nbytes += nb;
      Etot += edep;
      nevents = evid;
      //      getchar();
   }

   cout << "  nentries = " << nentries << endl;
   cout << "  nb       = " << nb << endl;
   cout << "  Etot     = " << Etot << " MeV" << endl;
   cout << "  nevents  = " << ++nevents << endl;

   TH2D* hd = (TH2D*) he->Clone("hd");
   hd->SetTitle("Doses(kGy/(uA*h))");

   const double mass = 0.6278535;   // PbWO block mass, kg.
   const double J = 6.24e+12;       // MeV/joule
   const double C = 6.24e+18;       // e/Coulumb

   //Conversion factor from energy(MeV) to Gy/(uA*h).
   const double fac = 1./nevents * 1./mass * 1./J * C *1.e-6 * 3600 * 1.e-3;

   cout << "  Edep/block = " << Etot/(NCOL*NROW)*fac*mass << " kJ/(uA*h)"<<endl;
   cout << "  Dose       = " << Etot/(NCOL*NROW)*fac << " kGy/(uA*h)" << endl;

   he->Scale(1./nevents);
   hd->Scale(fac);

   // Plot.

   gStyle->SetOptStat(0);

   TCanvas *c1 = new TCanvas("c1", "NPS Calorimeter", 1050, 600);
   c1->Divide(2,1);

   c1->cd(1);
   he->Draw("colz");

   c1->cd(2);
   hd->Draw("colz");

}

//==============================================================================

void nps_setup::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L nps_setup.C
//      Root > nps_setup t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
   }

   cout << "  nentries = " << nentries << endl;
   cout << "  nb       = " << nb << endl;
}

//==============================================================================
