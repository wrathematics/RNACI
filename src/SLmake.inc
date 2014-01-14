CDEFS = 
PKG_CPPFLAGS = 
PKG_CFLAGS = -w
PKG_FFLAGS = 
R_SEXPtools = libsexptools.a
include /usr/lib/R/etc/Makeconf

CCFLAGS = $(ALL_CPPFLAGS) $(ALL_CFLAGS) -O3 -w
FCFLAGS = $(ALL_CPPFLAGS) $(ALL_FFLAGS) -O3 -w
ARCH = $(AR)
ARCHFLAGS = cr
# ARCHFLAGS = -rucs

SEXPTOOLSLIB = $(R_SEXPtools) 

