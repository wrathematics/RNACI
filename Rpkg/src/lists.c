#include "RNACI.h"

SEXP RNACI_intvec();
SEXP RNACI_dblvec();

SEXP RNACI_list()
{
  SEXP a, b;
  SEXP R_list, R_list_names;
  
  hidefromGC(a = RNACI_intvec());
  hidefromGC(b = RNACI_dblvec());
  
  R_list_names = make_list_names(2, "a", "b");
  R_list = make_list(R_list_names, 2, a, b);
  
  unhideGC();
  return R_list;
}

SEXP RNACI_list_nonames()
{
  SEXP a, b;
  SEXP R_list;
  
  hidefromGC(a = RNACI_intvec());
  hidefromGC(b = RNACI_dblvec());
  
  R_list = make_list(RNULL, 2, a, b);
  
  unhideGC();
  return R_list;
}

SEXP RNACI_list_empty()
{
  SEXP R_df = make_list(RNULL, 0);
  unhideGC();
  return R_df;
}
