 // Listado 4.8 - muestra por qu� las llaves
 // son importantes en instrucciones if anidadas
 #include <iostream.h>
 int main()
 {
	 int x;
	 cout << "Escriba un n�mero menor que 10 o mayor que 100: ";
	 cin >> x;
	 cout << "\n";

	 if (x >= 10)
		 if (x > 100)
			 cout << "Mayor que 100, �gracias!\n";
		 else // �no es la instrucci�n else que se quiere!
			 cout << "Menor que 10, �gracias!\n";

	 return 0;
 }
