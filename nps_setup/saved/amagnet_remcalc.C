#include "TList.h"
#include "TString.h"
#include "TLegend.h"
#include "TH1.h"                // eg. for 1D Histogram

//
// GN 2015
//
TH1F *make_a_frame(Double_t xmin, Double_t xmax, Double_t ymin, Double_t ymax, char *xlabel, char *ylabel, Int_t zones) {

  TH1F *a=new TH1F("hframe"," ",10,xmin,xmax);
  a->BufferEmpty(1); 
  a->SetMinimum(ymin);  a->SetMaximum(ymax);
  a->SetDirectory(0); a->SetStats(0);
  a->GetXaxis()->SetLabelSize(0.03*zones);  
  a->GetYaxis()->SetLabelSize(0.03*zones);
  a->GetXaxis()->CenterTitle(1);  
  a->GetYaxis()->CenterTitle(1);
  a->GetYaxis()->SetTitleOffset(0.75); 
  a->GetXaxis()->SetTitleOffset(0.75);
  a->GetXaxis()->SetTitleSize(0.06);  
  a->GetYaxis()->SetTitleSize(0.06);
  a->GetXaxis()->SetTitle(xlabel);
  a->GetYaxis()->SetTitle(ylabel);
  return a;
}
//////////////////////////////////////////////////
Double_t MeVtoRem(Double_t aKE) {
  Double_t Eref[22]={ .250E-07, .100E-06, .100E-05, .100E-04, .100E-03,
		      .100E-02, .100E-01, .100E+00, .500E+00, .100E+01, .250E+01,
		      .500E+01, .700E+01, .100E+02, .140E+02, .200E+02, .400E+02,
		      .600E+02, .100E+03, .200E+03, .300E+03, .400E+03};
  Double_t Cref[22]={ .1021E-05, .1021E-05, .1240E-05, .1240E-05, .1197E-05,
		      .1021E-05, .9921E-06, .6039E-05, .2572E-04, .3655E-04, .3472E-04,
		      .4340E-04, .4085E-04, .4085E-04, .5787E-04, .6313E-04, .6944E-04,
		      .6313E-04, .4960E-04, .5342E-04, .6313E-04, .6944E-04};
  Double_t crt_rem=0.;
  if (aKE <= Eref[0]) {
    crt_rem=Cref[0];
    return crt_rem;
  }
  else if (aKE >= Eref[21]) {
    crt_rem=Cref[21];
    return crt_rem;
  }
  for (Int_t i=1;i<=21;i++) {
      if (aKE >= Eref[i-1] && aKE <= Eref[i]) {
	crt_rem=(Cref[i]*(aKE-Eref[i-1]) + Cref[i-1]*(Eref[i]-aKE))
	  /(Eref[i]-Eref[i-1]);
	return crt_rem;
      }
  }
  //C -- mrem to 10^-12 Sievert (pSv)
  //    f = f / ABS(cos(theta)) * 1.e+07
  //C**      f = f * 1.e+07
  return crt_rem;
}
///////////////////////////////////////////////
void amagnet_remcalc(char *infile, Double_t BeamCurrent, Double_t nElectrons,char *atitle) {
  //
  // open output file, define histograms that go in it
  //
  //
  // beam current in uA
  // nElectrons in millions
  //
  Double_t aFactor=BeamCurrent/1.6*3600.*1.e7/nElectrons; // this factor should take the final answer to mrem/hr
  // cout <<"Conversion factor = "<<aFactor<<endl;  
  //  TFile *fout=new TFile(outfile,"RECREATE");
  //cout <<"Opening file "<<outfile<<" for writing."<<endl;

  Double_t rem_sums[9]={0.,0.,0.,0.,0.,0.,0.,0.,0.};
  Double_t rem_avg_KE[9]={0.,0.,0.,0.,0.,0.,0.,0.,0.};
  Double_t rem_avg_dist[9]={0.,0.,0.,0.,0.,0.,0.,0.,0.};
  // ghost volumes in cm^3
  //Double_t rem_vols[7]={0.,1700000.,600000.,210000.,210000.,600000.,1700000.}; // ghost volumes in cm^3
  // Double_t rem_vols[7]={0.,2700000.,1200000.,210000.,210000.,1200000.,2700000.}; // ghost volumes in cm^3 increase only in x
  //Double_t rem_vols[7]={0.,4050000.,1800000.,420000.,420000.,1800000.,4050000.}; // ghost volumes in cm^3 increase in x&y
  //  Double_t rem_vols[7]={0.,900000.,900000.,840000.,840000.,900000.,900000.}; // ghost volumes in cm^3. thin volumes 1.5 m from center
  Double_t rem_vols[9]={0.,90000000.,90000000.,89400000.,89400000.,90000000.,90000000.,0.,0.}; // ghost volumes in cm^3. thin volumes 15. m from center
  //Double_t rem_vols[9]={0,635040.,534240.,491840.,491840.,534240.,635040.,25000., 22372.}; // ghost volumes in cm^3. thin volumes 15. m from center
  // volumes 1-6 just outside green blocks, #7 - tgt coil, #8 amagnet coil
  Int_t rem_no[9]={0,0,0,0,0,0,0,0,0};

  TFile *f=new TFile(infile);
  cout <<"Opening file "<<infile<<" for reading."<<endl;

  // try looping over events only once!
  TTree *gn_tree=(TTree*)f->Get("rem");
  // get the (only) branch and set its address
  Int_t event, vol, ID; // event #, vol #, particle ID
  Double_t dist, KE; // distance in mm, KE in MeV
  Double_t x,y,z,px,py,pz;
  TBranch *b0 = gn_tree->GetBranch("event");
  b0->SetAddress(&event);
  TBranch *b1 = gn_tree->GetBranch("vol");
  b1->SetAddress(&vol);
  TBranch *b2 = gn_tree->GetBranch("ID");
  b2->SetAddress(&ID);
  TBranch *b3 = gn_tree->GetBranch("dist");
  b3->SetAddress(&dist);
  TBranch *b4 = gn_tree->GetBranch("KE");
  b4->SetAddress(&KE);
  TBranch *b5 = gn_tree->GetBranch("x");
  b5->SetAddress(&x);
  TBranch *b6 = gn_tree->GetBranch("y");
  b6->SetAddress(&y);
  TBranch *b7 = gn_tree->GetBranch("z");
  b6->SetAddress(&z);
  TBranch *b8 = gn_tree->GetBranch("px");
  b7->SetAddress(&px);
  TBranch *b9 = gn_tree->GetBranch("py");
  b8->SetAddress(&py);
  TBranch *b10 = gn_tree->GetBranch("pz");
  b10->SetAddress(&pz);
  

  
  Int_t no_of_events = gn_tree->GetEntries();
  cout << "This file has "<<no_of_events<<" events in it"<<endl;

  TH2D *gxy=new TH2D("gxy","Photon x vs y; x (mm); y (mm)",200,-5.,5.,200,-5.,5.);
  TH2D *exy=new TH2D("exy","Electron x vs y; x (mm); y (mm)",200,-5.,5.,200,-5.,5.);  
  TH2D *gpxy=new TH2D("gpxy","Photon px vs py; px (MeV); py (MeV)",120,-60.,60.,120,-60.,60.);
  
  for (Int_t i=0;i<no_of_events;i++) {
    if(i%250000 == 0) fprintf(stdout,"event\t%d\n",i);
    // read event
    b0->GetEntry(i);
    b1->GetEntry(i);
    b2->GetEntry(i);
    b3->GetEntry(i);
    b4->GetEntry(i);
    if (vol >=1 && vol <=8 && abs(ID-2112)<=0.5) {
      rem_sums[vol]+=MeVtoRem(KE)*dist/10.; // distance in cm
      rem_no[vol]++;
      rem_avg_KE[vol]+=KE;
      rem_avg_dist[vol]+=dist/10;
      //  cout <<"event = "<<event<<endl;
    }
  }
  Double_t total_mrem=0.;
  for (Int_t i=1;i<9;i++) {
    rem_sums[i]=rem_sums[i]/rem_vols[i]*aFactor;
    total_mrem+=rem_sums[i];
    if (rem_no[i]>0) {
      rem_avg_KE[i]=rem_avg_KE[i]/rem_no[i];
      rem_avg_dist[i]=rem_avg_dist[i]/rem_no[i];
    }
    cout << " Vol = "<<i<<" hits = "<<rem_no[i]<<" avg.nKE (MeV)= "<<rem_avg_KE[i]<<" avg.d (cm)= "<<rem_avg_dist[i]<<" rem_sum = "<<rem_sums[i]<<" mrem/hr"<<endl;
  }
  cout << "total = "<<total_mrem<<" mrem/hr"<<endl;
  // Now plot x:y:z type distributions for each volume
  /*
  TBox *bb1=new TBox(-.500,-.350,.500,.350);bb1->SetFillStyle(0);bb1->SetLineColor(kBlack);bb1->SetLineWidth(2);
  TBox *bb2=new TBox(-.500,-.300,.500,.300);bb2->SetFillStyle(0);bb2->SetLineColor(kBlack);bb2->SetLineWidth(2);
  TBox *bb3=new TBox(-.350,-.300,.350,.300);bb3->SetFillStyle(0);bb3->SetLineColor(kBlack);bb3->SetLineWidth(2);

  TH2D *h1=new TH2D("h1","Top view;z (m);x (m)",30,-15,15,30,-15,15.);
  TH2D *h6=new TH2D("h6","Bottom view;z (m);x (m)",30,-15,15,30,-15,15.);
  TH2D *h3=new TH2D("h3","Upstream view;x (m);y (m)",30,-15,15,30,-15,15.);
  TH2D *h4=new TH2D("h4","Downstream view;x (m);y (m)",30,-15,15,30,-15,15.);
  TH2D *h2=new TH2D("h2","Right view;z (m);y (m)",30,-15,15,30,-15,15.);
  TH2D *h5=new TH2D("h5","Left view;z (m);y (m)",30,-15,15,30,-15,15.);


 
  rem->Project("h1","x/1000.:z/1000.","vol==1 && ID==2112");
  rem->Project("h6","x/1000.:z/1000.","vol==6 && ID==2112");
  rem->Project("h2","y/1000.:z/1000.","vol==2 && ID==2112");
  rem->Project("h5","y/1000.:z/1000.","vol==5 && ID==2112");
  rem->Project("h3","y/1000.:x/1000.","vol==3 && ID==2112");
  rem->Project("h4","y/1000.:x/1000.","vol==4 && ID==2112");


  rem->Project("gpxy","py:px","ID == 22 && KE>=6000.");
  rem->Project("gxy","y-14000*py/sqrt(px*px+py*py+pz*pz):x-14000*px/sqrt(px*px+py*py+pz*pz)","ID == 22 && KE>=6000. &&
TMath::Sqrt((y-14000*py/sqrt(px*px+py*py+pz*pz))*(y-14000*py/sqrt(px*px+py*py+pz*pz))+(x-14000*px/sqrt(px*px+py*py+pz*pz)-1)*(x-14000*px/sqrt(px*px+py*py+pz*pz)-1))<2.");
  
  h1->Draw("col"); bb1->DrawClone();  c1->Print(Form("%s(",atitle),"pdf");
  h6->Draw("col"); bb1->DrawClone();  c1->Print(atitle,"pdf");
  h2->Draw("col"); bb2->DrawClone();  c1->Print(atitle,"pdf");
  h5->Draw("col"); bb2->DrawClone();  c1->Print(atitle,"pdf");
  h3->Draw("col"); bb3->DrawClone();  c1->Print(atitle,"pdf");
  h4->Draw("col"); bb3->DrawClone();  c1->Print(atitle,"pdf");

  h1->Rebin2D(2,2,"h11");
  h2->Rebin2D(2,2,"h21");
  h3->Rebin2D(2,2,"h31");
  h4->Rebin2D(2,2,"h41");
  h5->Rebin2D(2,2,"h51");
  h6->Rebin2D(2,2,"h61");
  c1->Clear();
  c1->Divide(2,3);
  c1->cd(1); h11->Draw("col");  bb1->DrawClone();
  c1->cd(2); h21->Draw("col");  bb1->DrawClone();
  c1->cd(3); h31->Draw("col");  bb2->DrawClone();
  c1->cd(4); h41->Draw("col");  bb2->DrawClone();
  c1->cd(5); h51->Draw("col");  bb3->DrawClone();
  c1->cd(6); h61->Draw("col");  bb3->DrawClone();
  c1->Print(atitle,"pdf");
  c1->Clear();
  
  Bool_t do_legend=kFALSE;
  Double_t beam_radius=0.50; // in mm
  Double_t hole_radius=2.0; // in mm
  Int_t hole_no=0;
  Double_t x0[5]={0.1, 0.093,-0.4 ,-0.566,0.278};
  Double_t y0[5]={0. , 0.285, 0.29, -0.41, -0.856};
  TArc *hole=new TArc(x0[hole_no]*10.,y0[hole_no]*10.,hole_radius);
  TArc *hole2=new TArc(x0[hole_no]*10.,y0[hole_no]*10.,beam_radius);
  hole->SetLineColor(kRed); hole2->SetLineColor(kGreen);
  hole->SetFillStyle(0); hole2->SetFillStyle(0); hole->SetLineWidth(4);
  
  gxy->Draw("colz"); hole->Draw("same");c1->Print(atitle,"pdf");
  //  exy->Draw("colz"); c1->Print(atitle,"pdf");
  gpxy->Draw("colz"); c1->Print(Form("%s)",atitle),"pdf");
  */
  //  f->Close();
  /*  fout->cd();
  fout->Write();
  fout->Close();
  */
}
