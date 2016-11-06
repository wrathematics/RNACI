#include "RNACI.h"

#define LEN 4

newRptrfreefun(myextptrfinfun, double, free)

SEXP RNACI_createptr()
{
  SEXP Rptr;
  
  double *x = malloc(LEN * sizeof(*x));
  for (int i=0; i<LEN; i++)
    x[i] = sqrt(i+1);
  
  newRptr(x, Rptr, myextptrfinfun);
  setRclass(Rptr, "myptr");
  
  unhideGC();
  return Rptr;
}

SEXP RNACI_getptr(SEXP Rptr)
{
  double *x = (double*) getRptr(Rptr);
  for (int i=0; i<LEN; i++)
    Rprintf("%.2f ", x[i]);
  
  Rputchar('\n');
  
  unhideGC();
  return RNULL;
}
