 // Listado 10.3
 // Sobrecarga de constructores
 
 #include <iostream.h>
 
 class Rectangulo
 {
 public:
	 Rectangulo();
	 Rectangulo(int ancho, int longitud);
	 ~Rectangulo() {}
	 int ObtenerAncho() const 
		 { return suAncho; }
	 int ObtenerLongitud() const 
		 { return suLongitud; }
 private:
	 int suAncho;
	 int suLongitud;
 };
 
 Rectangulo::Rectangulo()
 {
	 suAncho = 5;
	 suLongitud = 10;
 }
 
 Rectangulo::Rectangulo (int ancho, int longitud)
 {
	 suAncho = ancho;
	 suLongitud = longitud;
 }
 
 int main()
 {
	 Rectangulo Rect1;
	 cout << "Ancho de Rect1: ";
	 cout << Rect1.ObtenerAncho() << endl;
	 cout << "Longitud de Rect1: ";
	 cout << Rect1.ObtenerLongitud() << endl;
	 
	 int unAncho, unaLongitud;
	 cout << "Escriba un ancho: ";
	 cin >> unAncho;
	 cout << "\nEscriba una longitud: ";
	 cin >> unaLongitud;
	 
	 Rectangulo Rect2(unAncho, unaLongitud);
	 cout << "\nAncho de Rect2: ";
	 cout << Rect2.ObtenerAncho() << endl;
	 cout << "Longitud de Rect2: ";
	 cout << Rect2.ObtenerLongitud() << endl;
	 return 0;
 }
