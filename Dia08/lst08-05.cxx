 // Listado 8.5
 // Creaci�n de objetos en el heap
 
 #include <iostream.h>
 
 class GatoSimple
 {
 public:
	 GatoSimple();
	 ~GatoSimple();
 private:
	 int suEdad;
 };
 
 GatoSimple::GatoSimple()
 {
	 cout << "Se llam� al constructor.\n";
	 suEdad = 1;
 }
 
 GatoSimple::~GatoSimple()
 {
	 cout << "Se llam� al destructor.\n";
 }
 
 int main()
 {
	 cout << "GatoSimple Pelusa...\n";
	 GatoSimple Pelusa;
	 cout << "GatoSimple *apFelix = new GatoSimple...\n";
	 GatoSimple * apFelix = new GatoSimple;
	 cout << "delete apFelix...\n";
	 delete apFelix;
	 cout << "saliendo, observe c�mo se va Pelusa...\n";
	 return 0;
 }
