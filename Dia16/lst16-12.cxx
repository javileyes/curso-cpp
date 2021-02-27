 // Listado 16.12 - Ajuste del ancho de la salida
 #include <iostream.h>
	 
 int main()
 {
 	cout << "Inicio >";
 	cout.width(25);
 	cout << 123 << "< Fin\n";
	 
	cout << "Inicio >";
	cout.width(25);
	cout << 123<< "< Siguiente >";
	cout << 456 << "< Fin\n";
	 
	cout << "Inicio >";
	cout.width(4);
	cout << 123456 << "< Fin\n";
 	return 0;
 }
