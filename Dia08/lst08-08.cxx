 // Listado 8.8
 // Uso del apuntador this
 
 #include <iostream.h>
 
 class Rectangulo
 {
 public:
	 Rectangulo();
	 ~Rectangulo();
	 void AsignarLongitud(int longitud) 
		 { this->suLongitud = longitud; }
	 int ObtenerLongitud() const 
		 { return this->suLongitud; }
	 void AsignarAncho(int ancho) 
		 { suAncho = ancho; }
	 int ObtenerAncho() const 
		 { return suAncho; }
 private:
	 int suLongitud;
	 int suAncho;
 };
 
 Rectangulo::Rectangulo()
 {
	 suAncho = 5;
	 suLongitud = 10;
 }
 
 Rectangulo::~Rectangulo()
 {}
 
 int main()
 {
	 Rectangulo elRect;
	 
	 cout << "elRect tiene " << elRect.ObtenerLongitud();
	 cout << " pies de largo.\n";
	 cout << "elRect tiene " << elRect.ObtenerAncho();
	 cout << " pies de ancho.\n";
	 elRect.AsignarLongitud(20);
	 elRect.AsignarAncho(10);
	 cout << "elRect tiene " << elRect.ObtenerLongitud();
	 cout << " pies de largo.\n";
	 cout << "elRect tiene " << elRect.ObtenerAncho();
	 cout << " pies de ancho.\n";
	 return 0;
 }
