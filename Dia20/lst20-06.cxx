 // Listado 20.6: Excepciones con plantillas

 #include <iostream.h>

 const int TamanioPredet = 10;


 class xLimite {};

 template < class T >
 class Arreglo
 {
 public:
	 // constructores
	 Arreglo(int suTamanio = TamanioPred);
	 Arreglo(const Arreglo & rhs);
	 ~Arreglo() 
		 { delete [] apTipo;}
	 // operadores
	 Arreglo & operator=(const Arreglo< T > &);
	 T & operator[](int desplazamiento);
	 const T & operator[](int desplazamiento) const;
	 // métodos de acceso
	 int ObtenersuTamanio() const 
		 { return suTamanio; }
	 // función amiga
	 friend ostream & operator<< <> (ostream &, const Arreglo< T > &);
	 // definir las clases de excepciones
	 class xTamanio {};
 private:
	 int * apTipo;
	 int suTamanio;
 };

 template < class T >
 Arreglo< T >::Arreglo(int tamanio):
	 suTamanio(tamanio)
 {
	 if (tamanio < 10 || tamanio > 30000)
		 throw xTamanio();
	 apTipo = new T[ tamanio ];
	 for (int i = 0; i < tamanio; i++)
		 apTipo[ i ] = 0;
 }

 template < class T >
 Arreglo< T > & Arreglo< T >::operator=(const Arreglo< T > & rhs)
 {
	 if (this == &rhs)
		 return *this;
	 delete [] apTipo;
	 suTamanio = rhs.ObtenersuTamanio();
	 apTipo = new T[ suTamanio ];
	 for (int i = 0; i < suTamanio; i++)
		 apTipo[ i ] = rhs[ i ];
 }

 template < class T >
 Arreglo< T >::Arreglo(const Arreglo< T > & rhs)
 {
	 suTamanio = rhs.ObtenersuTamanio();
	 apTipo = new T[ suTamanio ];
	 for (int i = 0; i < suTamanio; i++)
		 apTipo[ i ] = rhs[ i ];
 }

 template < class T >
 T & Arreglo< T >::operator[](int desplazamiento)
 {
	 int tamanio = ObtenersuTamanio();
	
	 if (desplazamiento >= 0 && desplazamiento < ObtenersuTamanio())
		 return apTipo[ desplazamiento ];
	 throw xLimite();
	 return apTipo[ 0 ];
 }

 template < class T >
 const T & Arreglo< T >::operator[](int desplazamiento) const
 {
	 int mitamanio = ObtenersuTamanio();
	
	 if (desplazamiento >= 0 && desplazamiento < ObtenersuTamanio())
		 return apTipo[ desplazamiento ];
	 throw xLimite();
 }

 template < class T > ostream & operator<< (ostream & salida, const Arreglo< T > & elArreglo)
 {
	 for (int i = 0; i < elArreglo.ObtenersuTamanio(); i++)
		 salida << "[" << i << "] " << elArreglo[ i ] << endl;
	 return salida;
 }

 int main()
 {
	 try
	 {
		 Arreglo< int > arregloInt(9);
		
		 for (int j = 0; j < 100; j++)
		 {
			 arregloInt[ j ] = j;
			 cout << "arregloInt[" << j << "] está bien..." << endl;
		 }
	 }
	 catch (xLimite)
	 {
		 cout << "¡No se pudo procesar su entrada!\n";
	 }
	 catch (Arreglo< int >::xTamanio)
	 {
		 cout << "¡Tamaño incorrecto!\n";
	 }
	 cout << "Listo.\n";
	 return 0;
 }
