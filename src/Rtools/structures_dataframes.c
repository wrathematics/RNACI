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

// Internals
SEXP make_dataframe_default_colnames(int n)
{
  PTINIT;
  int i;
  SEXP basePackage;
  SEXP x;
  SEXP ret_names;
  
  PT(basePackage);
  basePackage = eval( lang2( install("getNamespace"), ScalarString(mkChar("base")) ), R_GlobalEnv );
  
  PT(x = Rvecalloc(n, "int"));
  
  for (i=0; i<n; i++)
    INT(x,i) = i+1;
  
  PT(ret_names);
  
  ret_names = eval( lang2( install("make.names"), x), basePackage);
  
  UNPT;
  return ret_names;
}



SEXP make_dataframe_default_rownames(int n)
{
  PTINIT;
  int i;
  SEXP ret_names;
  
  PT(ret_names = Rvecalloc(n, "int"));
  for(i=0; i<n; i++)
    INT(ret_names,i) = i + 1;
  
  UNPT;
  return ret_names;
}



// Actually useful things
SEXP make_dataframe_nonames(int n, ...)
{
  PTINIT;
  int i, nrows;
  SEXP R_list;
  SEXP R_rownames;
  SEXP R_colnames;
  SEXP tmp;
  va_list listPointer;
  
  // Construct list
  PT(R_list = Rvecalloc(n, "vec"));
  
  va_start(listPointer, n);
  
  for(i=0; i<n; i++)
  {
    tmp = va_arg(listPointer, SEXP);
    
    SET_VECTOR_ELT(R_list, i, tmp);
  }
  
  va_end(listPointer);
  
  // Set rownames
  R_rownames = make_dataframe_default_rownames(n);
  
  // Set colnames
  R_colnames = make_dataframe_default_colnames(n);
  
  setAttrib(R_list, R_ClassSymbol, mkString("data.frame"));
  setAttrib(R_list, R_RowNamesSymbol, R_rownames);
  setAttrib(R_list, R_NamesSymbol, R_colnames);
  
  UNPT;
  return R_list;
}

