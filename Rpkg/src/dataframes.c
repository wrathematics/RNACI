#include "RNACI.h"

SEXP RNACI_intvec();
SEXP RNACI_dblvec();

SEXP RNACI_df()
{
  R_INIT;
  SEXP a, b;
  SEXP cn;
  SEXP R_df;
  
  a = RNACI_intvec();
  b = RNACI_dblvec();
  cn = make_list_names(2, "a", "b");
  R_df = make_dataframe(RNULL, cn, 2, a, b);
  
  R_END;
  return R_df;
}

SEXP RNACI_df_nonames()
{
  R_INIT;
  SEXP a, b;
  SEXP R_df;
  
  a = RNACI_intvec();
  b = RNACI_dblvec();
  
  R_df = make_dataframe(RNULL, RNULL, 2, a, b);
  
  R_END;
  return R_df;
}

SEXP RNACI_df_empty()
{
  return make_dataframe(RNULL, RNULL, 0);
}
