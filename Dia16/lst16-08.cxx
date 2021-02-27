 // Listado 16.8 - Uso de ignore()
 #include <iostream.h>
 
 int main()
 {
 	char cadenaUno[ 255 ];
 	char cadenaDos[ 255 ];
	 
 	cout << "Escriba la cadena uno:";
	cin.get(cadenaUno, 255);
	cout << "Cadena uno: " << cadenaUno << endl;
	cout << "Escriba la cadena dos: ";
	cin.getline(cadenaDos, 255);
	cout << "Cadena dos: " << cadenaDos << endl;
	cout << "\n\nAhora intente de nuevo...\n";
	cout << "Escriba la cadena uno: ";
	cin.get(cadenaUno, 255);
	cout << "Cadena uno: " << cadenaUno<< endl;
	cin.ignore(255, '\n');
	cout << "Escriba la cadena dos: ";
	cin.getline(cadenaDos, 255);
	cout << "Cadena dos: " << cadenaDos<< endl;
	return 0;
 }
