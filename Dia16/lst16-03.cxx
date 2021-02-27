 //Listado 16.3 - Cadenas de caracteres y cin
 
 #include <iostream.h>
 
 
 int main()
 {
 	int miInt;
 	long miLong;
	double miDouble;
	float miFloat;
	unsigned int miUnsigned;
	char miPalabra[ 50 ];
 
	cout << "int: ";
	cin >> miInt;
	cout << "Long: ";
	cin >> miLong;
	cout << "Double: ";
	cin >> miDouble;
	cout << "Float: ";
	cin >> miFloat;
	cout << "Palabra: ";
	cin >> miPalabra;
	cout << "Unsigned: ";
	cin >> miUnsigned;
	 
	cout << "\n\nInt:\t" << miInt << endl;
	cout << "Long:\t" << miLong << endl;
	cout << "Double:\t" << miDouble << endl;
	cout << "Float:\t" << miFloat << endl;
	cout << "Palabra:\t" << miPalabra << endl;
	cout << "Unsigned:\t" << miUnsigned << endl;
	cout << "\n\nInt, Long, Double, Float, Palabra, Unsigned: ";
	 
	cin >> miInt >> miLong >> miDouble;
	cin >> miFloat >> miPalabra >> miUnsigned;
	cout << "\n\nInt:\t" << miInt << endl;
	cout << "Long:\t" << miLong << endl;
	cout << "Double:\t" << miDouble << endl;
	cout << "Float:\t" << miFloat << endl;
	cout << "Palabra:\t" << miPalabra << endl;
	cout << "Unsigned:\t" << miUnsigned << endl;
	 return 0;
 }

