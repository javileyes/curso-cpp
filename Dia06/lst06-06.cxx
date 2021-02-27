 // Muestra de las funciones en línea
 // y la inclusión de archivos de encabezado

 #include "lst06-06.hpp" // -¡asegúrese de incluir los archivos de encabezado!


 Gato::Gato(int edadInicial) //constructor
 {
	 suEdad = edadInicial;
 }

 Gato::~Gato() //destructor, no realiza ninguna acción
 {
 }

 // Crear un gato, asignar un valor a su edad, hacer que maúlle,
 // que nos diga su edad y que maúlle nuevamente.
 int main()
 {
	 Gato Pelusa(5);
	 Pelusa.Maullar();
	 cout << "Pelusa es un gato que tiene " ;
	 cout << Pelusa.ObtenerEdad() << " años de edad.\n";
	 Pelusa.Maullar();
	 Pelusa.AsignarEdad(7);
	 cout << "Ahora Pelusa tiene " ;
	 cout << Pelusa.ObtenerEdad() << " años de edad.\n";
	 return 0;
 }
