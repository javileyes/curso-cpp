 // Muestra de la declaraci�n de una clase y
 // la definici�n de los m�todos de la clase,

 #include <iostream.h> // para cout

 class Gato // empieza la declaraci�n de la clase
 {
 public: // empieza la secci�n p�blica
	 int ObtenerEdad(); // m�todo de acceso
	 void AsignarEdad (int edad); // m�todo de acceso
	 void Maullar(); // m�todo general
 private: // empieza la secci�n privada
	 int suEdad; // variable miembro
 };

 // ObtenerEdad, m�todo de acceso p�blico
 // regresa el valor de la propiedad suEdad
 int Gato::ObtenerEdad()
 {
	 return suEdad;
 }

 // definici�n de AsignarEdad, m�todo
 // de acceso p�blico
 // da un valor a la propiedad suEdad
 void Gato::AsignarEdad(int edad)
 {
	 // dar a la variable miembro suEdad el
	 // valor pasado por el par�metro edad
	 suEdad = edad;
 }

 // definici�n del m�todo Maullar
 // regresa: void
 // par�metros: Ninguno
 // acci�n: Imprime "miau" en la pantalla
 void Gato::Maullar()
 {
	 cout << "Miau.\n";
 }

 // crear un gato, asignar un valor a su edad, hacer que
 // ma�lle, que nos diga su edad y que vuelva a maullar.
 int main()
 {
	 Gato Pelusa;
	 Pelusa.AsignarEdad(5);
	 Pelusa.Maullar();
	 cout << "Pelusa es un gato que tiene ";
	 cout << Pelusa.ObtenerEdad() << " a�os de edad.\n";
	 Pelusa.Maullar();
	 return 0;
 }
