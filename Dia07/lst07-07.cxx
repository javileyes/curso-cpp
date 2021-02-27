 // Listado 7.7
 // Muestra del ciclo do...while

 #include <iostream.h>

 int main()
 {
	 int contador;

	 cout << "¿Cuántos holas?: ";
	 cin >> contador;
	 do
	 {
		 cout << "Hola\n";
		 contador--;
	 } while (contador >0);
	 cout << "Contador vale: " << contador << endl;
	 return 0;
 }
