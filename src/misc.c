/* This Source Code Form is subject to the terms of the BSD 2-Clause
 * License. If a copy of the this license was not distributed with this
 * file, you can obtain one from http://opensource.org/licenses/BSD-2-Clause. */

// Copyright 2014, Schmidt


#include "SEXPtools.h"

int is_Rnull(SEXP x)
{
  R_INIT;
  SEXP basePackage;
  SEXP tmp;
  
  PT( basePackage = eval( lang2( install("getNamespace"), ScalarString(mkChar("base")) ), R_GlobalEnv ) );
  
  tmp = eval( lang2( install("is.null"), x), basePackage);
  
  R_END;
  return INT(tmp,0);
}



int is_Rnan(SEXP x)
{
  R_INIT;
  SEXP basePackage;
  SEXP tmp;

  PT( basePackage = eval( lang2( install("getNamespace"), ScalarString(mkChar("base")) ), R_GlobalEnv ) );

  tmp = eval( lang2( install("is.nan"), x), basePackage);

  R_END;
  return INT(tmp,0);
}



int is_Rna(SEXP x)
{
  R_INIT;
  SEXP basePackage;
  SEXP tmp;
  
  PT( basePackage = eval( lang2( install("getNamespace"), ScalarString(mkChar("base")) ), R_GlobalEnv ) );
  
  tmp = eval( lang2( install("is.na"), x), basePackage);
  
  R_END;
  return INT(tmp,0);
}



int is_double(SEXP x)
{
  R_INIT;
  SEXP basePackage;
  SEXP tmp;
  
  PT( basePackage = eval( lang2( install("getNamespace"), ScalarString(mkChar("base")) ), R_GlobalEnv ) );
  
  tmp = eval( lang2( install("is.double"), x), basePackage);
  
  R_END;
  return INT(tmp,0);
}



int is_integer(SEXP x)
{
  R_INIT;
  SEXP basePackage;
  SEXP tmp;
  
  PT( basePackage = eval( lang2( install("getNamespace"), ScalarString(mkChar("base")) ), R_GlobalEnv ) );
  
  tmp = eval( lang2( install("is.integer"), x), basePackage);
  
  R_END;
  return INT(tmp,0);
}

