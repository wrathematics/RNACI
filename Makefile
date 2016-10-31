all: headeronlysrc regularsrc

headeronlysrc:
	./utils/build_ho.sh

regularsrc:
	cd utils && ./build.sh

Rpackage: regularsrc
	cp build/regular/* Rpkg/src/ && R CMD INSTALL Rpkg


clean:
	rm -rf build/*
