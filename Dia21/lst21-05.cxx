 // Listado 21.5: Uso de Constantes()

 #include <iostream.h>
 #include <string.h>
 #define DEPURAR
 #define MOSTRAR_CONSTANTES

 #ifndef DEPURAR
   #define ASSERT(x)
 #else
   #define ASSERT(x) if (! (x)) { cout << "¡¡ERROR!! Assert " << #x << " falló\n"; cout << " en la línea " << __LINE__ < "\n"; cout << " del archivo " << __FILE__ << "\n"; }
 #endif

 const int FALSE = 0;
 const int TRUE = 1;
 // typedef int bool;


 class Cadena
 {
 public:
	 // constructores
	 Cadena();
	 Cadena(const char * const);
	 Cadena(const Cadena &);
	 ~Cadena();
	 char & operator[](int offset);
	 char operator[](int offset) const;
	 Cadena & operator=(const Cadena &);
	 int ObtenerLongitud()const 
		 { return suLongitud; }
	 const char * ObtenerCadena() const 
		 { return suCadena; }
	 bool Constantes() const;
 private: 
	 // constructor privado
	 Cadena (int);
	 char * suCadena;
	 // unsigned short suLongitud;
	 int suLongitud;
 };

 // constructor predeterminado crea una cadena de 0 bytes
 Cadena::Cadena()
 {
	 suCadena = new char[ 1 ];
	 suCadena[ 0 ] = '\0';
	 suLongitud = 0;
	 ASSERT(Constantes());
 }

 // constructor privado (auxiliar), lo utilizan sólo los
 // métodos de la clase para crear una nueva cadena del
 // tamaño requerido. Se llena con caracteres nulos.
 Cadena::Cadena(int longitud)
 {
	 suCadena = new char[ longitud + 1 ];
	
	 for (int i = 0; i <= longitud; i++)
		 suCadena[ i ] = '\0';
	 suLongitud = longitud;
	 ASSERT(Constantes());
 }

 // Convierte un arreglo de caracteres en una Cadena
 Cadena::Cadena(const char * const cCadena)
 {
	 suLongitud = strlen(cCadena);
	 suCadena = new char[ suLongitud + 1 ];
	
	 for (int i = 0; i < suLongitud; i++)
		 suCadena[ i ] = cCadena[ i ];
	 suCadena[ suLongitud ] = '\0';
	 ASSERT(Constantes());
 }

 // constructor de copia
 Cadena::Cadena(const Cadena & rhs)
 {
	 suLongitud = rhs.ObtenerLongitud();
	 suCadena = new char[ suLongitud + 1 ];
	
	 for (int i = 0; i < suLongitud;i++)
		 suCadena[ i ] = rhs[ i ];
	 suCadena[ suLongitud ] = '\0';
	 ASSERT(Constantes());
 }

 // destructor, libera la memoria asignada
 Cadena::~Cadena ()
 {
	 ASSERT(Constantes());
	 delete [] suCadena;
	 suLongitud = 0;
 }

 // operador igual a, libera la memoria existente
 // y luego copia la cadena y el tamaño
 Cadena & Cadena::operator=(const Cadena & rhs)
 {
	 ASSERT(Constantes());
	 if (this == &rhs)
		 return *this;
	 delete [] suCadena;
	 suLongitud = rhs.ObtenerLongitud();
	 suCadena = new char[ suLongitud + 1 ];
	 for (int i = 0; i < suLongitud; i++)
		 suCadena[ i ] = rhs[ i ];
	 suCadena[ suLongitud ] = '\0';
	 ASSERT(Constantes());
	 return *this;
 }

 //operador de desplazamiento no constante
 char & Cadena::operator[](int offset)
 {
	 ASSERT(Constantes());
	 if (offset > suLongitud)
	 {
		 ASSERT(Constantes());
		 return suCadena[ suLongitud - 1 ];
	 }
	 else
	 {
		 ASSERT(Constantes());
		 return suCadena[ offset ];
	 }
 }

 // operador de desplazamiento constante 
 char Cadena::operator[](int offset) const
 {
	 ASSERT(Constantes());
	 char retVal;
	 if (offset > suLongitud)
		 retVal = suCadena[ suLongitud - 1 ];
	 else
	 retVal = suCadena[ offset ];
	 ASSERT(Constantes());
	 return retVal;
 }

 bool Cadena::Constantes() const
 {
	 #ifdef MOSTRAR_CONSTANTES
	   cout << "Constantes probadas";
	 #endif
	 return ((suLongitud && suCadena) || (!suLongitud && !suCadena));
 }

 class Animal
 {
 public:
	 Animal():suEdad(1),suNombre("John Q. Animal")
		 { ASSERT(Constantes()); }
	 Animal(int, const Cadena &);
	 ~Animal() {}
	 int ObtenerEdad() 
		 { ASSERT(Constantes()); return suEdad; }
	 void AsignarEdad(int Edad)
	 {
		 ASSERT(Constantes());
		 suEdad = Edad;
		 ASSERT(Constantes());
	 }
	 Cadena& ObtenerNombre()
	 {
		 ASSERT(Constantes());
		 return suNombre;
	 }
	 void AsignarNombre(const Cadena & nombre)
	 {
		 ASSERT(Constantes());
		 suNombre = nombre;
		 ASSERT(Constantes());
	 }
	 bool Constantes();
 private:
	 int suEdad;
	 Cadena suNombre;
 };

 Animal::Animal(int edad, const Cadena & nombre):
	 suEdad(edad),
	 suNombre(nombre)
 {
	 ASSERT(Constantes());
 }

 bool Animal::Constantes()
 {
	 #ifdef MOSTRAR_CONSTANTES
	   cout << "Constantes probadas";
	 #endif
	 return (suEdad > 0 && suNombre.ObtenerLongitud());
 }

 int main()
 {
	 Animal sparky(5, "Sparky");
	
	 cout << "\n" << sparky.ObtenerNombre().ObtenerCadena();
	 cout << " tiene " << sparky.ObtenerEdad();
	 cout << " años de edad.\n";
	 sparky.AsignarEdad(8);
	 cout << "\n" << sparky.ObtenerNombre().ObtenerCadena();
	 cout << " tiene " << sparky.ObtenerEdad();
	 cout << " años de edad.\n";
	 return 0;
 }
