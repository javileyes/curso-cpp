 // Listado 4.5 - muestra el uso de la instrucci�n if
 // con los operadores relacionales
 #include <iostream.h>
 int main()
 {
	 int CarrerasMediasRojas, CarrerasYanquis;
	 cout << "Escriba las carreras anotadas por los Medias rojas: ";
	 cin >> CarrerasMediasRojas;

	 cout << "\nEscriba las carreras anotadas por los Yanquis: ";
	 cin >> CarrerasYanquis;

	 cout << "\n";

	 if (CarrerasMediasRojas > CarrerasYanquis)
		 cout << "�Vamos, Medias rojas!\n";

	 if (CarrerasMediasRojas < CarrerasYanquis)
	 {
		 cout << "�Vamos, Yanquis!\n";
		 cout << "�Son d�as felices en Nueva York!\n";
	 }

	 if (CarrerasMediasRojas == CarrerasYanquis)
	 {
		 cout << "�Un empate? Nooo, no puede ser.\n";
		 cout << "Escriba las carreras que anotaron realmente los Yanquis: ";
		 cin >> CarrerasYanquis;

		 if (CarrerasMediasRojas > CarrerasYanquis)
			 cout << "�Lo sab�a! �Vamos, Medias rojas!";

		 if (CarrerasYanquis > CarrerasMediasRojas)
			 cout << "�Lo sab�a! �Vamos, Yanquis!";

		 if (CarrerasYanquis == CarrerasMediasRojas)
			 cout << "�Vaya! �Realmente fue un empate!";
	 }

	 cout << "\nGracias por dec�rmelo.\n";
	 return 0;
 }
