 // Listado 4.6 - muestra el uso de la instrucci�n if
 // con la cl�usula else
 #include <iostream.h>
 int main()
 {
	 int primerNumero, segundoNumero;
	 cout << "Escriba un n�mero grande: ";
	 cin >> primerNumero;
	 cout << "\nEscriba un n�mero m�s peque�o: ";
	 cin >> segundoNumero;
	 if (primerNumero >= segundoNumero)
		 cout << "\n�Gracias!\n";
	 else
		 cout << "\nOh. �El segundo es m�s grande!\n";

	 return 0;
 }
