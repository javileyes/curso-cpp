 // *****************
 // Muestra de la palabra reservada typedef
 #include <iostream>
 using namespace std;

 typedef unsigned short int USHORT; //typedef definido

 int main()
 {
 	USHORT Ancho = 5;
 	USHORT Longitud;
 	Longitud = 10;
 	USHORT Area = Ancho * Longitud;
	cout << "Ancho:" << Ancho << "\n";
	cout << "Longitud: " << Longitud << endl;
	cout << "Area: " << Area <<endl;
	return 0;
 }
