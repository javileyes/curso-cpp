 // Listado 4.4 - muestra el uso de
 // los operadores de incremento de
 // prefijo y posfijo
 #include <iostream.h>
 int main()
 {
 	 int miEdad = 39; // inicializar dos variables de tipo entero
	 int suEdad = 39;
	 cout << "Yo tengo: " << miEdad << " a�os.\n";
	 cout << "Usted tiene: " << suEdad << " a�os \n";
	 miEdad++; // incremento mediante posfijo
	 ++suEdad; // incremento mediante prefijo
	 cout << "Pasa un a�o...\n";
	 cout << "Ahora tengo: " << miEdad << " a�os.\n";
	 cout << "Usted tiene: " << suEdad << " a�os\n";
	 cout << "Pasa otro a�o\n";
	 cout << "Ahora tengo: " << miEdad++ << " a�os.\n";
	 cout << "Usted tiene: " << ++suEdad << " a�os\n";
	 cout << "Imprimamos eso de nuevo.\n";
	 cout << "Yo tengo: " << miEdad << " a�os.\n";
	 cout << "Usted tiene: " << suEdad << " a�os\n";
	 return 0;
 }
