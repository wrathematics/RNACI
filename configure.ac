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

AC_OUTPUT(src/Makevars)

