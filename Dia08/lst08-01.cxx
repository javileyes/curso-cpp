 // Listado 8.1 Muestra del operador de dirección, 
 // y de direcciones de variables locales 
 
 #include <iostream.h>
 
 int main()
 {
	 unsigned short shortVar = 5;
	 unsigned long longVar = 65535;
	 long sVar = -65535;
	 
	 cout << "Variable de tipo short sin signo:\t";
	 cout << shortVar << "\n";
	 cout << "Dirección de variable de tipo short:\t";
	 cout << &shortVar << "\n";
	 
	 cout << "Variable de tipo long sin signo:\t";
	 cout << longVar << "\n";
	 cout << "Dirección de variable de tipo long:\t" ;
	 cout << &longVar << "\n";
	 
	 cout << "Variable de tipo long con signo:\t";
	 cout << sVar << "\n";
	 cout << "Dirección de variable de tipo long con signo:\t" ;
	 cout << &sVar << "\n";
	 
	 return 0;
 }
