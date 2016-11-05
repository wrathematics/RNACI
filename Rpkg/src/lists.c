#include "RNACI.h"

SEXP RNACI_intvec();
SEXP RNACI_dblvec();

SEXP RNACI_list()
{
  SEXP a, b;
  SEXP R_list, R_list_names;
  
  a = RNACI_intvec();
  b = RNACI_dblvec();
  
  R_list_names = make_list_names(2, "a", "b");
  R_list = make_list(R_list_names, 2, a, b);
  
  return R_list;
}

SEXP RNACI_list_nonames()
{
  SEXP a, b;
  SEXP R_list;
  
  a = RNACI_intvec();
  b = RNACI_dblvec();
  
  R_list = make_list(RNULL, 2, a, b);
  
  return R_list;
}

SEXP RNACI_list_empty()
{
  return make_list(RNULL, 0);
}
