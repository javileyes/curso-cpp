 #include <iostream.h>
 #include "lst05-11.h"
 // Listado 5.12 - Una muestra del uso de bibliotecas

 int main()
 {

	 int n, respuesta;
	 cout << "Escriba el número a encontrar: "; 
	 cin >> n;
	 cout << "\n\n";

	 respuesta = fib(n);
	 cout << respuesta << " es el número " << n << " en la serie de Fibonacci\n";
	 return 0;
 }
