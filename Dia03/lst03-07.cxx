 #include <iostream>
 using namespace std;

 int main()
 {
	enum Dias { Domingo, Lunes, Martes,
		    Miercoles, Jueves, Viernes, Sabado };
	 int opcion;
	 cout << "Escriba un día (0-6): ";
	 cin >> opcion;
	 if (opcion == Domingo || opcion == Sabado)
		 cout << "\n¡Ya se le agotaron los fines de semana!\n";
	 else
		 cout << "\nEstá bien, incluirá un día de descanso.\n";
	 return 0;
 }
