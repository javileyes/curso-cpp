 //Listado 16.1 - cadenas de caracteres y cin
	 
 #include <iostream.h>
	 
	 
 int main()
 {
 	int miInt;
 	long miLong;
 	double miDouble;
 	float miFloat;
 	unsigned int miUnsigned;
 
 	cout << "int: ";
 	cin >> miInt;
 	cout << "Long: ";
 	cin >> miLong;
 	cout << "Double: ";
 	cin >> miDouble;
 	cout << "Float: ";
 	cin >> miFloat;
 	cout << "Unsigned: ";
 	cin >> miUnsigned;
	 
 	cout << "\n\nInt:\t" << miInt << endl;
 	cout << "Long:\t" << miLong << endl;
 	cout << "Double:\t" << miDouble << endl;
 	cout << "Float:\t" << miFloat << endl;
 	cout << "Unsigned:\t" << miUnsigned << endl;
 	return 0;
 }

