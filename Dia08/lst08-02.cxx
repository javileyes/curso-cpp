 // Listado 8.2 Uso de apuntadores
 
 #include <iostream.h>
 
 typedef unsigned short int USHORT;
 int main()
 {
	 USHORT miEdad; // una variable
	 USHORT * apEdad = NULL; // un apuntador
	 
	 miEdad = 5;
	 cout << "miEdad: " << miEdad << "\n";
	 // asignar dirección de miEdad a apEdad
	 apEdad = &miEdad; 
	 cout << "*apEdad: " << *apEdad << "\n\n";
	 cout << "*apEdad = 7\n";
	 // asigna el valor 7 a miEdad 
	 *apEdad = 7;
	 cout << "*apEdad: " << *apEdad << "\n";
	 cout << "miEdad: " << miEdad << "\n\n";
	 cout << "miEdad = 9\n";
	 miEdad = 9;
	 cout << "miEdad: " << miEdad << "\n";
	 cout << "*apEdad: " << *apEdad << "\n";
	 
	 return 0;
 }
