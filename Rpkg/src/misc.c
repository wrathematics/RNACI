/* This Source Code Form is subject to the terms of the BSD 2-Clause
 * License. If a copy of the this license was not distributed with this
 * file, you can obtain one from http://opensource.org/licenses/BSD-2-Clause. */

// Copyright 2013-2015, Schmidt

#include "RNACI.h"


// Printing
SEXP test_print()
{
  R_INIT;
  SEXP a;
  
  int nrow = 3;
  int ncol = 2;
  newRmat(a, nrow, ncol, "double");
  
  for (int j=0; j<ncol; j++)
    for (int i=0; i<nrow; i++)
      MatDBL(a, i, j) = i+j;
  
  PRINT(a);
  
  R_END;
  return RNULL;
}

