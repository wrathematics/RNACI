RNACI_FUNTYPE void PRINT(SEXP x)
{
  SEXP basePackage;
  
  PROTECT( basePackage = eval( lang2( install("getNamespace"), ScalarString(mkChar("base")) ), R_GlobalEnv ) );
  
  eval( lang2( install("print"), x), basePackage);
  
  UNPROTECT(1);
}
