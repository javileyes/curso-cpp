 // Listado 15.3 - Otro ejemplo de la clase Empleado
 // que utiliza la clase Cadena (lst15-01.hpp) 
 
 #include "lst15-01.hpp"
 
 
 class Empleado
 {
 public:
	 Empleado();
	 Empleado(char *, char *, char *, long);
	 ~Empleado();
	 Empleado(const Empleado &);
	 Empleado & operator= (const Empleado &);
	 const Cadena & ObtenerPrimerNombre() const
		 { return suPrimerNombre; }
	 const Cadena & ObtenerApellido() const 
		 { return suApellido; }
	 const Cadena & ObtenerDireccion() const 
		 { return suDireccion; }
	 long ObtenerSalario() const 
		 { return suSalario; }
	 void AsignarPrimerNombre(const Cadena & primNombre)
		 { suPrimerNombre = primNombre; }
	 void AsignarApellido(const Cadena & Apellido)
		 { suApellido = Apellido; }
	 void AsignarDireccion(const Cadena & direccion)
		 { suDireccion = direccion; }
	 void AsignarSalario(long salario) 
		 { suSalario = salario; }
 private:
	 Cadena suPrimerNombre;
	 Cadena suApellido;
	 Cadena suDireccion;
	 long suSalario;
 };
 
 Empleado::Empleado():
	 suPrimerNombre(""),
	 suApellido(""),
	 suDireccion(""),
	 suSalario(0)
 {}
 
 Empleado::Empleado(char * primerNombre, char * apellido,
	            char * direccion, long salario):
	 suPrimerNombre(primerNombre),
	 suApellido(apellido),
	 suDireccion(direccion),
	 suSalario(salario)
 {}
 
 Empleado::Empleado(const Empleado & rhs):
	 suPrimerNombre(rhs.ObtenerPrimerNombre()),
	 suApellido(rhs.ObtenerApellido()),
	 suDireccion(rhs.ObtenerDireccion()),
	 suSalario(rhs.ObtenerSalario())
 {}
 
 Empleado::~Empleado() {}
 
 Empleado & Empleado::operator= (const Empleado & rhs)
 {
	 if (this == &rhs)
		 return *this;
	 suPrimerNombre = rhs.ObtenerPrimerNombre();
	 suApellido = rhs.ObtenerApellido();
	 suDireccion = rhs.ObtenerDireccion();
	 suSalario = rhs.ObtenerSalario();
	 return *this;
 }
 
 int main()
 {
	 cout << "Creando a Edie...\n";
	 Empleado Edie("Jane", "Doe", "1461 Shore Parkway", 20000);
	 Edie.AsignarSalario(20000);
	 cout << "Llamando a AsignarPrimerNombre con char *...\n";
	 Edie.AsignarPrimerNombre("Edythe");
	 cout << "Creando cadena cApellido temporal...\n";
	 Cadena cApellido("Levine");
	 Edie.AsignarApellido(cApellido);
	 cout << "Nombre: ";
	 cout << Edie.ObtenerPrimerNombre().ObtenerCadena();
	 cout << " " << Edie.ObtenerApellido().ObtenerCadena();
	 cout << "\nDirección: ";
	 cout << Edie.ObtenerDireccion().ObtenerCadena();
	 cout << "\nSalario: " ;
	 cout << Edie.ObtenerSalario();
	 cout << endl;
	 return 0;
 }
