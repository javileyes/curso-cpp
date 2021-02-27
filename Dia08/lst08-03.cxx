 // Listado 8.3 Qué se guarda en un apuntador.
 
 #include <iostream.h>
 
 int main()
 {
	 unsigned short int miEdad = 5, suEdad = 10;
	 unsigned short int * apEdad = &miEdad; // un apuntador
	 
	 cout << "miEdad:\t" << miEdad
	      << "\tsuEdad:\t" << suEdad << "\n";
	 cout << "&miEdad:\t" << &miEdad
	      << "\t&suEdad:\t" << &suEdad <<"\n";
	 cout << "apEdad:\t" << apEdad << "\n";
	 cout << "*apEdad:\t" << *apEdad << "\n";
	 // reasignar el apuntador
	 apEdad = &suEdad;
	 cout << "miEdad:\t" << miEdad 
	      << "\tsuEdad:\t" << suEdad << "\n";
	 cout << "&miEdad:\t" << &miEdad 
	      << "\t&suEdad:\t" << &suEdad <<"\n";
	 cout << "apEdad:\t" << apEdad << "\n";
	 cout << "*apEdad:\t" << *apEdad << "\n";
	 cout << "&apEdad:\t" << &apEdad << "\n";
	 return 0;
 }
