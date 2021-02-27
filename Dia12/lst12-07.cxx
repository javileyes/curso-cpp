 // Listado 12.7 - Un arreglo en el heap

 #include <iostream.h>

 class GATO
 {
 public:
	 GATO() 
		 { suEdad = 1; suPeso = 5; }
	 ~GATO();
	 int ObtenerEdad() const 
		 { return suEdad; }
	 int ObtenerPeso() const 
		 { return suPeso; }
	 void AsignarEdad(int edad ) 
		 { suEdad = edad; }
 private:
	 int suEdad;
	 int suPeso;
 };
 
 GATO::~GATO()
 {
	 // cout << "¡Se llamó al destructor!\n";
 }

 int main()
 {
	 GATO * Familia = new GATO[ 500 ];
	 int i;
	
	 for (i = 0; i < 500; i++ )
	 {
		 Familia[ i ].AsignarEdad(2 * i + 1 );
	 }
	 for (i = 0; i < 500; i++ )
	 {
		 cout << "Gato #" << i + 1 << ": ";
		 cout << Familia[ i ].ObtenerEdad() << endl;
	 }
	 delete [] Familia;
	 return 0;
 }
