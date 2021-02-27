Lst05-11.o: Lst05-11.cxx Lst05-11.h
	g++ -c Lst05-11.cxx
#
Lst05-12: Lst05-12.cxx Lst05-11.o Lst05-11.h
	g++ Lst05-13.cxx Lst05-11.o -o Lst05-12
