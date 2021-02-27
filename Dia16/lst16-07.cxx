 // Listado 16.7 - Uso de getline()
 #include <iostream.h>
	 
 int main()
 {
 	char cadenaUno[ 256 ];
 	char cadenaDos[ 256 ];
 	char cadenaTres[ 256 ];
	 
	cout << "Escriba la cadena uno: ";
	cin.getline(cadenaUno, 256);
	cout << "cadenaUno: " << cadenaUno << endl;
	cout << "Escriba la cadena dos: ";
	cin >> cadenaDos;
	cout << "cadenaDos: " << cadenaDos << endl;
	cout << "Escriba la cadena tres: ";
	cin.getline(cadenaTres, 256);
	cout << "cadenaTres: " << cadenaTres << endl;
	 return 0;
 }
