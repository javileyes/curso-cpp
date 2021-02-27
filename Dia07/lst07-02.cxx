 // Listado 7.2
 // Uso de ciclos con while

 #include <iostream.h>

 int main()
 {
	 int contador = 0; // inicializar la condición 

	 while(contador < 5) // evaluar que la condición aún sea verdadera 
	 {
		 contador++; // cuerpo del ciclo 
		 cout << "contador: " << contador << "\n";
	 }

	 cout << "Completo. Contador: " << contador << ".\n";
	 return 0;
 }
