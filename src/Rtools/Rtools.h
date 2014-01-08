#ifndef __RTOOLS_H__
#define __RTOOLS_H__


#include <R.h>
#include <Rinternals.h>

#include <stdarg.h>
#include <string.h>


/* R stuff */

// Dummy return
#define RNULL R_NilValue

// R data accessors
#define INT(x,i) (INTEGER(x)[i])
#define DBL(x,i) (REAL(x)[i])
#define STR(x,i) ((char*)CHAR(STRING_ELT(x,i)))

#define INTP(x) (INTEGER(x))
#define DBLP(x) (REAL(x))

// GC stuff
#define PTINIT int __Rtools_protect_counter=0
#define PT(x) PROTECT((x)); (__Rtools_protect_counter)++
#define UNPT (UNPROTECT(__Rtools_protect_counter))


/* Misc stuff */

#define begin {printf(__func__##" Started\n");
#define end printf(__func__##" Ended\n");}


// alloc.c
SEXP Rvecalloc(int n, char *type);
SEXP Rmatalloc(int m, int n, char *type);

// printing.c
void PRINT(SEXP x);

// structures_lists.c
SEXP make_list_names(int n, ...);
SEXP make_list(SEXP R_list_names, ...);
SEXP make_list_nonames(int n, ...);


#endif
