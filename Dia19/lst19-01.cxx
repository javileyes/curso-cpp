 #include <iostream.h>

 //Listado 19.1 La plantilla de una clase de tipo arreglo 

 const int TamanioPredet = 10;
 
 // declarar la plantilla y el parámetro 
 template < class T > 
 // la clase que se va a parametrizar
 class Arreglo 
 {
 public:
	 // constructores
	 Arreglo(int suTamanio = TamanioPredet);
	 Arreglo(const Arreglo & rhs);
	 ~Arreglo() 
		 { delete [] apTipo; }
	 // operadores
	 Arreglo& operator=(const Arreglo &);
	 T & operator[](int desplazamiento) 
		 { return apTipo[ desplazamiento ]; }
	 // métodos de acceso
	 int obtenerTamanio() 
		 { return suTamanio; }
 private:
	 T * apTipo;
	 int suTamanio;
 };
