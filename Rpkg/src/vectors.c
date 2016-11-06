#include "RNACI.h"

#define NELTS 4

SEXP RNACI_intvec()
{
  SEXP x;
  
  newRvec(x, NELTS, "int");
  
  for (int i=0; i<NELTS; i++)
    INT(x, i) = i+1;
  
  unhideGC();
  return x;
}

SEXP RNACI_dblvec()
{
  SEXP x;
  
  newRvec(x, NELTS, "dbl");
  
  for (int i=0; i<NELTS; i++)
    DBL(x, i) = 123456 / (double)(i+1);
  
  unhideGC();
  return x;
}
