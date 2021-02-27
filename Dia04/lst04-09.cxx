 // Listado 4.9 - muestra el uso apropiado de las llaves
 // en instrucciones if anidadas
 #include <iostream.h>
 int main()
 {
	 int x;
	 cout << "Escriba un número menor que 10 o mayor que 100: ";
	 cin >> x;
	 cout << "\n";

	 if (x >= 10)
	 {
		 if (x > 100)
			 cout << "Mayor que 100, ¡gracias!\n";
	 }
	 else // arreglado!
		 cout << "Menor que 10, ¡gracias!\n";
	 return 0;
 }
