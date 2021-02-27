 // Declaraci�n de la clase Gato
 // Los datos miembro son privados, los m�todos de acceso p�blicos
 // se encargan de asignar y obtener los valores de los datos privados

 class Gato
 {
 public:
 	// elementos de acceso p�blicos
	 unsigned int ObtenerEdad();
	 void AsignarEdad(unsigned int Edad);

	 unsigned int ObtenerPeso();
	 void AsignarPeso(unsigned int Peso);

	 // funciones miembro p�blicas
	 void Maullar();

 // datos miembro privados
 private:
	 unsigned int suEdad;
	 unsigned int suPeso;

 };
