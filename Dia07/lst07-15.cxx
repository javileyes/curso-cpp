 // Listado 7.15
 // Muestra de la solución del enésimo 
 // número de Fibonacci por medio de la iteración

 #include <iostream.h>

 int fib(int posicion);

 int main()
 {
	 int respuesta, posicion;
	 cout << "¿Cuál posición?: ";
	 cin >> posicion;
	 cout << "\n";
	 respuesta = fib(posicion);
	 cout << respuesta << " es el número ";
	 cout << posicion << " de la serie de Fibonacci.\n";
	 return 0;
 }

 int fib(int n)
 {
	 int menosDos=1, menosUno=1, respuesta=2;

	 if (n < 3)
		 return 1;
	 for (n -= 3; n; n--)
	 {
		 menosDos = menosUno;
		 menosUno = respuesta;
		 respuesta = menosUno + menosDos;
	 }
	 return respuesta;
 }
