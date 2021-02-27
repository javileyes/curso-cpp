 //Listado 12.1 - Arreglos

 #include <iostream.h>

 int main()
 {
	 int miArreglo[ 5 ];
	 int i;
	
	 for (i = 0; i < 5; i++ ) // 0-4
	 {
		 cout << "Valor para miArreglo[" << i << "]: ";
		 cin >> miArreglo[ i ];
	 }
	 for (i = 0; i < 5; i++ )
		 cout << i << ": " << miArreglo[i] << "\n";
	 return 0;
 }
