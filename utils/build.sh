#!/bin/sh

export PROJROOT="../"
export OUTDIR="${PROJROOT}/build/regular/"

echo -n "Building regular..."

COMMENT_FILE(){
  cat $1 | sed -e 's/^/\/\/ /' >> $OUTFILE
}

ECHO_FILE(){
  echo -e $1 >> $OUTFILE
}

CAT_FILE(){
  cat $1 | sed -e "s/RNACI_FUNTYPE//g" >> $OUTFILE
}

if [ -d $OUTDIR ]; then
  rm -rf $OUTDIR
fi

mkdir $OUTDIR

OUTFILE_H="${OUTDIR}/RNACI.h"
sed -e "s/RNACI_FUNTYPE//g" < "${PROJROOT}/src/API.h" >> ${OUTFILE_H}

OUTFILE="${OUTDIR}/RNACI.c"

ECHO_FILE "// NOTE: file generated automatically from RNACI source; do not edit by hand\n" OUTFILE

COMMENT_FILE "${PROJROOT}/LICENSE.md"
ECHO_FILE "\n// Changelog:"
COMMENT_FILE "${PROJROOT}/ChangeLog"
ECHO_FILE "\n\n"

ECHO_FILE "#include \"RNACI.h\"\n"

ECHO_FILE "unsigned int RNACI_ptct = 0;\n\n"

for f in `ls ${PROJROOT}/src/*.c`; do
  ECHO_FILE "// ${f}"
  CAT_FILE $f
  ECHO_FILE "\n\n"
done


echo "DONE!"
