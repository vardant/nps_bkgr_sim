#include "TList.h"
#include "TString.h"
#include "TLegend.h"
#include "TH1.h"      
#include "TH2.h"      
#include "TTree.h"
#include "TFile.h"
#include <iostream>
#include "Riostream.h"
#include "TCanvas.h"
#include "TROOT.h"
#include "TLegend.h"

//
// GN 2015
//
TH1F *make_a_frame(Double_t xmin, Double_t xmax, Double_t ymin, Double_t ymax, char *xlabel, char *ylabel, Int_t zones) {

  TH1F *a=new TH1F("hframe","",10,xmin,xmax);
  a->BufferEmpty(1); 
  a->SetMinimum(ymin);  a->SetMaximum(ymax);
  a->SetDirectory(0); a->SetStats(0);
  a->GetXaxis()->SetLabelSize(0.03*zones);  
  a->GetYaxis()->SetLabelSize(0.03*zones);
  a->GetXaxis()->CenterTitle(1);  
  a->GetYaxis()->CenterTitle(1);
  a->GetYaxis()->SetTitleOffset(0.85); 
  a->GetXaxis()->SetTitleOffset(0.75);
  //  a->GetXaxis()->SetTitleSize(0.06);  
  //a->GetYaxis()->SetTitleSize(0.06);
  a->GetXaxis()->SetTitleSize(0.05);  
  a->GetYaxis()->SetTitleSize(0.05);
  a->GetXaxis()->SetTitle(xlabel);
  a->GetYaxis()->SetTitle(ylabel);
  return a;
}
///////////////////////////////////////////////
void amagnet_genplot(char *infile, Double_t nElectrons) {

  Double_t NeScale=1./nElectrons/1000000.;
  //
  // nElectrons (in millions)
  //

  // open input file
  TFile *f=new TFile(infile);
  cout <<"Opening file "<<infile<<" for reading."<<endl;

  TCanvas *c1=new TCanvas("c1","c1",1024,768);
  //  Int_t nBinsX;
  Int_t nBinsY=8;
  Double_t KEmin=0.1;
  Double_t KEmax=15000.;
  Int_t iyBins[9]={0,5,10,20,40,60,90,130,180};
  //
  // project 2D histograms in X (for xsect vs T) and in Y (for Xsect vs theta)
  //
  // looping over strings...
  char *names[7]={"em","ep","gamma","pim","pip","neutron","proton"};
  char *crtname;  //  cout << names[0]<<" and "<<names[1]<<" and "<<names[2]<<endl;
  TH2D *crt2d=NULL;
  Int_t ybin1, ybin2;
  em->ProjectionY("emangle");
  for (int j=0;j<7;j++) {
    for (int i=1; i<=nBinsY;i++) {
      crtname=Form("%s%s%d",names[j],"t",i);
      crt2d=(TH2D *)gROOT->FindObject(names[j]);
      ybin1=emangle->FindBin(iyBins[i-1]);
      ybin2=emangle->FindBin(iyBins[i]);
      //      cout <<"crtname = "<<crtname<<" ybin1 = "<<ybin1<<" ybin2 = "<<ybin2<<endl;
      crt2d->ProjectionX(crtname,ybin1,ybin2);
    }
  }
  Int_t xBins=9;
  Double_t xLimits[9]={0.1, 0.3, 1.0, 3.2, 10., 31.6, 100., 316.2, 1000.};
    //Double_t xLimits[7]={0.1,3.2,10.,31.6,100.,316.2,1000.};
  Int_t tmpbin,maxbin;
  maxbin=em->GetNbinsX();
  em->ProjectionX("emKE");
  for (int j=0;j<7;j++) {
    for (int i=1; i<=xBins;i++) {
      tmpbin=emKE->FindBin(xLimits[i]);
      crtname=Form("%s%s%d",names[j],"a",i);
      crt2d=(TH2D *)gROOT->FindObject(names[j]);
      crt2d->ProjectionY(crtname,tmpbin,maxbin);
    }
  }
  //
  /// Now plot some stuff
  //
  Bool_t first_page=kFALSE;
  Double_t crtttscale;
  Double_t degrad=3.14159/180.;
  TH1D *crthist=NULL;
  TH1F *aframe1=NULL;
  TH1F *aframe2=NULL;

  aframe1=make_a_frame(.1, 10000.,1.e-12,50.," T [MeV]","N_{e}^{-1} dN/d#Omega/dT/N_{e} [el^{-1} MeV^{-1} sr^{-1}]",1);
  aframe2=make_a_frame(0.,180.,1.e-11,500.," theta [deg]","N_{e}^{-1} dN/d#Omega/N_{e} [el^{-1} sr^{-1}]",1);
  //
  // loop over particle types
  //
  for (int j=5;j<6;j++) {
    gPad->SetLogy(1);
    gPad->SetLogx(1);
    gPad->SetGridx();
    gPad->SetGridy();
     //gPad->SetBottomMargin(0.2);
    if (j==0)    aframe1->SetTitle("                   e^{-} + C --> e^{-} + X");
    if (j==1)    aframe1->SetTitle("                   e^{-} + C --> e^{+} + X");
    if (j==2)    aframe1->SetTitle("                   e^{-} + C --> #gamma + X");
    if (j==3)    aframe1->SetTitle("                   e^{-} + C --> #pi^{-} + X");
    if (j==4)    aframe1->SetTitle("                   e^{-} + C --> #pi^{+} + X");
    if (j==5)    aframe1->SetTitle("                   e^{-} + C --> n + X");
    if (j==6)    aframe1->SetTitle("                   e^{-} + C --> p + X");
    aframe1->DrawClone();
    
    TLegend *l1=new TLegend(0.5,.5,0.9,.9);//"","NDC");       
    l1->SetFillColor(0);l1->SetTextSize(0.045);
    //
    // loop over particle types once more
    //
    for (int i=1; i<=nBinsY;i++) {
      ybin1=ttScale->FindBin(iyBins[i-1]);
      ybin2=ttScale->FindBin(iyBins[i]);
      /*
	for (int ii=ybin1;ii<=ybin2;ii++) {
	crtttscale=crtttscale+ttScale->GetBinContent(ii);
      }
      */
      crtttscale=cos(iyBins[i-1]*degrad)-cos(iyBins[i]*degrad);
      //      
      crtttscale=1./crtttscale/2./3.14159;
      crtname=Form("%s%s%d",names[j],"t",i);
      crthist= (TH1D *)gROOT->FindObject(crtname);
      crthist->Divide(KEScale);
      crthist->Scale(crtttscale);
      crthist->Scale(NeScale);
      //      if (i%3==0)      crthist->SetLineColor(kRed);
      // if (i%3==1)      crthist->SetLineColor(kGreen);
      //if (i%3==2)      crthist->SetLineColor(kBlue);
      //crthist->SetLineWidth(2*int(i/3)+1);
      crthist->SetLineColor(1+i%6);
      crthist->DrawClone("same");
      l1->AddEntry(crthist,Form("%d^{o} < #theta < %d^{o}",iyBins[i-1],iyBins[i]),"l");
    }
    l1->DrawClone("");
    if (!first_page) {
      c1->Print("amagnet_gentest_just_n.pdf(","pdf");
      first_page=kTRUE;
    }
    else {
      c1->Print("amagnet_gentest_just_n.pdf","pdf");
    }
      
    //
    // pad 2
    // xsect vs angle
    //
    gPad->SetLogy(1);
    gPad->SetLogx(0);
    //gPad->SetBottomMargin(0.1);
    if (j==0)    aframe2->SetTitle("                   e^{-} + C --> e^{-} + X");
    if (j==1)    aframe2->SetTitle("                   e^{-} + C --> e^{+} + X");
    if (j==2)    aframe2->SetTitle("                   e^{-} + C --> \gamma + X");
    if (j==3)    aframe2->SetTitle("                   e^{-} + C --> \pi^{-} + X");
    if (j==4)    aframe2->SetTitle("                   e^{-} + C --> \pi^{+} + X");
    if (j==5)    aframe2->SetTitle("                   e^{-} + C --> n + X");
    if (j==6)    aframe2->SetTitle("                   e^{-} + C --> p + X");   
    aframe2->Draw();
    TLegend *l2=new TLegend(0.5,.5,0.9,.9);//"","NDC");       
    l2->SetFillColor(0);l2->SetTextSize(0.045);
    //
    for (int i=1; i<=xBins;i++) {
      crtname=Form("%s%s%d",names[j],"a",i);
      crthist= (TH1D *)gROOT->FindObject(crtname);
      crthist->Divide(ttScale);
      crthist->Scale(NeScale);
      crtttscale=1./2./3.14159;
      crthist->Scale(crtttscale);
      //      if (i%3==0)      crthist->SetLineColor(kRed);
      //if (i%3==1)      crthist->SetLineColor(kGreen);
      //if (i%3==2)      crthist->SetLineColor(kBlue);
      // crthist->SetLineWidth(2*int(i/3)+1);
      crthist->SetLineColor(1+i%6);
      crthist->DrawClone("same");
      l2->AddEntry(crthist,Form("T > %5.1f MeV",xLimits[i-1]),"l");
    }
    l2->DrawClone("");
    if (j==5) {
      c1->Print("amagnet_gentest_just_n.pdf)","pdf");
    }
    if (j<5) {
      c1->Print("amagnet_gentest_just_n.pdf","pdf");
    }
  }
}
