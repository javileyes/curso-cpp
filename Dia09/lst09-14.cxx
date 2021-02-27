 // Listado 9.14
 // Solución para fugas de memoria
 
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
 
 GatoSimple & LaFuncion();
 
 int main()
 {
	 GatoSimple & rGato = LaFuncion();
	 int edad = rGato.ObtenerEdad();
	 cout << "¡rGato tiene " << edad << " años de edad!\n";
	 cout << "&rGato: " << &rGato << endl;
	 // ¿Cómo nos deshacemos de esa memoria?
	 GatoSimple * apGato = &rGato;
	 delete apGato;
	 // Hmmm?,¿a quién se refiere ahora rGato??
	 return 0;
 }
 
 GatoSimple & LaFuncion()
 {
	 GatoSimple * apPelusa = new GatoSimple(5, 9);
	 cout << "apPelusa: " << apPelusa << endl;
	 return *apPelusa;
 }
