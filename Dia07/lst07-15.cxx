 // Listado 7.15
 // Muestra de la soluci�n del en�simo 
 // n�mero de Fibonacci por medio de la iteraci�n

 #include <iostream.h>

 int fib(int posicion);

 int main()
 {
	 int respuesta, posicion;
	 cout << "�Cu�l posici�n?: ";
	 cin >> posicion;
	 cout << "\n";
	 respuesta = fib(posicion);
	 cout << respuesta << " es el n�mero ";
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
