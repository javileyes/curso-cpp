 //Listado 7.17
 //Uso de un ciclo eterno para manejar 
 //la interacción con el usuario
 #include <iostream.h>

 // prototipos
 int menu();
 void HacerTareaUno();
 void HacerTareaMuchos(int);

 int main()
 {

	 bool salir = false;
	 for (;;)
	 {
		 int opcion = menu();
		 switch(opcion)
		 {
			 case (1):
				 HacerTareaUno();
				 break;
			 case (2):
				 HacerTareaMuchos(2);
				 break;
			 case (3):
				 HacerTareaMuchos(3);
				 break;
			 case (4):
				 continue; // ¡redundante!
				 break;
			 case (5):
				 salir=true;
				 break;
			 default:
				 cout << "¡Seleccione otra vez!\n";
				 break;
		 } // fin de switch

		 if (salir)
		 break;
	 } // fin de ciclo eterno
	 return 0;
 } // fin de main()

 int menu()
 {
	 int opcion;

	 cout << " **** Menú ****\n\n";
	 cout << "(1) Opción uno.\n";
	 cout << "(2) Opción dos.\n";
	 cout << "(3) Opción tres.\n";
	 cout << "(4) Volver a desplegar menú.\n";
	 cout << "(5) Salir.\n\n";
	 cout << ": ";
	 cin >> opcion;
	 return opcion;
 }

 void HacerTareaUno()
 {
	 cout << "¡Tarea Uno!\n";
 }

 void HacerTareaMuchos(int cual)
 {
	 if (cual == 2)
		 cout << "¡Tarea Dos!\n";
	 else
		 cout << "¡Tarea Tres!\n";
 }
