 // Listado 16.19 - Uso de los argumentos de la línea de comandos
 #include <iostream.h>
	 
 int main(int argc, char **argv)
 {
 	cout << "Se recibieron " << argc << " argumentos...\n";
 	for (int i = 0; i < argc; i++)
	 	 cout << "argumento " << i << ": " << argv[i] << endl;
	 return 0;
 }
