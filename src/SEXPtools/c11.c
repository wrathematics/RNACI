// C11 _Generic features

#if __STDC_VERSION__ >= 201112L


#include <stdio.h>

#define TYPE_INT 0
#define TYPE_DBL 1

#define var_type(T) _Generic( (T), \
  int: TYPE_INT, \
  double: TYPE_DBL, \
  default: -1)

int generic_test()
{
  int n;
  long N;
  double x;
  
  printf("%d %d %d\n", type_idx(n), type_idx(N), type_idx(x));
  
  return 0;
}




#endif
