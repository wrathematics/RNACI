#!/bin/sh

PKGVER=`grep "Version:" ../../DESCRIPTION | sed -e "s/Version: //"`
sed -i -e "s/thispackageversion}{.*}/thispackageversion}{${PKGVER}}/" cover.tex

xelatex cover.tex
xelatex cover.tex
Rscript -e "tools::compactPDF('cover.pdf', gs_quality='ebook')"
rm *.aux *.bbl *.blg *.log *.out *.toc *.idx *.lof *.lot *.ind *.ilg *.dvi
