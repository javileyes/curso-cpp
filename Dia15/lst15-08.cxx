 // Listado 15.8 - Operadores amigables
 
 #include <iostream.h>
 #include <string.h>
 
 
 // Clase cadena rudimentaria
 class Cadena
 {
 public:
	 // constructores
	 Cadena();
	 Cadena(const char *const);
	 Cadena(const Cadena &);
	 ~Cadena();
	 // operadores sobrecargados
	 char & operator[](int desplazamiento);
	 char operator[](int desplazamiento) const;
	 Cadena operator+(const Cadena &);
	 friend Cadena operator+(const Cadena &, const Cadena &);
	 void operator+=(const Cadena &);
	 Cadena & operator=(const Cadena &);
	 // Métodos generales de acceso
	 int ObtenerLongitud()const 
		 { return suLongitud; }
	 const char * ObtenerCadena() const 
		 { return suCadena; }
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
	 // cout << "\tConstructor de cadena predeterminado\n";
	 // ConstructorCuenta++;
 }
 
 // constructor privado (auxiliar), lo utilizan sólo 
 // los métodos de la clase para crear una nueva cadena del
 // tamaño requerido. Se llena con caracteres nulos.
 Cadena::Cadena(int longitud)
 {
	 suCadena = new char[ longitud + 1 ];
	 
	 for (int i = 0; i <= longitud; i++)
		 suCadena[ i ] = '\0';
	 suLongitud = longitud;
	 // cout << "\tConstructor de Cadena(int)\n";
	 // ConstructorCuenta++;
 }
 
 // Convierte un arreglo de caracteres en una Cadena
 Cadena::Cadena(const char * const cCadena)
 {
	 suLongitud = strlen(cCadena);
	 suCadena = new char[ suLongitud + 1 ];
	 for (int i = 0; i < suLongitud; i++)
		 suCadena[ i ] = cCadena[ i ];
	 suCadena[ suLongitud ] = '\0';
	 // cout << "\tConstructor de Cadena(char *)\n";
	 // ConstructorCuenta++;
 }
 
 // constructor de copia
 Cadena::Cadena (const Cadena & rhs)
 {
	 suLongitud = rhs.ObtenerLongitud();
	 suCadena = new char[ suLongitud + 1 ];
	 for (int i = 0; i < suLongitud; i++)
		 suCadena[ i ] = rhs[ i ];
	 suCadena[ suLongitud ] = '\0';
	 // cout << "\tConstructor de Cadena(Cadena&)\n";
	 // ConstructorCuenta++;
 }
 
 // destructor, libera la memoria asignada
 Cadena::~Cadena ()
 {
	 delete [] suCadena;
	 suLongitud = 0;
	 // cout << "\tDestructor de Cadena\n";
 }
 
 // operador igual a, libera la memoria existente
 // luego copia la cadena y el tamaño
 Cadena& Cadena::operator=(const Cadena & rhs)
 {
	 if (this == &rhs)
		 return *this;
	 delete [] suCadena;
	 suLongitud = rhs.ObtenerLongitud();
	 suCadena = new char[ suLongitud + 1 ];
	 for (int i = 0; i < suLongitud; i++)
		 suCadena[ i ] = rhs[ i ];
	 suCadena[ suLongitud ] = '\0';
	 return *this;
	 // cout << "\tOperador = de Cadena\n";
 }
 
 //operador de desplazamiento que no es constante, ¡regresa
 // la referencia a un carácter para que se pueda
 // cambiar!
 char & Cadena::operator[](int desplazamiento)
 {
	 if (desplazamiento > suLongitud)
		 return suCadena[ suLongitud - 1 ];
	 else
		 return suCadena[ desplazamiento ];
 }
 
 // operador de desplazamiento constante para utilizar
 // en objetos const (vea el constructor de copia)
 char Cadena::operator[](int desplazamiento) const
 {
	 if (desplazamiento > suLongitud)
	 	return suCadena[ suLongitud - 1 ];
	 else
		 return suCadena[ desplazamiento ];
 }
 
 // crea una nueva cadena al agregar la cadena
 // actual a rhs
 Cadena Cadena::operator+(const Cadena & rhs)
 {
	 int longitudTotal = suLongitud + rhs.ObtenerLongitud();
	 Cadena temp(longitudTotal);
	 int i, j;
	 
	 for (i = 0; i < suLongitud; i++)
		 temp[ i ] = suCadena[ i ];
	 for (j = 0, i = suLongitud; j<rhs.ObtenerLongitud(); j++, i++)
		 temp[ i ] = rhs[ j ];
	 temp[ longitudTotal ] = '\0';
	 return temp;
 }
 
 // crea una nueva cadena sumando
 // una cadena a otra
 Cadena operator+(const Cadena & lhs, const Cadena & rhs)
 {
	 int longitudTotal = lhs.ObtenerLongitud() + rhs.ObtenerLongitud();
	 Cadena temp(longitudTotal);
	 int i, j;
	 
	 for (i = 0; i < lhs.ObtenerLongitud(); i++)
		 temp[ i ] = lhs[ i ];
	 for (j = 0, i = lhs.ObtenerLongitud(); 
		 j < rhs.ObtenerLongitud(); j++, i++)
	 temp[ i ] = rhs[ j ];
	 temp[ longitudTotal ] = '\0';
	 return temp;
 }
 
 int main()
 {
	 Cadena s1("Cadena Uno ");
	 Cadena s2("Cadena Dos ");
	 char *c1 = { "C-Cadena Uno " } ;
	 Cadena s3;
	 Cadena s4;
	 Cadena s5;
	 
	 cout << "s1: " << s1.ObtenerCadena() << endl;
	 cout << "s2: " << s2.ObtenerCadena() << endl;
	 cout << "c1: " << c1 << endl;
	 s3 = s1 + s2;
	 cout << "s3: " << s3.ObtenerCadena() << endl;
	 s4 = s1 + c1;
	 cout << "s4: " << s4.ObtenerCadena() << endl;
	 s5 = c1 + s2;
	 cout << "s5: " << s5.ObtenerCadena() << endl;
	 return 0;
 }
