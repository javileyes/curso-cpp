 //Listado 7.12 muestra de una
 //instrucción de ciclo for con encabezado vacío

 #include <iostream.h>

 int main()
 {
	 int contador=0; // inicialización
	 int max;
	 cout << "¿Cuántos holas?: ";
	 cin >> max;
	 for (;;) // un ciclo for que no termina
	 {
		 if (contador < max) // prueba
		 {
			 cout << "¡Hola!\n";
			 contador++; // incremento
	 	 }
		 else
			 break;
	 }
	 return 0;
 }
