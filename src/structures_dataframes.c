RNACI_FUNTYPE SEXP make_dataframe_default_colnames(const int n)
{
  R_INIT;
  int i;
  int buflen;
  SEXP ret;
  
  buflen = (int) (ceil(log10((double)n)) + 1.);
  char *buf = malloc(buflen * sizeof(*buf));
  buf[0] = 'X';
  
  newRlist(ret, n);
  
  for (i=0; i<n; i++)
  {
    sprintf(buf+1, "%d", i+1);
    buflen = (int) (ceil(log10((double)i+2)) + 1.);
    buflen = RNACI_MAX(buflen, 2);
    SET_VECTOR_ELT(ret, i, mkCharLen(buf, buflen));
  }
  
  free(buf);
  
  R_END;
  return ret;
}

RNACI_FUNTYPE SEXP make_dataframe_default_rownames(int n)
{
  R_INIT;
  int i;
  SEXP ret_names;
  
  newRvec(ret_names, n, "int");
  
  for(i=0; i<n; i++)
    INT(ret_names,i) = i + 1;
  
  R_END;
  return ret_names;
}

RNACI_FUNTYPE SEXP make_dataframe(SEXP R_rownames, SEXP R_colnames, int n, ...)
{
  R_INIT;
  int i;
  int nrow = 0;
  SEXP R_df;
  SEXP R_default_rownames;
  SEXP R_default_colnames;
  SEXP tmp;
  va_list listPointer;
  
  // Construct list
  newRlist(R_df, n);
  
  va_start(listPointer, n);
  
  for(i=0; i<n; i++)
  {
    tmp = va_arg(listPointer, SEXP);
    
    SET_VECTOR_ELT(R_df, i, tmp);
  }
  
  va_end(listPointer);
  
  // Set names
  set_list_as_df(R_df);
  
  if (is_Rnull(R_rownames))
  {
    if(n)
        nrow = length(VECTOR_ELT(R_df, 0));
    R_default_rownames = make_dataframe_default_rownames(nrow);
    set_df_rownames(R_df, R_default_rownames);
  }
  else
    set_df_rownames(R_df, R_rownames);
  
  if (is_Rnull(R_colnames))
  {
    R_default_colnames = make_dataframe_default_colnames(n);
    set_df_colnames(R_df, R_default_colnames);
  }
  else
    set_df_colnames(R_df, R_colnames);
  
  
  R_END;
  return R_df;
}
