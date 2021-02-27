 // Listado 19.10: Clase contenedora map

 #include <iostream>
 #include <string>
 #include <map>

 using namespace std;


 class Estudiante
 {
 public:
	 Estudiante();
	 Estudiante(const string & nombre, const int edad);
	 Estudiante(const Estudiante & rhs);
	 ~Estudiante();
	 void AsignarNombre(const string & nombre);
	 string ObtenerNombre() const;
	 void AsignarEdad(const int edad);
	 int ObtenerEdad() const;
	 Estudiante & operator=(const Estudiante & rhs);
 private:
	 string suNombre;
	 int suEdad;
 };

 Estudiante::Estudiante():
	 suNombre("Nuevo Estudiante"),
	 suEdad(16)
 {}

 Estudiante::Estudiante(const string & nombre, const int edad):
	 suNombre(nombre),
	 suEdad(edad)
 {}

 Estudiante::Estudiante(const Estudiante & rhs):
	 suNombre(rhs.ObtenerNombre()),
	 suEdad(rhs.ObtenerEdad())
 {}

 Estudiante::~Estudiante()
 {}

 void Estudiante::AsignarNombre(const string & nombre)
 {
	 suNombre = nombre;
 }

 string Estudiante::ObtenerNombre() const
 {
	 return suNombre;
 }

 void Estudiante::AsignarEdad(const int edad)
 {
	 suEdad = edad;
 }

 int Estudiante::ObtenerEdad() const
 {
	 return suEdad;
 }

 Estudiante & Estudiante::operator=(const Estudiante & rhs)
 {
	 suNombre = rhs.ObtenerNombre();
	 suEdad = rhs.ObtenerEdad();
	 return *this;
 }

 ostream & operator<<(ostream & os, const Estudiante & rhs)
 {
	 os << rhs.ObtenerNombre() << " tiene ";
	 os << rhs.ObtenerEdad() << " años de edad";
	 return os;
 }

 template< class T, class A >
 // desplegar propiedades del contenedor map
 void MostrarMap(const map< T, A > & v);

 typedef map< string, Estudiante > ClaseEscuela;

 int main()
 {
	 Estudiante Harry("Harry", 18);
	 Estudiante Sally("Sally", 15);
	 Estudiante Bill("Bill", 17);
	 Estudiante Peter("Peter", 16);
	
	 ClaseEscuela ClaseMatematicas;
	 ClaseMatematicas[ Harry.ObtenerNombre() ] = Harry;
	 ClaseMatematicas[ Sally.ObtenerNombre() ] = Sally;
	 ClaseMatematicas[ Bill.ObtenerNombre() ] = Bill;
	 ClaseMatematicas[ Peter.ObtenerNombre() ] = Peter;
	
	 cout << "ClaseMatematicas:\n";
	 MostrarMap(ClaseMatematicas);
	
	 cout << "Sabemos que ";
	 cout << ClaseMatematicas[ "Bill" ].ObtenerNombre();
	 cout << " tiene ";
	 cout << ClaseMatematicas[ "Bill" ].ObtenerEdad();
	 cout << " años de edad\n";
	 return 0;
 }

 // Desplegar propiedades del contenedor map
 template< class T, class A >
 void MostrarMap(const map< T, A > & v)
 {
	 for (map< T, A >::const_iterator ci = v.begin();
	      ci != v.end(); ++ci)
		 cout << ci->first << ": " << ci->second << "\n";
	 cout << endl;
 }
