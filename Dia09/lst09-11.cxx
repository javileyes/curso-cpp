 //Listado 9.11
 // Paso de apuntadores const a objetos
 
 #include <iostream.h>
 
 class GatoSimple
 {
 public:
	 GatoSimple();
	 GatoSimple(GatoSimple &);
	 ~GatoSimple();
	 int ObtenerEdad() const 
		 { return suEdad; }
	 void AsignarEdad(int edad) 
		 { suEdad = edad; }
 private:
	 int suEdad;
 };
 
 GatoSimple::GatoSimple()
 {
	 cout << "Constructor de GatoSimple...\n";
	 suEdad = 1;
 }
 
 GatoSimple::GatoSimple(GatoSimple &)
 {
	 cout << "Constructor de copia de GatoSimple...\n";
 }
 
 GatoSimple::~GatoSimple()
 {
	 cout << "Destructor de GatoSimple...\n";
 }
 
 const GatoSimple * const FuncionDos(const GatoSimple * const elGato);
 
 int main()
 {
	 cout << "Crear un gato...\n"; 
	 GatoSimple Pelusa;
	 cout << "Pelusa tiene " ;
	 cout << Pelusa.ObtenerEdad();
	 cout << " años de edad\n";
	 int edad = 5;
	 Pelusa.AsignarEdad(edad);
	 cout << "Pelusa tiene " ;
	 cout << Pelusa.ObtenerEdad();
	 cout << " años de edad\n";
	 cout << "Llamando a FuncionDos...\n";
	 FuncionDos(&Pelusa);
	 cout << "Pelusa tiene " ;
	 cout << Pelusa.ObtenerEdad();
	 cout << " años de edad\n";
	 return 0;
 }
 
 // FuncionDos, pasa un apuntador const
 const GatoSimple * const FuncionDos(const GatoSimple * const elGato)
 {
	 cout << "FuncionDos. Regresando...\n";
	 cout << "Ahora Pelusa tiene " << elGato->ObtenerEdad();
	 cout << " años de edad \n";
	 // elGato->AsignarEdad(8); ¡const!
	 return elGato;
 }
