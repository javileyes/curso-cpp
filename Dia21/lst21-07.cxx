 // Listado 21.7: Niveles de depuración

 #define ALTO 3
 #define MEDIO 2
 #define BAJO 1
 #define NINGUNO 0
 #define NIVELDEPURAR ALTO 

 #include <iostream.h>
 #include <string.h>

 #if NIVELDEPURAR < BAJO // debe ser medio o alto para definir ASSERT()
   #define ASSERT(x)
 #else
   #define ASSERT(x) if (! (x)) { cout << "¡¡ERROR!! Assert " << #x << " falló\n"; cout << " en la línea " << __LINE__ < "\n"; cout << " del archivo " << __FILE__ << "\n"; }
 #endif

 #if NIVELDEPURAR < MEDIO
   #define EVAL(x)
 #else
   #define EVAL(x) cout << #x << ":\t" << x << endl;
 #endif

 #if NIVELDEPURAR < ALTO
   #define IMPRIMIR(x)
 #else
   #define IMPRIMIR(x) cout << x << endl;
 #endif


 class Cadena
 {
 public:
	 // constructores
	 Cadena();
	 Cadena(const char * const);
	 Cadena(const Cadena &);
	 ~Cadena();
	 char & operator[](int offset);
	 char operator[](int offaset) const;
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
	 unsigned short suLongitud;
 };

 // constructor predeterminado crea una cadena de 0 bytes
 Cadena::Cadena()
 {
	 suCadena = new char[ 1 ];
	 suCadena[ 0 ] = '\0';
	 suLongitud = 0;
	 ASSERT(Constantes());
 }

 // constructor privado (auxiliar), lo utilizan sólo 
 // los métodos de la clase para crear una nueva cadena del
 // tamaño requerido. Se llena de caracteres nulos.
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
	
	 for (int i = 0; i < suLongitud; i++)
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
 // luego copia la cadena y el tamaño
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
	 IMPRIMIR("(Constantes de Cadena probadas)");
	 return ((bool) (suLongitud && suCadena) ||
	 (!suLongitud && !suCadena));
 }

 class Animal
 {
 public:
	 Animal() : suEdad(1), suNombre("John Q. Animal")
		 { ASSERT(Constantes()); }
	 Animal(int, const Cadena &);
	 ~Animal() {}
	 int ObtenerEdad()
	 {
		 ASSERT(Constantes());
		 return suEdad;
	 }
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
	 IMPRIMIR("(Constantes de Animal probadas)");
	 return (suEdad > 0 && suNombre.ObtenerLongitud());
 }

 int main()
 {
	 const int EDAD = 5;
	
	 EVAL(EDAD);
	 Animal sparky(EDAD,"Sparky");
	 cout << "\n" << sparky.ObtenerNombre().ObtenerCadena();
	 cout << " tiene " << sparky.ObtenerEdad();
	 cout << " años de edad.\n";
	 sparky.AsignarEdad(8);
	 cout << "\n" << sparky.ObtenerNombre().ObtenerCadena();
	 cout << " tiene " << sparky.ObtenerEdad();
	 cout << " años de edad.\n";
	 return 0;
 }
