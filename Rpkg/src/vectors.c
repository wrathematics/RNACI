#include "RNACI.h"

#define NELTS 4

SEXP RNACI_intvec()
{
  R_INIT;
  SEXP x;
  
  newRvec(x, NELTS, "int");
  
  for (int i=0; i<NELTS; i++)
    INT(x, i) = i+1;
  
  R_END;
  return x;
}

SEXP RNACI_dblvec()
{
  R_INIT;
  SEXP x;
  
  newRvec(x, NELTS, "dbl");
  
  for (int i=0; i<NELTS; i++)
    DBL(x, i) = 123456 / (double)(i+1);
  
  R_END;
  return x;
}
