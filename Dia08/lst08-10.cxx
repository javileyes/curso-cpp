 // Listado 8.10
 // Uso de apuntadores con métodos const
 
 #include <iostream.h>
 
 class Rectangulo
 {
 public:
	 Rectangulo();
	 ~Rectangulo();
	 void AsignarLongitud(int longitud) 
		 { suLongitud = longitud; }
	 int ObtenerLongitud() const 
		 { return suLongitud; }
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
	 Rectangulo * apRect = new Rectangulo;
	 const Rectangulo * apConstRect = new Rectangulo;
	 Rectangulo * const apConstApunt = new Rectangulo;
	 
	 cout << "Ancho de apRect: ";
	 cout << apRect->ObtenerAncho() << " pies\n";
	 cout << "Ancho de apConstRect: ";
	 cout << apConstRect->ObtenerAncho() << " pies\n";
	 cout << "Ancho de apConstApunt: ";
	 cout << apConstApunt->ObtenerAncho() << " pies\n";
	 
	 apRect->AsignarAncho(10);
	 // apConstRect->AsignarAncho(10);
	 apConstApunt->AsignarAncho(10);
	 
	 cout << "Ancho de apRect: ";
	 cout << apRect->ObtenerAncho() << " pies\n";
	 cout << "Ancho de apConstRect: ";
	 cout << apConstRect->ObtenerAncho() << " pies\n";
	 cout << "Ancho de apConstApunt: ";
	 cout << apConstApunt->ObtenerAncho() << " pies\n";
	 return 0;
 }
