/* This Source Code Form is subject to the terms of the BSD 2-Clause
 * License. If a copy of the this license was not distributed with this
 * file, you can obtain one from http://opensource.org/licenses/BSD-2-Clause. */

// Copyright 2014, Schmidt


#include <R.h>
#include <Rinternals.h>

SEXP Rtrue;
SEXP Rfalse;
PROTECT(Rtrue = allocVector(LGLSXP, 1));
PROTECT(Rfalse = allocVector(LGLSXP, 1));
//LOGICAL(Rtrue)[0] = 1;
//LOGICAL(Rtrue)[0] = 0;
UNPROTECT(2);


static SEXP assignValueToFooInR_GlobalEnv(SEXP Value)
{
    defineVar(install("Foo"),Value,R_GlobalEnv);
    return Value;
}
