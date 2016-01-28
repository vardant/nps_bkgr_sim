#ifndef SimpleField_H
#define SimpleField_H 1

/**
  * @file
  * @brief Defines class SimpleField
*/
#include "globals.hh"
#include "G4MagneticField.hh"
 
#include <fstream>
#include <vector>

using namespace std;

class SimpleField 

#ifndef STANDALONE
: public G4MagneticField
#endif

{
public:
  SimpleField();
  ~SimpleField();
  void GetFieldValue( const  double Point[4],
		      double *Bfield ) const;
private:
  G4double Bvalue;
  // G4double rmax_sq;
  // G4double zMin;
  G4double zMax;
  G4double str;
  
  vector< vector< vector< double > > > fXField;
  vector< vector< vector< double > > > fYField;
  vector< vector< vector< double > > > fZField;
  G4int fNx,fNy,fNz; 
  G4double fMinix, fMaxix, fMiniy, fMaxiy, fMiniz, fMaxiz;
  G4double fDx, fDy, fDz;
  G4float fGradient1, fGradient2, fGradient3, fGradient4;
  
};

#endif
