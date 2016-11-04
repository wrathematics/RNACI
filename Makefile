all: clean headeronlysrc regularsrc Rpackage

builddir:
	mkdir -p build/

headeronlysrc: builddir
	cd utils && ./build_ho.sh

regularsrc: builddir
	cd utils && ./build.sh


### R package
Rpkg_roxygenize:
	Rscript -e "roxygen2::roxygenize(\"Rpkg/\")"

Rpkg_RNACIze: cleanup headeronlysrc
	cp build/headeronly/RNACI.h Rpkg/src/ 

Rpkg: Rpkg_roxygenize Rpkg_RNACIze
	R CMD INSTALL Rpkg



cleanup:
	cd Rpkg && ./cleanup

cleansrc:
	rm -rf build/*

clean: cleanup cleansrc
