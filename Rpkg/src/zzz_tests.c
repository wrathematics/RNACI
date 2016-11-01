/* This Source Code Form is subject to the terms of the BSD 2-Clause
 * License. If a copy of the this license was not distributed with this
 * file, you can obtain one from http://opensource.org/licenses/BSD-2-Clause. */

// Copyright 2013-2015, Schmidt

#include "RNACI.h"


// Lists
SEXP test_list(SEXP names)
{
  R_INIT;
  SEXP a, b;
  SEXP R_list, R_list_names;
  int hasnames = INT(names,0);
  
  newRvec(a, 2, "int");
  newRvec(b, 1, "double");
  
  INT(a,0) = 1;
  INT(a,1) = 2;
  
  DBL(b,0) = -10.10214;
  
  if (hasnames == 0)
    R_list = make_list(RNULL, 2, a, b);
  else
  {
    R_list_names = make_list_names(2, "abc", "defg");
    R_list = make_list(R_list_names, 2, a, b);
  }
  
  
  R_END;
  return R_list;
}


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



// Dataframes
SEXP test_df()
{
  R_INIT;
  SEXP a, b;
  SEXP R_df;
  
  const int nrows = 4;
  newRvec(a, nrows, "int");
  newRvec(b, nrows, "double");
  
  for (int i=0; i<nrows; i++)
    INT(a, i) = i+1;
  
  for (int i=0; i<nrows; i++)
    DBL(b, i) = 123456 / (double)(i+1);
  
  // df without names
  R_df = make_dataframe(RNULL, RNULL, 2, a, b);
  
  PRINT(R_df);
  
  R_END;
  return R_df;
}
