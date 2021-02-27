 // listado 20.1: Cómo se produce una excepción

 #include <iostream.h>

 const int TamanioPredet = 10;


 class Arreglo
 {
 public:
	 // constructores
	 Arreglo(int suTamanio = TamanioPredet);
	 Arreglo(const Arreglo & rhs);
	 ~Arreglo() 
		 { delete [] apTipo;}
	 // operadores
	 Arreglo & operator=(const Arreglo &);
	 int & operator[](int desplazamiento);
	 const int & operator[](int desplazamiento) const;
	 // métodos de acceso
	 int ObtenersuTamanio() const 
		 { return suTamanio; }
	 // función amiga
	 friend ostream & operator<< (ostream &, const Arreglo &);
	 // definir la clase de excepción
	 class xLimite {};
 private:
	 int *apTipo;
	 int suTamanio;
 };


 Arreglo::Arreglo(int tamanio):
 suTamanio(tamanio)
 {
	 apTipo = new int[ tamanio ];
	
	 for (int i = 0; i < tamanio; i++)
	 apTipo[ i ] = 0;
 }


 Arreglo & Arreglo::operator=(const Arreglo & rhs)
 {
	 if (this == &rhs)
		 return *this;
	 delete [] apTipo;
	 suTamanio = rhs.ObtenersuTamanio();
	 apTipo = new int[ suTamanio ];
	 for (int i = 0; i < suTamanio; i++)
		 apTipo[ i ] = rhs[ i ];
	 return *this;
 }

 Arreglo::Arreglo(const Arreglo & rhs)
 {
	 suTamanio = rhs.ObtenersuTamanio();
	 apTipo = new int[ suTamanio ];
	
	 for (int i = 0; i < suTamanio; i++)
		 apTipo[ i ] = rhs[ i ];
 }

 int & Arreglo::operator[](int desplazamiento)
 {
	 int tamanio = ObtenersuTamanio();
	
	 if (desplazamiento >= 0 && desplazamiento < ObtenersuTamanio())
		 return apTipo[ desplazamiento ];
	 throw xLimite();
	 // apaciguar a MSC
	 return apTipo[ 0 ];
 }


 const int & Arreglo::operator[](int desplazamiento) const
 {
	 int mitamanio = ObtenersuTamanio();
	
	 if (desplazamiento >= 0 && desplazamiento < ObtenersuTamanio())
		 return apTipo[ desplazamiento ];
	 throw xLimite();
	 // apaciguar a MSC
	 return apTipo[ 0 ];
 }

 ostream & operator<< (ostream & salida, const Arreglo & elArreglo)
 {
	 for (int i = 0; i < elArreglo.ObtenersuTamanio(); i++)
		 salida << "[" << i << "] " << elArreglo[ i ] << endl;
	 return salida;
 }

 int main()
 {
	 Arreglo arregloInt(20);
	
	 try
		 {
		 for (int j = 0; j < 100; j++)
		 {
			 arregloInt[ j ] = j;
			 cout << "arregloInt[" << j;
			 cout << "] está bien..." << endl;
		 }
	 }
	 catch (Arreglo::xLimite)
	 {
		 cout << "¡No se pudo procesar su entrada!\n";
	 }
	 cout << "Listo.\n";
	 return 0;
 }
