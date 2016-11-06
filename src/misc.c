RNACI_FUNTYPE int is_Rnull(SEXP x)
{
  SEXP basePackage;
  SEXP tmp;
  
  RNACI_PT( basePackage = eval( lang2( install("getNamespace"), ScalarString(mkChar("base")) ), R_GlobalEnv ) );
  
  tmp = eval( lang2( install("is.null"), x), basePackage);
  
  UNPROTECT(1);
  return INT(tmp);
}

RNACI_FUNTYPE int is_Rnan(SEXP x)
{
  SEXP basePackage;
  SEXP tmp;

  RNACI_PT( basePackage = eval( lang2( install("getNamespace"), ScalarString(mkChar("base")) ), R_GlobalEnv ) );

  tmp = eval( lang2( install("is.nan"), x), basePackage);

  UNPROTECT(1);
  return INT(tmp);
}

RNACI_FUNTYPE int is_Rna(SEXP x)
{
  SEXP basePackage;
  SEXP tmp;
  
  RNACI_PT( basePackage = eval( lang2( install("getNamespace"), ScalarString(mkChar("base")) ), R_GlobalEnv ) );
  
  tmp = eval( lang2( install("is.na"), x), basePackage);
  
  UNPROTECT(1);
  return INT(tmp);
}

RNACI_FUNTYPE int is_double(SEXP x)
{
  SEXP basePackage;
  SEXP tmp;
  
  RNACI_PT( basePackage = eval( lang2( install("getNamespace"), ScalarString(mkChar("base")) ), R_GlobalEnv ) );
  
  tmp = eval( lang2( install("is.double"), x), basePackage);
  
  UNPROTECT(1);
  return INT(tmp);
}

RNACI_FUNTYPE int is_integer(SEXP x)
{
  SEXP basePackage;
  SEXP tmp;
  
  RNACI_PT( basePackage = eval( lang2( install("getNamespace"), ScalarString(mkChar("base")) ), R_GlobalEnv ) );
  
  tmp = eval( lang2( install("is.integer"), x), basePackage);
  
  UNPROTECT(1);
  return INT(tmp);
}
