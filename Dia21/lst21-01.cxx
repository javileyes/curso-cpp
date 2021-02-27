 // Listado 21.1 - Uso de #define

 #define VersionDemo
 #define VERSION_NT 5
 #include <iostream.h>

 int main()
 {
	 cout << "Comprobando las definiciones de VersionDemo, ";
	 cout << "VERSION_NT y VERSION_WINDOWS...\n";
	
	 #ifdef VersionDemo
	   cout << "VersionDemo definida.\n";
	 #else
	   cout << "VersionDemo no definida.\n";
	 #endif
	
	 #ifndef VERSION_NT
	   cout << "¡VERSION_NT no definida!\n";
	 #else
	   cout << "VERSION_NT definida como: " << VERSION_NT << endl;
	 #endif
	
	 #ifdef VERSION_WINDOWS
	   cout << "¡VERSION_WINDOWS definida!\n";
	 #else
	   cout << "VERSION_WINDOWS no fue definida.\n";
	 #endif
	
	 cout << "Listo.\n";
	 return 0;
 }
