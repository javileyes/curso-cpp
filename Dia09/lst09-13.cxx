 // Listado 9.13 Regreso de una referencia 
 // a un objeto que ya no existe
 
 #include <iostream.h>
 
 class GatoSimple
 {
 public:
	 GatoSimple(int edad, int peso);
	 ~GatoSimple() {}
	 int ObtenerEdad() 
		 { return suEdad; }
	 int ObtenerPeso() 
		 { return suPeso; }
 private:
	 int suEdad;
	 int suPeso;
 };
 
 GatoSimple::GatoSimple(int edad, int peso)
 {
	 suEdad = edad;
	 suPeso = peso;
 }
 
 GatoSimple & LaFuncion();
 
 int main()
 {
	 GatoSimple & rGato = LaFuncion();
	 int edad = rGato.ObtenerEdad();
	 cout << "¡rGato tiene " << edad << " años de edad!\n";
	 return 0;
 }
 
 GatoSimple & LaFuncion()
 {
	 GatoSimple Pelusa(5, 9);
	 return Pelusa;
 }
