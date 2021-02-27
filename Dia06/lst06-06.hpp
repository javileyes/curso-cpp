 // lst06-06.hpp
 #include <iostream.h>
 class Gato
 {
 public:
	 Gato (int edadInicial);
	 ~Gato();
	 int ObtenerEdad() const { return suEdad;} // ¡en línea!
	 void AsignarEdad (int edad) { suEdad = edad;} // ¡en línea!
	 void Maullar() const { cout << "Miau.\n";} // ¡en línea!
 private:
	 int suEdad;
 };
