 // Listado 4.5 - muestra el uso de la instrucción if
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
		 cout << "¡Vamos, Medias rojas!\n";

	 if (CarrerasMediasRojas < CarrerasYanquis)
	 {
		 cout << "¡Vamos, Yanquis!\n";
		 cout << "¡Son días felices en Nueva York!\n";
	 }

	 if (CarrerasMediasRojas == CarrerasYanquis)
	 {
		 cout << "¿Un empate? Nooo, no puede ser.\n";
		 cout << "Escriba las carreras que anotaron realmente los Yanquis: ";
		 cin >> CarrerasYanquis;

		 if (CarrerasMediasRojas > CarrerasYanquis)
			 cout << "¡Lo sabía! ¡Vamos, Medias rojas!";

		 if (CarrerasYanquis > CarrerasMediasRojas)
			 cout << "¡Lo sabía! ¡Vamos, Yanquis!";

		 if (CarrerasYanquis == CarrerasMediasRojas)
			 cout << "¡Vaya! ¡Realmente fue un empate!";
	 }

	 cout << "\nGracias por decírmelo.\n";
	 return 0;
 }
