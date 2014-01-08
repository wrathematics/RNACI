/* This Source Code Form is subject to the terms of the BSD 2-Clause
 * License. If a copy of the this license was not distributed with this
 * file, you can obtain one from http://opensource.org/licenses/BSD-2-Clause. */

// Copyright (c) 2014, Schmidt


#include "Rtools.h"


void PRINT(SEXP x)
{
  PTINIT;
  SEXP basePackage;
  
  PT(basePackage);
  basePackage = eval( lang2( install("getNamespace"), ScalarString(mkChar("base")) ), R_GlobalEnv );
  
  eval( lang2( install("print"), x), basePackage);
  
  UNPT;
}


