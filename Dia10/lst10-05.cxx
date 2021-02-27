 // Listado 10.5
 // Constructores de copia
 
 #include <iostream.h>
 
 class GATO
 {
 public:
	 GATO(); // constructor predeterminado
	 GATO (const GATO &); // constructor de copia
	 ~GATO(); // destructor
	 int ObtenerEdad() const 
		 { return *suEdad; }
	 int ObtenerPeso() const 
		 { return *suPeso; }
	 void AsignarEdad(int edad) 
		 { *suEdad = edad; }
	 
 private:
	 int * suEdad;
	 int * suPeso;
 };
 
 GATO::GATO()
 {
	 suEdad = new int;
	 suPeso = new int;
	 *suEdad = 5;
	 *suPeso = 9;
 }
 
 GATO::GATO(const GATO & rhs)
 {
	 suEdad = new int;
	 suPeso = new int;
	 *suEdad = rhs.ObtenerEdad(); // acceso público
	 *suPeso = *(rhs.suPeso); // acceso privado
 }
 
 GATO::~GATO()
 {
	 delete suEdad;
	 suEdad = NULL;
	 delete suPeso;
	 suPeso = NULL;
 }
 
 int main()
 {
	 GATO pelusa;
	 cout << "edad de pelusa: ";
	 cout << pelusa.ObtenerEdad() << endl;
	 cout << "Establecer la edad de pelusa en 6...\n";
	 pelusa.AsignarEdad(6);
	 cout << "Crear a silvestre a partir de pelusa\n";
	 GATO silvestre(pelusa);
	 cout << "edad de pelusa: ";
	 cout << pelusa.ObtenerEdad() << endl;
	 cout << "edad de silvestre: ";
	 cout << silvestre.ObtenerEdad() << endl;
	 cout << "establecer edad de pelusa en 7...\n";
	 pelusa.AsignarEdad(7);
	 cout << "edad de pelusa: ";
	 cout << pelusa.ObtenerEdad() << endl;
	 cout << "edad de silvestre: ";
	 cout << silvestre.ObtenerEdad() << endl;
	 return 0;
 }
