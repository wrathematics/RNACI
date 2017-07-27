static inline SEXP make_dataframe_default_colnames(const int ncols)
{
  int buflen;
  SEXP ret;
  
  if (ncols == 0)
    return RNULL;
  
  buflen = (int) (ceil(log10((double)ncols)) + 1.);
  char *buf = (char*) R_alloc(buflen, sizeof(*buf));
  buf[0] = 'X';
  
  PROTECT(ret = allocVector(VECSXP, ncols));
  
  for (int i=0; i<ncols; i++)
  {
    sprintf(buf+1, "%d", i+1);
    buflen = (int) (ceil(log10((double)i+2)) + 1.);
    buflen = RNACI_MAX(buflen, 2);
    SET_VECTOR_ELT(ret, i, mkCharLen(buf, buflen));
  }
  
  UNPROTECT(1);
  return ret;
}

static inline SEXP make_dataframe_default_rownames(int nrows)
{
  int i;
  SEXP ret_names;
  
  PROTECT(ret_names = allocVector(INTSXP, nrows));
  
  for (i=0; i<nrows; i++)
    INT(ret_names, i) = i + 1;
  
  UNPROTECT(1);
  return ret_names;
}

RNACI_FUNTYPE SEXP _make_dataframe(SEXP R_rownames, SEXP R_colnames, int ncols, ...)
{
  int nrows = 0;
  SEXP R_df;
  SEXP R_default_rownames;
  SEXP R_default_colnames;
  SEXP tmp;
  va_list listPointer;
  
  // Construct list
  PROTECT(R_df = allocVector(VECSXP, ncols));
  
  va_start(listPointer, ncols);
  
  for (int i=0; i<ncols; i++)
  {
    tmp = va_arg(listPointer, SEXP);
    
    SET_VECTOR_ELT(R_df, i, tmp);
  }
  
  va_end(listPointer);
  
  // Set names
  set_list_as_df(R_df);
  
  
  if (R_rownames == RNULL)
  {
    if (ncols)
      nrows = LENGTH(VECTOR_ELT(R_df, 0));
    
    PROTECT(R_default_rownames = make_dataframe_default_rownames(nrows));
    set_df_rownames(R_df, R_default_rownames);
    UNPROTECT(1);
  }
  else
    set_df_rownames(R_df, R_rownames);
  
  
  if (R_colnames == RNULL)
  {
    if (ncols == 0)
    {
      PROTECT(R_default_colnames = make_dataframe_default_rownames(0));
      set_df_colnames(R_df, R_default_colnames);
      UNPROTECT(1);
    }
    else
    {
      R_default_colnames = RNULL;
      set_df_colnames(R_df, R_default_colnames);
    }
  }
  else
    set_df_colnames(R_df, R_colnames);
  
  UNPROTECT(1);
  return R_df;
}
