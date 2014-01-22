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

R_SCMD="${R_HOME}/bin/Rscript -e"


# Set EXT_LDFLAGS, otherwise default LDFLAGS, OBJS, and LIBS will be set.
AC_ARG_VAR(EXT_LDFLAGS, [ external linking flags of external libraries ])
AS_VAR_SET_IF(EXT_LDFLAGS, [], [ AS_VAR_SET(EXT_LDFLAGS, "") ])
if test "X$EXT_LDFLAGS" = "X" ; then
  EXT_OBJS="\$(R_SEXPTOOLS)"
  EXT_LIBS="userLibrary"
else
  EXT_OBJS=""
  EXT_LIBS=""
fi


# Report
echo " "
echo "****************** Results of SEXPtools package configure *****************"
echo " "
echo ">> EXT_OBJS = ${EXT_OBJS}"
echo ">> EXT_LIBS = ${EXT_LIBS}"
echo " "
echo "*************************************************************************"
echo " "


# Substitute
AC_SUBST(EXT_LIBS)
AC_OUTPUT(src/Makevars)

