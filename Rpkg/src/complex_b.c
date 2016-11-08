#include "RNACI.h"

SEXP RNACI_complexa1();
SEXP RNACI_complexa2();
SEXP RNACI_complexa3();

SEXP RNACI_complex()
{
  SEXP df1, df2, df3;
  SEXP ret, retnames;
  
  df1 = RNACI_complexa1();
  df2 = RNACI_complexa2();
  df3 = RNACI_complexa3();
  
  retnames = make_list_names(3, "df1", "df2", "df3");
  ret = make_list(retnames, 3, df1, df2, df3);
  
  unhideGC();
  return ret;
}
