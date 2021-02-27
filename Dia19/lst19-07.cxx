 // Listado 19.7: Uso de funciones y datos miembro estáticos

 #include <iostream.h>

 const int TamanioPredet = 3;


 // Una clase trivial para agregar a los arreglos
 class Animal
 {
 public:
	 // constructores
	 Animal(int);
	 Animal();
	 ~Animal();
	 // métodos de acceso
	 int ObtenerPeso() const 
		 { return suPeso; }
	 void AsignarPeso(int elPeso) 
		 { suPeso = elPeso; }
	 // operadores amigos 
	 friend ostream & operator<< (ostream &, const Animal &);
 private:
	 int suPeso;
 };

 // operador de extracción para imprimir animales
 ostream & operator<< (ostream & elFlujo, const Animal & elAnimal)
 {
	 elFlujo << elAnimal.ObtenerPeso();
	 return elFlujo;
 }

 Animal::Animal(int peso):
	 suPeso(peso)
 {
	 //cout << "animal(int) \n";
 }

 Animal::Animal():
	 suPeso(0)
 {
	 //cout << "animal() \n";
 }

 Animal::~Animal()
 {
	 //cout << "Se destruyó un animal...\n";
 }

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
		 { delete [] apTipo; suNumeroArreglos--; }
	 // operadores
	 Arreglo & operator=(const Arreglo &);
	 T & operator[](int desplazamiento) 
		 { return apTipo[ desplazamiento ]; }
	 const T & operator[](int desplazamiento) const
		 { return apTipo[ desplazamiento ]; }
	 // métodos de acceso
	 int ObtenerTamanio() const 
		 { return suTamanio; }
	 static int ObtenerNumeroArreglos() 
		 { return suNumeroArreglos; }
	 // función amiga 
	 friend ostream & operator<< <> (ostream &, const Arreglo< T > &);
 private:
	 T *apTipo;
	 int suTamanio;
	 static int suNumeroArreglos;
 };

 template < class T >
 int Arreglo< T >::suNumeroArreglos = 0;

 template < class T >
 Arreglo< T >::Arreglo(int tamanio = TamanioPredet):
	 suTamanio(tamanio)
 {
	 apTipo = new T[ tamanio ];
	
	 for (int i = 0; i < tamanio; i++)
		 apTipo[ i ] = (T)0;
	 suNumeroArreglos++;
 }

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
 }

 template < class T >
 Arreglo< T >::Arreglo(const Arreglo & rhs)
 {
	 suTamanio = rhs.ObtenerTamanio();
	 apTipo = new T[ suTamanio ];
	
	 for (int i = 0; i < suTamanio; i++)
		 apTipo[ i ] = rhs[ i ];
	 suNumeroArreglos++;
 }


 template < class T >
 ostream & operator<< (ostream & salida, const Arreglo< T > & elArreglo)
 {
	 for (int i = 0; i < elArreglo.ObtenerTamanio(); i++)
		 salida << "[" << i << "] " << elArreglo[ i ] << endl;
	 return salida;
 }

 int main()
 {
	 cout << Arreglo< int >::ObtenerNumeroArreglos();
	 cout << " arreglos de enteros\n";
	 cout << Arreglo< Animal >::ObtenerNumeroArreglos();
	 cout << " arreglos de animales\n\n";
	
	 Arreglo< int > arregloInt;
	 Arreglo< Animal > arregloAnimal;
	
	 cout << arregloInt.ObtenerNumeroArreglos();
	 cout << " arreglos de enteros\n";
	 cout << arregloAnimal.ObtenerNumeroArreglos();
	 cout << " arreglos de animales\n\n";
	
	 Arreglo< int > *apArregloInt = new Arreglo< int >;
	
	 cout << Arreglo< int >::ObtenerNumeroArreglos();
	 cout << " arreglos de enteros\n";
	 cout << Arreglo< Animal >::ObtenerNumeroArreglos();
	 cout << " arreglos de animales\n\n";
	
	 delete apArregloInt;
	
	 cout << Arreglo< int >::ObtenerNumeroArreglos();
	 cout << " arreglos de enteros\n";
	 cout << Arreglo< Animal >::ObtenerNumeroArreglos();
	 cout << " arreglos de animales\n\n";
	 return 0;
 }
