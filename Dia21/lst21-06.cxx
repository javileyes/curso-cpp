 // Listado 21.6 - Impresión de valores en modo DEPURAR

 #include <iostream.h>
 #define DEPURAR

 #ifndef DEPURAR
   #define IMPRIMIR(x)
 #else
   #define IMPRIMIR(x) 	cout << #x << ":\t" << x << endl;
 #endif

 // enum bool { FALSE, TRUE } ;


 int main()
 {
	 int x = 5;
	 long y = 73898l;
	
	 IMPRIMIR(x);
	 for (int i = 0; i < x; i++)
	 {
		 IMPRIMIR(i);
	 }
	 IMPRIMIR(y);
	 IMPRIMIR("Hola.");
	 int *apx = &x;
	 IMPRIMIR(apx);
	 IMPRIMIR(*apx);
	 return 0;
 }
