#!/bin/sh

export PROJROOT="../"
export OUTDIR="${PROJROOT}/build/headeronly/"

echo "Building header-only..."

COMMENT_FILE(){
  cat $1 | sed -e 's/^/\/\/ /' >> $OUTFILE
}

ECHO_FILE(){
  echo -e $1 >> $OUTFILE
}

CAT_FILE(){
  cat $1 | sed -e "s/RNACI_FUNTYPE/static inline/g" >> $OUTFILE
}

if [ -d $OUTDIR ]; then
  rm -rf $OUTDIR
fi

mkdir $OUTDIR

OUTFILE="${OUTDIR}/RNACI.h"

ECHO_FILE "// NOTE: file generated automatically from RNACI source; do not edit by hand\n"

COMMENT_FILE "${PROJROOT}/LICENSE.md"
ECHO_FILE "\n// Changelog:"
COMMENT_FILE "${PROJROOT}/ChangeLog"

ECHO_FILE "\n"
ECHO_FILE "#ifndef __RNACI_H__"
ECHO_FILE "#define __RNACI_H__"
ECHO_FILE "\n"

CAT_FILE "${PROJROOT}/src/API.h"

ECHO_FILE "\n\n"
ECHO_FILE "//----------------------------------------------------------------"
ECHO_FILE "// Definitions"
ECHO_FILE "//----------------------------------------------------------------"
ECHO_FILE ""


for f in `ls ${PROJROOT}/src/*.c`; do
  ECHO_FILE "// ${f}"
  CAT_FILE $f
  ECHO_FILE "\n\n"
done

ECHO_FILE "#endif"
