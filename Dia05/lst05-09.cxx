 // Listado 5.9 - muestra las funciones en l�nea

 #include <iostream.h>

 inline int Duplicar(int);

 int main()
 {
	 int numero;

	 cout << "Escriba un n�mero con el que quiera trabajar: ";
	 cin >> numero;
	 cout << "\n";

	 numero = Duplicar(numero);
	 cout << "N�mero: " << numero << endl;

	 numero = Duplicar(numero);
	 cout << "N�mero: " << numero << endl;


	 numero = Duplicar(numero);
	 cout << "N�mero: " << numero << endl;
	 return 0;
 }

 int Duplicar(int numero)
 {
	 return numero * 2;
 }
