 // lst06-06.hpp
 #include <iostream.h>
 class Gato
 {
 public:
	 Gato (int edadInicial);
	 ~Gato();
	 int ObtenerEdad() const { return suEdad;} // �en l�nea!
	 void AsignarEdad (int edad) { suEdad = edad;} // �en l�nea!
	 void Maullar() const { cout << "Miau.\n";} // �en l�nea!
 private:
	 int suEdad;
 };
