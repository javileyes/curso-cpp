 // Listado 7.3
 // Instrucciones while complejas

 #include <iostream.h>

 int main()
 {
	 unsigned short chico;
	 unsigned long grande;
	 const unsigned short MAXCHICO=65535;

	 cout << "Escriba un n�mero chico: ";
	 cin >> chico;
	 cout << "Escriba un n�mero grande: ";
	 cin >> grande;

	 cout << "chico: " << chico << "...";

	 // para cada iteraci�n, evaluar tres condiciones
	 while (chico < grande && grande > 0 && chico < MAXCHICO)
	 {
		 if (chico % 5000 == 0) // escribir un punto cada 5 mil l�neas
		 cout << ".";

		 chico++;

		 grande-=2;
	 }

	 cout << "\nChico: " << chico << " Grande: " << grande << endl;
	 return 0;
 }
