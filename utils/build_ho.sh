#!/bin/sh

ROOTDIR="../"
OUTDIR="${ROOTDIR}/build/headeronly/"


if [ -d $OUTDIR ]; then
  rm -rf $OUTDIR
fi

mkdir $OUTDIR

OUTFILE="${OUTDIR}/RNACI.h"

echo -e "// NOTE: file generated automatically from RNACI source; do not edit by hand\n\n" >> $OUTFILE

cat files/license.txt > $OUTFILE

echo "#ifndef __RNACI_H__" >> $OUTFILE
echo "#define __RNACI_H__" >> $OUTFILE
echo -e "\n\n" >> $OUTFILE

cat "${ROOTDIR}/src/build_type.h" | sed -e "s/SETME/1" >> $OUTFILE

cat "${ROOTDIR}/src/API.h"

echo -e "\n\n" >> $OUTFILE
echo "/***************************************************" >> $OUTFILE
echo " * Definitions *" >> $OUTFILE
echo " ***************************************************/" >> $OUTFILE
echo -e "\n\n" >> $OUTFILE

for f in `ls ${ROOTDIR}/src/*.c`; do
  echo "// $f"
  cat $f >> $OUTFILE
done

echo -e "\n\n" >> $OUTFILE
echo "#endif" >> $OUTFILE
