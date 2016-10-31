all: headeronlysrc regularsrc

builddir:
	mkdir -p build/

headeronlysrc: builddir
	./utils/build_ho.sh

regularsrc: builddir
	cd utils && ./build.sh

Rpackage: regularsrc
	cp build/regular/* Rpkg/src/ && R CMD INSTALL Rpkg


clean:
	rm -rf build/*
