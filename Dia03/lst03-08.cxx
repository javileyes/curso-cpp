 #include <iostream>
 using namespace std;

 int main()
 {
	 const int Domingo = 0;
	 const int Lunes = 1;
	 const int Martes = 2;
	 const int Miercoles = 3;
	 const int Jueves = 4;
	 const int Viernes = 5;
	 const int Sabado = 6;

	 int opcion;
	 cout << "Escriba un día (0-6): ";
	 cin >> opcion;

	 if (opcion == Domingo || opcion == Sabado)
		 cout << "\n¡Ya se le agotaron los fines de semana!\n";
	 else
		 cout << "\nEstá bien, incluirá un día de descanso.\n";

	 return 0;
 }
