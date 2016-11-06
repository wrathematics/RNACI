#include "RNACI.h"

SEXP RNACI_intvec();
SEXP RNACI_dblvec();

SEXP RNACI_df()
{
  SEXP a, b;
  SEXP cn;
  SEXP R_df;
  
  hidefromGC(a = RNACI_intvec());
  hidefromGC(b = RNACI_dblvec());
  cn = make_list_names(2, "a", "b");
  R_df = make_dataframe(RNULL, cn, 2, a, b);
  
  unhideGC();
  return R_df;
}

SEXP RNACI_df_nonames()
{
  SEXP a, b;
  SEXP R_df;
  
  hidefromGC(a = RNACI_intvec());
  hidefromGC(b = RNACI_dblvec());
  
  R_df = make_dataframe(RNULL, RNULL, 2, a, b);
  
  unhideGC();
  return R_df;
}

SEXP RNACI_df_empty()
{
  SEXP R_df = make_dataframe(RNULL, RNULL, 0);
  unhideGC();
  return R_df;
}
