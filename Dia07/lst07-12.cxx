 //Listado 7.12 muestra de una
 //instrucci�n de ciclo for con encabezado vac�o

 #include <iostream.h>

 int main()
 {
	 int contador=0; // inicializaci�n
	 int max;
	 cout << "�Cu�ntos holas?: ";
	 cin >> max;
	 for (;;) // un ciclo for que no termina
	 {
		 if (contador < max) // prueba
		 {
			 cout << "�Hola!\n";
			 contador++; // incremento
	 	 }
		 else
			 break;
	 }
	 return 0;
 }
