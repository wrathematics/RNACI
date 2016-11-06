#include "RNACI.h"


// Printing
SEXP RNACI_print()
{
  SEXP a;
  
  int nrow = 3;
  int ncol = 2;
  newRmat(a, nrow, ncol, "double");
  
  for (int j=0; j<ncol; j++)
    for (int i=0; i<nrow; i++)
      MatDBL(a, i, j) = i+j;
  
  PRINT(a);
  
  unhideGC();
  return RNULL;
}
