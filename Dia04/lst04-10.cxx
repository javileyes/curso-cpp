 // Listado 4.10 - Muestra el uso del operador condicional
 //
 #include <iostream.h>
 int main()
 {
	 int x, y, z;
	 cout << "Escriba dos números.\n";
	 cout << "Primero: ";
	 cin >> x;
	 cout << "\nSegundo: ";
	 cin >> y;
	 cout << "\n";

	 if (x > y)
		 z = x;
	 else
		 z = y;

 	 cout << "z: " << z;
	 cout << "\n";

	 z = (x > y) ? x : y;

	 cout << "z: " << z;
	 cout << "\n";
	 return 0;
 }
