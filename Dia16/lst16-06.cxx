 // Listado 16.6 - Uso de get() con un arreglo de caracteres
 #include <iostream.h>
	 
 int main()
 {
 	char cadenaUno[ 256 ];
 	char cadenaDos[ 256 ];
	 
 	cout << "Escriba la cadena uno: ";
	cin.get(cadenaUno, 256);
	cout << "cadenaUno: " << cadenaUno << endl;
	cout << "Escriba la cadena dos: ";
	cin >> cadenaDos;
	cout << "CadenaDos: " << cadenaDos << endl;
	 return 0;
 }
