 #include <iostream.h>
 int main()
 {
	enum Dias { Domingo, Lunes, Martes,
		    Miercoles, Jueves, Viernes, Sabado };
	 int opcion;
	 cout << "Escriba un d�a (0-6): ";
	 cin >> opcion;
	 if (opcion == Domingo || opcion == Sabado)
		 cout << "\n�Ya se le agotaron los fines de semana!\n";
	 else
		 cout << "\nEst� bien, incluir� un d�a de descanso.\n";
	 return 0;
 }
