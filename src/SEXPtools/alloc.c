/* This Source Code Form is subject to the terms of the BSD 2-Clause
 * License. If a copy of the this license was not distributed with this
 * file, you can obtain one from http://opensource.org/licenses/BSD-2-Clause. */

// Copyright 2014, Schmidt


#include "SEXPtools.h"


SEXP __Rvecalloc(int n, char *type, int init)
{
  SEXP RET;
  int i;
  
  if (strcmp(type, "vec") == 0)
    PROTECT(RET = allocVector(VECSXP, n));
  else if (strcmp(type, "int") == 0)
  {
    PROTECT(RET = allocVector(INTSXP, n));
    
    if (init)
    {
      #if defined( _OPENMP_SUPPORT_SIMD)
      #pragma omp for simd
      #endif
      for (i=0; i<n; i++)
        INT(RET, i) = 0;
    }
  }
  else if (strcmp(type, "double") == 0 || strcmp(type, "dbl") == 0)
  {
    PROTECT(RET = allocVector(REALSXP, n));
    
    if (init)
    {
      #if defined( _OPENMP_SUPPORT_SIMD)
      #pragma omp for simd
      #endif
      for (i=0; i<n; i++)
        DBL(RET, i) = 0.0;
    }
  }
  else if (strcmp(type, "str") == 0 || strcmp(type, "char*") == 0)
    PROTECT(RET = allocVector(STRSXP, n));
  else
    return NULL;
  
  UNPROTECT(1);
  return RET;
}



SEXP __Rmatalloc(int m, int n, char *type, int init)
{
  SEXP RET;
  int i, j;
  
  if (strcmp(type, "vec") == 0)
    PROTECT(RET = allocMatrix(VECSXP, m, n));
  else if (strcmp(type, "int") == 0)
  {
    PROTECT(RET = allocMatrix(INTSXP, m, n));
    
    if (init)
    {
      for (j=0; j<n; j++)
      {
        #if defined( _OPENMP_SUPPORT_SIMD)
        #pragma omp for simd
        #endif
        for (i=0; i<m; i++)
          MatINT(RET, i, j) = 0;
      }
    }
  }
  else if (strcmp(type, "double") == 0 || strcmp(type, "dbl") == 0)
  {
    PROTECT(RET = allocMatrix(REALSXP, m, n));
    
    if (init)
    {
      for (j=0; j<n; j++)
      {
        #if defined( _OPENMP_SUPPORT_SIMD)
        #pragma omp for simd
        #endif
        for (i=0; i<m; i++)
          MatDBL(RET, i, j) = 0.0;
      }
    }
  }
  else if (strcmp(type, "str") == 0 || strcmp(type, "char*") == 0)
    PROTECT(RET = allocMatrix(STRSXP, m, n));
  else
    return NULL;
  
  UNPROTECT(1);
  return RET;
}

