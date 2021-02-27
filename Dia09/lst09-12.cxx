 //Listado 9.12
 // Paso de referencias a objetos
 
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
 
 const GatoSimple & FuncionDos(const GatoSimple & elGato);
 
 int main()
 {
	 cout << "Crear un gato...\n";
	 GatoSimple Pelusa;
	 cout << "Pelusa tiene " << Pelusa.ObtenerEdad();
	 cout << " años de edad\n";
	 int edad = 5;
	 Pelusa.AsignarEdad(edad);
	 cout << "Pelusa tiene " << Pelusa.ObtenerEdad();
	 cout << " años de edad\n";
	 cout << "Llamando a FuncionDos...\n";
	 FuncionDos(Pelusa);
	 cout << "Pelusa tiene " << Pelusa.ObtenerEdad();
	 cout << " años de edad\n";
	 return 0;
 }
 
 // FuncionDos, pasa una referencia a un objeto const
 const GatoSimple & FuncionDos(const GatoSimple & elGato)
 {
	 cout << "FuncionDos. Regresando...\n";
	 cout << "Ahora Pelusa tiene " << elGato.ObtenerEdad();
	 cout << " años de edad \n";
	 // elGato.AsignarEdad(8); ¡const!
	 return elGato;
 }
