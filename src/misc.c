RNACI_FUNTYPE int is_Rnull(SEXP x)
{
  R_INIT;
  SEXP basePackage;
  SEXP tmp;
  
  PT( basePackage = eval( lang2( install("getNamespace"), ScalarString(mkChar("base")) ), R_GlobalEnv ) );
  
  tmp = eval( lang2( install("is.null"), x), basePackage);
  
  R_END;
  return INT(tmp,0);
}



RNACI_FUNTYPE int is_Rnan(SEXP x)
{
  R_INIT;
  SEXP basePackage;
  SEXP tmp;

  PT( basePackage = eval( lang2( install("getNamespace"), ScalarString(mkChar("base")) ), R_GlobalEnv ) );

  tmp = eval( lang2( install("is.nan"), x), basePackage);

  R_END;
  return INT(tmp,0);
}



RNACI_FUNTYPE int is_Rna(SEXP x)
{
  R_INIT;
  SEXP basePackage;
  SEXP tmp;
  
  PT( basePackage = eval( lang2( install("getNamespace"), ScalarString(mkChar("base")) ), R_GlobalEnv ) );
  
  tmp = eval( lang2( install("is.na"), x), basePackage);
  
  R_END;
  return INT(tmp,0);
}



RNACI_FUNTYPE int is_double(SEXP x)
{
  R_INIT;
  SEXP basePackage;
  SEXP tmp;
  
  PT( basePackage = eval( lang2( install("getNamespace"), ScalarString(mkChar("base")) ), R_GlobalEnv ) );
  
  tmp = eval( lang2( install("is.double"), x), basePackage);
  
  R_END;
  return INT(tmp,0);
}



RNACI_FUNTYPE int is_integer(SEXP x)
{
  R_INIT;
  SEXP basePackage;
  SEXP tmp;
  
  PT( basePackage = eval( lang2( install("getNamespace"), ScalarString(mkChar("base")) ), R_GlobalEnv ) );
  
  tmp = eval( lang2( install("is.integer"), x), basePackage);
  
  R_END;
  return INT(tmp,0);
}
