 // Declaración de la clase Gato
 // Los datos miembro son privados, los métodos de acceso públicos
 // se encargan de asignar y obtener los valores de los datos privados

 class Gato
 {
 public:
 	// elementos de acceso públicos
	 unsigned int ObtenerEdad();
	 void AsignarEdad(unsigned int Edad);

	 unsigned int ObtenerPeso();
	 void AsignarPeso(unsigned int Peso);

	 // funciones miembro públicas
	 void Maullar();

 // datos miembro privados
 private:
	 unsigned int suEdad;
	 unsigned int suPeso;

 };
