 // Listado 12.4 - Un arreglo de objetos

 #include <iostream.h>

 class GATO
 {
 public:
	 GATO() 
		 { suEdad = 1; suPeso = 5; }
	 ~GATO() {}
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

 int main()
 {
	 GATO Camada[ 5 ];
	 int i;
	
	 for (i = 0; i < 5; i++ )
		 Camada[ i ].AsignarEdad(2 * i + 1 );
	 for (i = 0; i < 5; i++ )
	 {
		 cout << "Gato #" << i + 1 << ": ";
		 cout << Camada[ i ].ObtenerEdad() << endl;
	 }
	 return 0;
 }
