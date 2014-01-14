include ../SLmake.inc


sexptools = 
	SEXPtools/alloc.o \
	SEXPtools/misc.o \
	SEXPtools/printing.o \
	SEXPtools/structures_dataframes.o \
	SEXPtools/structures_lists.o \
	SEXPtools/structures_misc.o


PKG_sexptools = $(sexptools:.o=.oo)


lib : all

$(PKG_sexptools): SEXPtools.h

all : $(PKG_sexptools) 
	$(ARCH) $(ARCHFLAGS) ./$(SEXPTOOLSLIB) \
		$(PKG_sexptools)
	$(RANLIB) ../$(SEXPTOOLSLIB)

#  -----------------------
#  Delete the object files
#  -----------------------
clean :
	rm -f $(PKG_sexptools)


#  ------------------------------------------------------------------------
#  We move C .o files to .oo so that we can use the portable suffix rule for
#  compilation, and still have them coexist with the fortran interface
#  .o files.
#  ------------------------------------------------------------------------
.SUFFIXES: .fo .oo
.c.oo:
	$(CC) -o $*.oo -c $(CDEFS) $(CCFLAGS) -DCallFromC $<
.c.fo:
	$(CC) -o $*.fo -c $(CDEFS) $(CCFLAGS) $<

