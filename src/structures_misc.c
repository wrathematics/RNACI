RNACI_FUNTYPE void set_list_names(SEXP R_list, SEXP R_names)
{
  setAttrib(R_list, R_NamesSymbol, R_names);
}

RNACI_FUNTYPE void set_df_rownames(SEXP R_df, SEXP R_rownames)
{
  setAttrib(R_df, R_RowNamesSymbol, R_rownames);
}

RNACI_FUNTYPE void set_df_colnames(SEXP R_df, SEXP R_colnames)
{
  setAttrib(R_df, R_NamesSymbol, R_colnames);
}

RNACI_FUNTYPE void set_list_as_df(SEXP R_list)
{
  setAttrib(R_list, R_ClassSymbol, mkString("data.frame"));
}
