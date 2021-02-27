 // Muestra de la declaraci�n de un constructor y
 // un destructor para la clase Gato

 #include <iostream.h> // para cout

 class Gato // empieza la declaraci�n de la clase
 {
 public: // empieza la secci�n p�blica
	 Gato(int edadInicial); // constructor
	 ~Gato(); // destructor
	 int ObtenerEdad(); // m�todo de acceso
	 void AsignarEdad(int edad); // m�todo de acceso
	 void Maullar();
 private: // empieza la secci�n privada
	 int suEdad; // variable miembro
 };

 // constructor de Gato,
 Gato::Gato(int edadInicial)
 {
	 suEdad = edadInicial;
 }

 Gato::~Gato() // destructor, no realiza ninguna acci�n
 {
 }

 // ObtenerEdad, m�todo de acceso p�blico
 // regresa el valor de su miembro suEdad
 int Gato::ObtenerEdad()
 {
	 return suEdad;
 }

 // Definici�n de AsignarEdad, m�todo
 // de acceso p�blico

 void Gato::AsignarEdad(int edad)
 {
	 // asignar a la variable miembro suEdad el
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
 // ma�lle, que nos diga su edad, y que vuelva a maullar.
 int main()
 {
	 Gato Pelusa(5);
	 Pelusa.Maullar();
	 cout << "Pelusa es un gato que tiene " ;
	 cout << Pelusa.ObtenerEdad() << " a�os de edad.\n";
	 Pelusa.Maullar();
	 Pelusa.AsignarEdad(7);
	 cout << "Ahora Pelusa tiene " ;
	 cout << Pelusa.ObtenerEdad() << " a�os de edad.\n";
	 return 0;
 }
