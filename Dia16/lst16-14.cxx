 // Listing 16.14 - Uso de setf()
 #include <iostream.h>
 #include <iomanip.h>
 
 int main()
 {
 	const int numero = 185;
 
 	cout << "El número es " << numero << endl;
	 
	cout << "El número es " << hex << numero << endl;
	 
	cout.setf(ios::showbase);
	cout << "El número es " << hex << numero << endl;
	 
	cout << "El número es " ;
	cout.width(10);
	cout << hex << numero << endl;
	 
	cout << "El número es " ;
	cout.width(10);
	cout.setf(ios::left);
	cout << hex << numero << endl;
	 
	cout << "El número es " ;
	cout.width(10);
	cout.setf(ios::internal);
	cout << hex << numero << endl;
	 
	cout << "El número es:" << setw(10) << hex << numero << endl;
 	return 0;
 }
