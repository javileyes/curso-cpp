 // Muestra de las funciones en l�nea
 // y la inclusi�n de archivos de encabezado

 #include "lst06-06.hpp" // -�aseg�rese de incluir los archivos de encabezado!


 Gato::Gato(int edadInicial) //constructor
 {
	 suEdad = edadInicial;
 }

 Gato::~Gato() //destructor, no realiza ninguna acci�n
 {
 }

 // Crear un gato, asignar un valor a su edad, hacer que ma�lle,
 // que nos diga su edad y que ma�lle nuevamente.
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
