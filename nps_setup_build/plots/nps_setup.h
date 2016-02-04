//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Feb  3 14:07:40 2016 by ROOT version 5.34/30
// from TTree rem/rem
// found on file: nps_setup.root
//////////////////////////////////////////////////////////

#ifndef nps_setup_h
#define nps_setup_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class nps_setup {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           col;
   Int_t           row;
   Int_t           pid;
   Double_t        edep;
   Double_t        x;
   Double_t        y;
   Double_t        z;

   // List of branches
   TBranch        *b_col;   //!
   TBranch        *b_row;   //!
   TBranch        *b_pid;   //!
   TBranch        *b_Edep;   //!
   TBranch        *b_x;   //!
   TBranch        *b_y;   //!
   TBranch        *b_z;   //!

   nps_setup(TTree *tree=0);
   virtual ~nps_setup();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual void     LoopEdepMap();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef nps_setup_cxx
nps_setup::nps_setup(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("nps_setup.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("nps_setup.root");
      }
      f->GetObject("rem",tree);

   }
   Init(tree);
}

nps_setup::~nps_setup()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t nps_setup::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t nps_setup::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void nps_setup::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("col", &col, &b_col);
   fChain->SetBranchAddress("row", &row, &b_row);
   fChain->SetBranchAddress("pid", &pid, &b_pid);
   fChain->SetBranchAddress("edep", &edep, &b_Edep);
   fChain->SetBranchAddress("x", &x, &b_x);
   fChain->SetBranchAddress("y", &y, &b_y);
   fChain->SetBranchAddress("z", &z, &b_z);
   Notify();
}

Bool_t nps_setup::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void nps_setup::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t nps_setup::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef nps_setup_cxx
