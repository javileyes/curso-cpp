 // Listado 8.6 Acceso a los datos miembro 
 // de objetos que se encuentran en el heap
 
 #include <iostream.h>
 
 class GatoSimple
 {
 public:
	 GatoSimple() 
		 { suEdad = 2; }
	 ~GatoSimple() {}
	 int ObtenerEdad() const 
		 { return suEdad; }
	 void AsignarEdad(int edad) 
		 { suEdad = edad; }
 private:
	 int suEdad;
 };
 
 int main()
 {
	 GatoSimple * Pelusa = new GatoSimple;
	 cout << "Pelusa tiene " << Pelusa->ObtenerEdad();
	 cout << "años de edad\n";
	 Pelusa->AsignarEdad(5);
	 cout << "Pelusa tiene " << Pelusa->ObtenerEdad();
	 cout << " años de edad\n";
	 delete Pelusa;
	 return 0;
 }
