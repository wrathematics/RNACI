#ifndef __RNACI_API_H_
#define __RNACI_API_H_


#include <R.h>
#include <Rinternals.h>

#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <float.h>

#include "internal.h"

// floats.c
RNACI_FUNTYPE int fis_zerof(float x);
RNACI_FUNTYPE int fis_zero(double x);
RNACI_FUNTYPE int fequalsf(float x, float y);
RNACI_FUNTYPE int fequals(double x, double y);

// misc.c
RNACI_FUNTYPE int is_Rnull(SEXP x);
RNACI_FUNTYPE int is_Rnan(SEXP x);
RNACI_FUNTYPE int is_Rna(SEXP x);
RNACI_FUNTYPE int is_double(SEXP x);
RNACI_FUNTYPE int is_integer(SEXP x);

// printinc.c
RNACI_FUNTYPE void PRINT(SEXP x);

// structures_dataframes.c
RNACI_FUNTYPE SEXP make_dataframe_default_colnames(const int n);
RNACI_FUNTYPE SEXP make_dataframe_default_rownames(int n);
RNACI_FUNTYPE SEXP make_dataframe(SEXP R_rownames, SEXP R_colnames, int n, ...);

// structures_lists.c
RNACI_FUNTYPE SEXP make_list_names(int n, ...);
RNACI_FUNTYPE SEXP make_list(SEXP R_list_names, const int n, ...);

// structures_misc.c
RNACI_FUNTYPE void set_list_names(SEXP R_list, SEXP R_names);
RNACI_FUNTYPE void set_df_rownames(SEXP R_df, SEXP R_rownames);
RNACI_FUNTYPE void set_df_colnames(SEXP R_df, SEXP R_colnames);
RNACI_FUNTYPE void set_list_as_df(SEXP R_list);


#endif
