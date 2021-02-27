 // Listado 19.6: Especialización de implementaciones de plantilla

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
	 cout << "animal(int) \n";
 }

 Animal::Animal():
	 suPeso(0)
 {
	 cout << "animal() \n";
 }

 Animal::~Animal()
 {
	 cout << "Se destruyó un animal...\n";
 }

 // declarar la plantilla y el parámetro
 template < class T >
 // la clase que se va a parametrizar
 class Arreglo 
 {
 public:
	 Arreglo(int suTamanio = TamanioPredet);
	 Arreglo(const Arreglo & rhs);
	 ~Arreglo() 
		 { delete [] apTipo; }
	 // operadores
	 Arreglo & operator=(const Arreglo &);
	 T & operator[](int desplazamiento) 
		 { return apTipo[desplazamiento]; }
	 const T	& operator[](int desplazamiento) const
		 { return apTipo[desplazamiento]; }
	 // métodos de acceso
	 int ObtenerTamanio() const 
		 { return suTamanio; }
	 // función amiga
	 friend ostream & operator<< <> (ostream &, const Arreglo< T > &);
 private:
	 T *apTipo;
	 int suTamanio;
 };

 template < class T >
 Arreglo< T >::Arreglo(int tamanio = TamanioPredet):
 suTamanio(tamanio)
 {
	 apTipo = new T[ tamanio ];
	
	 for (int i = 0; i < tamanio; i++)
		 apTipo[ i ] = (T)0;
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
	 return *this;
 }

 template < class T >
 Arreglo< T >::Arreglo(const Arreglo & rhs)
 {
	 suTamanio = rhs.ObtenerTamanio();
	 apTipo = new T[ suTamanio ];
	
	 for (int i = 0; i < suTamanio; i++)
		 apTipo[ i ] = rhs[ i ];
 }


 template < class T >
 ostream & operator<< (ostream & salida, const Arreglo< T > & elArreglo)
 {
	 for (int i = 0; i < elArreglo.ObtenerTamanio(); i++)
		 salida << "[" << i << "] " << elArreglo[ i ] << endl;
	 return salida;
 }

 Arreglo< Animal >::Arreglo(int TamanioArregloAnimal):
 suTamanio(TamanioArregloAnimal)
 {
	 apTipo = new Animal[ TamanioArregloAnimal ];
 }

 void FuncionLlenarInt(Arreglo< int > & elArreglo);

 void FuncionLlenarAnimal(Arreglo< Animal > & elArreglo);

 int main()
 {
	 Arreglo< int > arregloInt;
	 Arreglo< Animal > arregloAnimal;
	
	 FuncionLlenarInt(arregloInt);
	 FuncionLlenarAnimal(arregloAnimal);
	 cout << "arregloInt...\n" << arregloInt;
	 cout << "\narregloAnimal...\n" << arregloAnimal << endl;
	 return 0;
 }

 void FuncionLlenarInt(Arreglo< int > & elArreglo)
 {
	 bool Detener = false;
	 int desplazamiento, valor;
	
	 while (!Detener)
	 {
		 cout << "Escriba un desplazamiento (0-9) y un valor. ";
		 cout << "(-1 para detener): " ;
		 cin >> desplazamiento >> valor;
		 if (desplazamiento < 0) 
			 break;
		 if (desplazamiento > 9)
		 {
			 cout << "***Utilice valores entre 0 y 9.***\n";
			 continue;
		 }
		 elArreglo[ desplazamiento ] = valor;
	 }
 }


 void FuncionLlenarAnimal(Arreglo< Animal > & elArreglo)
 {
	 Animal * apAnimal;
	
	 for (int i = 0; i < elArreglo.ObtenerTamanio(); i++)
	 {
		 apAnimal = new Animal(i * 10);
		 elArreglo[ i ] = *apAnimal;
		 delete apAnimal;
	 }
 }
