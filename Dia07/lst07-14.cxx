 //Listado 7.14
 //Muestra de ciclos for anidados

 #include <iostream.h>

 int main()
 {
	 int filas, columnas;
	 char elCaracter;

	 cout << "�Cu�ntas filas? ";
	 cin >> filas;
	 cout << "�Cu�ntas columnas? ";
	 cin >> columnas;
	 cout << "�Cu�l car�cter? ";
	 cin >> elCaracter;
	 for (int i = 0; i<filas; i++)
	 {
		 for (int j = 0; j<columnas; j++)
			 cout << elCaracter;
		 cout << "\n";
	 }
	 return 0;
 }
