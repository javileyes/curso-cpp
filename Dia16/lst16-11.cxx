 // Listado 16.11 - Uso de write()
 #include <iostream.h>
 #include <string.h>
	 
 int main()
 {
 	char Uno[] = "Uno, si por tierra";
 	int longitudCompleta = strlen(Uno);
 	int muyCorta = longitudCompleta - 6;
 	int muyLarga = longitudCompleta + 6;
	 
	cout.write(Uno, longitudCompleta) << "\n";
	cout.write(Uno, muyCorta) << "\n";
	cout.write(Uno, muyLarga) << "\n";
	return 0;
 }
