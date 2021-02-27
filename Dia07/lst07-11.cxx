 // Listado 7.11
 // Ciclos for con instrucciones nulas

 #include <iostream.h>

 int main()
 {
	 int contador = 0;

	 for( ; contador < 5; )
	 {
		 contador++;
		 cout << "¡Haciendo un ciclo! ";
	 }
	 cout << "\nContador: " << contador << ".\n";
	 return 0;
 }
