/*  Copyright (c) 2014, Schmidt
    All rights reserved.
    
    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met: 
    
    1. Redistributions of source code must retain the above copyright notice, this
       list of conditions and the following disclaimer. 
    2. Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer in the documentation
       and/or other materials provided with the distribution. 
    
    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
    ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
    
    The views and conclusions contained in the software and documentation are those
    of the authors and should not be interpreted as representing official policies, 
    either expressed or implied, of the FreeBSD Project.  */


#include "Rtools.h"


SEXP make_dataframe(SEXP R_names,)
{
  SEXP RET, PRIMES, POWERS, ROWNAMES, COLNAMES;
  
  // Factor n
  integer_factorization(INTEGER(n)[0], &pf);
  
  // Create the dataframe --- probably shoulda just used eval tbh
  PROTECT(RET = allocVector(VECSXP, 2));
  PROTECT(PRIMES = allocVector(INTSXP, pf.num));
  PROTECT(POWERS = allocVector(INTSXP, pf.num));
  SET_VECTOR_ELT(RET, 0, PRIMES);
  SET_VECTOR_ELT(RET, 1, POWERS);
  
  for (i=0; i<pf.num; i++)
  {
    INTEGER(PRIMES)[i] = pf.factors[i].factor;
    INTEGER(POWERS)[i] = pf.factors[i].power;
  }
  
  PROTECT(ROWNAMES = allocVector(INTSXP, pf.num));
  for(i=0; i<pf.num; i++)
  {
    INTEGER(ROWNAMES)[i] = i + 1;
  }
  
  PROTECT(COLNAMES = allocVector(STRSXP, 2));
  SET_STRING_ELT(COLNAMES, 0, mkChar("Prime"));
  SET_STRING_ELT(COLNAMES, 1, mkChar("Power"));
  
  setAttrib(RET, R_ClassSymbol, mkString("data.frame"));
  setAttrib(RET, R_RowNamesSymbol, ROWNAMES);
  setAttrib(RET, R_NamesSymbol, COLNAMES);
  
  UNPROTECT(5);
  return RET;
}



