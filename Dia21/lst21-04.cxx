 // Listado 21.4 ASSERT

 #define DEPURAR
 #include <iostream.h>

 #ifndef DEPURAR
     #define ASSERT(x)
 #else 
     #define ASSERT(x) if (! (x)) { cout << "¡¡ERROR!! Assert "; cout << #x << " falló\n"; cout << " en la línea " << __LINE__ << "\n"; cout << " del archivo " << __FILE__ << "\n"; }
 //
 //
 //
 //
 //
 //
 #endif


 int main()
 {
	 int x = 5;
	
	 cout << "Primera Assert: \n";
	 ASSERT(x == 5);
	 cout << "\nSegunda Assert: \n";
	 ASSERT(x != 5);
	 cout << "\nListo.\n";
	 return 0;
 }
