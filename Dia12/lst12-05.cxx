 // Listado 12.5 Muestra el uso de arreglos 
 // multidimensionales

 #include <iostream.h>

 int main()
 {
	 int UnArreglo[ 5 ][ 2 ] = { {0, 0}, {1, 2}, {2, 4}, {3, 6}, {4, 8} };
	
	 for (int i = 0; i < 5; i++ )
		 for (int j = 0; j < 2; j++ )
		 {
			 cout << "UnArreglo[" << i << "][" << j << "]: ";
			 cout << UnArreglo[ i ][ j ]<< endl;
		 }
	 return 0;
 }
