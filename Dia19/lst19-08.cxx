 // Listado 19.8: Vectores

 #include <iostream>
 #include <string>
 #include <vector>

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

 template< class T >
 // desplegar propiedades del vector
 void MostrarVector(const vector< T > & v);

 typedef vector< Estudiante > ClaseEscuela;

 int main()
 {
	 Estudiante Harry;
	 Estudiante Sally("Sally", 15);
	 Estudiante Bill("Bill", 17);
	 Estudiante Peter("Peter", 16);
	
	 ClaseEscuela ClaseVacia;
	 cout << "ClaseVacia:\n";
	 MostrarVector(ClaseVacia);
	
	 ClaseEscuela ClaseCreciendo(3);
	 cout << "ClaseCreciendo(3):\n";
	 MostrarVector(ClaseCreciendo);
	
	 ClaseCreciendo[ 0 ] = Harry;
	 ClaseCreciendo[ 1 ] = Sally;
	 ClaseCreciendo[ 2 ] = Bill;
	 cout << "ClaseCreciendo(3) después de asignar estudiantes:\n";
	 MostrarVector(ClaseCreciendo);
	
	 ClaseCreciendo.push_back(Peter);
	 cout << "ClaseCreciendo() después de agregar el 4to estudiante:\n";
	 MostrarVector(ClaseCreciendo);
	
	 ClaseCreciendo[ 0 ].AsignarNombre("Harry");
	 ClaseCreciendo[ 0 ].AsignarEdad(18);
	 cout << "ClaseCreciendo() después de Asignar:\n";
	 MostrarVector(ClaseCreciendo);
	 return 0;
 }

 // Desplegar propiedades del vector
 template< class T >
 void MostrarVector(const vector< T > & v)
 {
	 cout << "max_size() = " << v.max_size();
	 cout << "\tsize() = " << v.size();
	 cout << "\tcapacity() = " << v.capacity();
	 cout << "\t" << (v.empty()? "vacío": "no vacío");
	 cout << "\n";
	 for (int i = 0; i < v.size(); ++i)
		 cout << v[ i ] << "\n";
	 cout << endl;
 }
