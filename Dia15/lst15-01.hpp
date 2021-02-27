 // Listado 15.1: La clase Cadena - lst15-01.hpp 
 // usada por los listados 15.2, 15.3 y 15.4
 
 #include <iostream.h>
 #include <string.h>
 
 
 class Cadena
 {
 public:
	 // constructores
	 Cadena();
	 Cadena(const char * const);
	 Cadena(const Cadena &);
	 ~Cadena();
	 // operadores sobrecargados
	 char & operator[](int desplazamiento);
	 char operator[](int desplazamiento) const;
	 Cadena operator+(const Cadena &);
	 void operator+=(const Cadena &);
	 Cadena & operator= (const Cadena &);
	 // Métodos generales de acceso
	 int ObtenerLongitud()const 
		{ return suLongitud; }
	 const char * ObtenerCadena() const 
		{ return suCadena; }
	 static int ConstructorCuenta;
 private:
	 Cadena (int); // constructor privado
	 char * suCadena;
	 unsigned short suLongitud;
 };
 
 // constructor predeterminado, crea una cadena de 0 bytes
 Cadena::Cadena()
 {
	 suCadena = new char[ 1 ];
	 suCadena[ 0 ] = '\0';
	 suLongitud = 0;
	 // cout << "\tConstructor de cadena predeterminado \n";
	 ConstructorCuenta++;
 }
 
 // constructor privado (auxiliar), lo utilizan sólo 
 // los métodos de la clase para crear una nueva cadena del
 // tamaño requerido. Se llena con caracteres nulos.
 Cadena::Cadena(int longitud)
 {
	 suCadena = new char[ longitud+1 ];
	 for (int i = 0; i <= longitud; i++)
		 suCadena[ i ] = '\0';
	 suLongitud = longitud;
	 // cout << "\tConstructor de Cadena(int)\n";
	 ConstructorCuenta++;
 }
 
 // Convierte un arreglo de caracteres en una Cadena
 Cadena::Cadena(const char * const cCadena)
 {
	 suLongitud = strlen(cCadena);
	 suCadena = new char[ suLongitud+1 ];
	 for (int i = 0; i < suLongitud; i++)
		 suCadena[ i ] = cCadena[ i ];
	 suCadena[ suLongitud ] = '\0';
	 // cout << "\tConstructor de Cadena(char *) constructor\n";
	 ConstructorCuenta++;
 }
 
 // constructor de copia
 Cadena::Cadena (const Cadena & rhs)
 {
	 suLongitud = rhs.ObtenerLongitud();
	 suCadena = new char[ suLongitud+1 ];
	 for (int i = 0; i < suLongitud; i++)
		 suCadena[ i ] = rhs[ i ];
	 suCadena[ suLongitud ] = '\0';
	 // cout << "\tConstructor de Cadena(Cadena &)\n";
	 ConstructorCuenta++;
 }
 
 // destructor, libera la memoria asignada
 Cadena::~Cadena ()
 {
	 delete [] suCadena;
	 suLongitud = 0;
	 // cout << "\tDestructor de Cadena\n";
 }
 
 // operador igual a, libera la memoria existente
 // y luego copia la cadena y el tamaño
 Cadena& Cadena::operator=(const Cadena & rhs)
 {
	 if (this == &rhs)
		 return *this;
	 delete [] suCadena;
	 suLongitud = rhs.ObtenerLongitud();
	 suCadena = new char[ suLongitud+1 ];
	 for (int i = 0; i < suLongitud; i++)
		 suCadena[ i ] = rhs[ i ];
	 suCadena[ suLongitud ] = '\0';
	 // cout << "\tOperador = de Cadena\n";
	 return * this;
 }
 
 //Operador de desplazamiento no constante, ¡regresa
 // una referencia a un carácter para que se pueda
 // cambiar!
 char & Cadena::operator[](int desplazamiento)
 {
	 if (desplazamiento > suLongitud)
		 return suCadena[ suLongitud-1 ];
	 else
		 return suCadena[ desplazamiento ];
 }
 
 // operador de desplazamiento constante para utilizar 
 // en objetos tipo const (ver constructor de copia)
 char Cadena::operator[](int desplazamiento) const
 {
	 if (desplazamiento > suLongitud)
		 return suCadena[ suLongitud-1 ];
	 else
		 return suCadena[ desplazamiento ];
 }
 
 // crea una nueva cadena agregando la cadena
 // actual a rhs
 Cadena Cadena::operator+(const Cadena & rhs)
 {
	 int longitudTotal = suLongitud + rhs.ObtenerLongitud();
	 Cadena temp(longitudTotal);
	 int i, j;
	 
	 for (i = 0; i < suLongitud; i++)
		 temp[ i ] = suCadena[ i ];
	 for (j = 0; j < rhs.ObtenerLongitud(); j++, i++)
		 temp[ i ] = rhs[ j ];
	 temp[ longitudTotal ] = '\0';
	 return temp;
 }
 
 // cambia la cadena actual, no regresa nada
 void Cadena::operator+=(const Cadena & rhs)
 {
	 unsigned short rhsLong = rhs.ObtenerLongitud();
	 unsigned short longitudTotal = suLongitud + rhsLong;
	 Cadena temp(longitudTotal);
	 int i, j;
	 
	 for (i = 0; i < suLongitud; i++)
		 temp[ i ] = suCadena[ i ];
	 for (j = 0; j < rhs.ObtenerLongitud(); j++, i++)
		 temp[ i ] = rhs[ i - suLongitud ];
	 temp[ longitudTotal ] = '\0';
	 *this = temp;
 }
 
 // int Cadena::ConstructorCuenta = 0;
