 // Listado 5.9 - muestra las funciones en línea

 #include <iostream.h>

 inline int Duplicar(int);

 int main()
 {
	 int numero;

	 cout << "Escriba un número con el que quiera trabajar: ";
	 cin >> numero;
	 cout << "\n";

	 numero = Duplicar(numero);
	 cout << "Número: " << numero << endl;

	 numero = Duplicar(numero);
	 cout << "Número: " << numero << endl;


	 numero = Duplicar(numero);
	 cout << "Número: " << numero << endl;
	 return 0;
 }

 int Duplicar(int numero)
 {
	 return numero * 2;
 }
