/* This Source Code Form is subject to the terms of the BSD 2-Clause
 * License. If a copy of the this license was not distributed with this
 * file, you can obtain one from http://opensource.org/licenses/BSD-2-Clause. */

// Copyright 2013, Schmidt

#include "../Rtools/Rtools.h"


// Lists
SEXP test_list(SEXP names)
{
  R_INIT;
  SEXP a, b;
  SEXP R_list, R_list_names;
  int hasnames = INTEGER(names)[0];
  
  PT(a = Rvecalloc(2, "int"));
  PT(b = Rvecalloc(1, "double"));
  
  INT(a,0) = 1;
  INT(a,1) = 2;
  
  DBL(b,0) = -10.10214;
  
  if (hasnames == 0)
    R_list = make_list_nonames(2, a, b);
  else
  {
    R_list_names = make_list_names(2, "abc", "defg");
    R_list = make_list(R_list_names, a, b);
  }
  
  
  R_END;
  return R_list;
}



// Printing
SEXP test_print()
{
  R_INIT;
  SEXP a;
  
  PT(a = Rmatalloc(2, 2, "double"));
  
  DBL(a,0) = 1;
  DBL(a,1) = 2;
  DBL(a,2) = 3;
  DBL(a,3) = 4;
  
  PRINT(a);
  
  R_END;
  return RNULL;
}



// Dataframes
SEXP test_df()
{
  R_INIT;
  SEXP a, b;
  SEXP R_df, R_df_names;
  
  Rvec(a, 2, "int");
  Rvec(b, 2, "double");
  
  INT(a,0) = 1;
  INT(a,1) = 2;
  
  DBL(b,0) = -10.10214;
  DBL(b,1) = 1.23456;
  
  R_df_names = make_list_names(2, "abc", "defg");
  R_df = make_dataframe_nonames(2, a, b);
  
  R_END;
  return R_df;
}




