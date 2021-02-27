 // Listado 16.4 - Uso de get() sin parámetros
 #include <iostream.h>
	 
 int main()
 {
	 char ch;
	 while ((ch = cin.get()) != EOF)
	 {
	 	 cout << "ch: " << ch << endl;
	 }
	 cout << "\n¡Listo!\n";
	 return 0;
 }
