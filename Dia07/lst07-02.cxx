 // Listado 7.2
 // Uso de ciclos con while

 #include <iostream.h>

 int main()
 {
	 int contador = 0; // inicializar la condici�n 

	 while(contador < 5) // evaluar que la condici�n a�n sea verdadera 
	 {
		 contador++; // cuerpo del ciclo 
		 cout << "contador: " << contador << "\n";
	 }

	 cout << "Completo. Contador: " << contador << ".\n";
	 return 0;
 }
