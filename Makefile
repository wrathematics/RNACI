all: clean headeronlysrc regularsrc Rpackage

builddir:
	mkdir -p build/

headeronlysrc: builddir
	cd utils && ./build_ho.sh

regularsrc: builddir
	cd utils && ./build.sh

Rpackage: cleanup headeronlysrc
	cp build/headeronly/RNACI.h Rpkg/src/ && R CMD INSTALL Rpkg



cleanup:
	cd Rpkg && ./cleanup

cleansrc:
	rm -rf build/*

clean: cleanup cleansrc
