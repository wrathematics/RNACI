/* This Source Code Form is subject to the terms of the BSD 2-Clause
 * License. If a copy of the this license was not distributed with this
 * file, you can obtain one from http://opensource.org/licenses/BSD-2-Clause. */

// Copyright 2013, Schmidt

#include "SEXPtools/SEXPtools.h"


SEXP example_df()
{
  R_INIT;
  SEXP a, b;
  SEXP R_df, R_df_names;
  
  newRvec(a, 2, "int");
  newRvec(b, 2, "double");
  
  INT(a,0) = 1;
  INT(a,1) = 2;
  
  DBL(b,0) = -10.10214;
  DBL(b,1) = 1.23456;
  
  R_df_names = make_list_names(2, "abc", "defg");
  R_df = make_dataframe(RNULL, RNULL, 2, a, b);
  
  R_END;
  return R_df;
}




