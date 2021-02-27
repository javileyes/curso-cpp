 // Listado 16.13 - Uso de fill()
 #include <iostream.h>
	 
 int main()
 {
 	cout << "Inicio >";
 	cout.width(25);
 	cout << 123 << "< Fin\n";
	 
	cout << "Inicio >";
	cout.width(25);
	cout.fill('*');
	cout << 123 << "< Fin\n";
 	return 0;
 }
