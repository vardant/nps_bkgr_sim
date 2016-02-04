void edeps() {

  gROOT->ProcessLine(".L nps_setup.C++");
  nps_setup* nps = new nps_setup();
  nps->LoopEdepMap();
}
