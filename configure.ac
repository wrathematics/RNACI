## autoconf configure.ac && autoreconf -if

AC_PREREQ([2.69])
AC_INIT([Rtools], [0.1])
AC_CONFIG_SRCDIR([src/SEXPtools/printing.c])

# Checks for programs.
AC_PROG_CC

: ${R_HOME=‘R RHOME‘}
if test -z "${R_HOME}"; then
  echo "could not determine R_HOME"
  exit 1
fi

dnl Set EXT_LDFLAGS, otherwise default LDFLAGS, OBJS, and LIBS will be set.
AC_ARG_VAR(EXT_LDFLAGS, [ external linking flags of external libraries ])
AS_VAR_SET_IF(EXT_LDFLAGS, [], [ AS_VAR_SET(EXT_LDFLAGS, "") ])
if test "X$EXT_LDFLAGS" = "X" ; then
  EXT_LDFLAGS="\$(LAPACK_LIBS) \$(BLAS_LIBS)"
  EXT_OBJS="\$(R_SEXPtools)"
  EXT_LIBS="userLibrary"
else
  EXT_OBJS=""
  EXT_LIBS=""
fi

echo " "
echo "****************** Results of pbdSLAP package configure *****************"
echo " "
echo ">> EXT_LDFLAGS = ${EXT_LDFLAGS}"
echo ">> EXT_OBJS = ${EXT_OBJS}"
echo ">> EXT_LIBS = ${EXT_LIBS}"
echo ">> CDEFS = ${CDEFS}"
echo ">> CDEFS_CHECK = ${CDEFS_CHECK}"
echo ">> SPMD_CPPFLAGS = ${SPMD_CPPFLAGS}"
echo ">> SPMD_LDFLAGS = ${SPMD_LDFLAGS}"
echo " "
echo "*************************************************************************"
echo " "

AC_SUBST(EXT_LIBS)
AC_OUTPUT(src/Makevars)

