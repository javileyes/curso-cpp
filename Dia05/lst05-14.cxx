lst05-11.o: lst05-11.cxx lst05-11.h
	g++ -c lst05-11.cxx
#
lst05-12: lst05-12.cxx lst05-11.o lst05-11.h
	g++ lst05-12.cxx lst05-11.o -o lst05-12
