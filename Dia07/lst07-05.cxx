 // Listado 7.5
 // Muestra de un ciclo while (true)

 #include <iostream.h>

 int main()
 {
	 int contador = 0;

	 while (true)
	 {
		 contador ++;
	 if (contador > 10)
		 break;
	 }
	 cout << "Contador: " << contador << "\n";
	 return 0;
 }
