 // Listado 9.4
 // Referencias a objetos de una clase
 
 #include <iostream.h>
 
 class GatoSimple
 {
 public:
	 GatoSimple (int edad, int peso);
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
 
 int main()
 {
	 GatoSimple Pelusa(5, 8);
	 GatoSimple & rGato = Pelusa;
	 
	 cout << "Pelusa tiene: ";
	 cout << Pelusa.ObtenerEdad() << " años de edad. \n";
	 cout << "Y Pelusa pesa: ";
	 cout << rGato.ObtenerPeso() << " libras. \n";
	 return 0;
 }
