 //Listado 7.14
 //Muestra de ciclos for anidados

 #include <iostream.h>

 int main()
 {
	 int filas, columnas;
	 char elCaracter;

	 cout << "¿Cuántas filas? ";
	 cin >> filas;
	 cout << "¿Cuántas columnas? ";
	 cin >> columnas;
	 cout << "¿Cuál carácter? ";
	 cin >> elCaracter;
	 for (int i = 0; i<filas; i++)
	 {
		 for (int j = 0; j<columnas; j++)
			 cout << elCaracter;
		 cout << "\n";
	 }
	 return 0;
 }
