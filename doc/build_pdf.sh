#!/bin/sh

PKGVER=`grep "Version:" ../DESCRIPTION | sed -e "s/Version: //"`
sed -i -e "s/myversion{.*}/myversion{${PKGVER}}/" RNACI-guide.Rnw


fil=`ls | grep "[.]Rnw"`

rm -f *.aux *.bbl *.blg *.log *.out *.toc *.pdf

pdflatex $fil
pdflatex $fil

Rscript -e "tools::compactPDF('.', gs_quality='ebook')"

rm *.aux *.bbl *.blg *.log *.out *.toc *.dvi

mv -f *.pdf ../inst/doc/
cp -f *.Rnw ../inst/doc/
