 // Listado 19.3 - Funciones amigas de tipo específico en plantillas

 #include <iostream.h>

 const int TamanioPredet = 10;


 // declarar una clase Animal simple para poder 
 // crear un arreglo de animales 
 class Animal
 {
 public:
	 Animal(int);
	 Animal();
	 ~Animal() {}
	 int ObtenerPeso() const 
		 { return suPeso; }
	 void Desplegar() const 
		 { cout << suPeso; }
 private:
	 int suPeso;
 };

 Animal::Animal(int peso):
	 suPeso(peso)
 {}

 Animal::Animal():
	 suPeso(0)
 {}

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
	 Arreglo & operator=(const Arreglo &);
	 T & operator[](int desplazamiento) 
		 { return apTipo[ desplazamiento ]; }
	 const T & operator[](int desplazamiento) const
		 { return apTipo[ desplazamiento ]; }
	 // métodos de acceso
	 int ObtenerTamanio() const 
		 { return suTamanio; }
	 // función amiga
	 friend void Intruso(Arreglo< int >);
 private:
	 T * apTipo;
	 int suTamanio;
 };

 // función amiga. No es una plantilla, ¡sólo se puede usar 
 // con arreglos de enteros! Se inmiscuye en los datos privados.
 void Intruso(Arreglo< int > elArreglo)
 {
	 cout << "\n*** Intruso ***\n";
	 for (int i = 0; i < elArreglo.suTamanio; i++)
		 cout << "i: " << elArreglo.apTipo[ i ] << endl;
	 cout << "\n";
 }

 // las implementaciones están a continuación...
 // implementar el Constructor
 template < class T >
 Arreglo< T >::Arreglo(int tamanio):
 suTamanio(tamanio)
 {
	 apTipo = new T[ tamanio ];
	
	 for (int i = 0; i < tamanio; i++)
		 apTipo[i] = 0;
 }

 // constructor de copia 
 template < class T >
 Arreglo< T >::Arreglo(const Arreglo & rhs)
 {
	 suTamanio = rhs.ObtenerTamanio();
	 apTipo = new T[ suTamanio ];
	
	 for (int i = 0; i < suTamanio; i++)
		 apTipo[ i ] = rhs[ i ];
 }

 // operator=
 template < class T >
 Arreglo< T > & Arreglo< T >::operator=(const Arreglo & rhs)
 {
	 if (this == &rhs)
		 return *this;
	 delete [] apTipo;
	 suTamanio = rhs.ObtenerTamanio();
	 apTipo = new T[ suTamanio ];
	 for (int i = 0; i < suTamanio; i++)
		 apTipo[ i ] = rhs[ i ];
	 return *this;
 }

 // programa controlador
 int main()
 {
	 // un arreglo de enteros 
	 Arreglo< int > elArreglo;
	 // un arreglo de animales
	 Arreglo< Animal > elZoologico;
	 Animal *apAnimal;
	
	 // llenar los arreglos 
	 for (int i = 0; i < elArreglo.ObtenerTamanio(); i++)
	 {
		 elArreglo[ i ] = i * 2;
		 apAnimal = new Animal(i * 3);
		 elZoologico[ i ] = *apAnimal;
	 }
	 for (int j = 0; j < elArreglo.ObtenerTamanio(); j++)
	 {
		 cout << "elZoologico[" << j << "]:\t";
		 elZoologico[ j ].Desplegar();
		 cout << endl;
	 }
	 cout << "Usar ahora la función amiga para ";
	 cout << "encontrar los miembros de Arreglo<int>";
	 Intruso(elArreglo);
	 cout << "\n\nListo.\n";
	 return 0;
 }
