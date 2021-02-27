 // Listado 17.1 Uso de un espacio de nombres
	 
 #include <iostream.h>
	 
	 
 namespace Ventana
 {
	 const int MAX_X = 30 ;
	 const int MAX_Y = 40 ;
	 class Vidrio
	 {
	 public:
		 Vidrio();
		 ~Vidrio();
		 void tamanio(int x, int y);
		 void mover(int x, int y);
		 void mostrar();
	 private:
		 static int cnt;
		 int x;
		 int y;
	 };
 }
	 
 int Ventana::Vidrio::cnt = 0;
	 
 Ventana::Vidrio::Vidrio():
	 x(0), 
	 y(0) 
 {}
	 
 Ventana::Vidrio::~Vidrio() {}
	 
 void Ventana::Vidrio::tamanio(int x, int y)
 {
	 if(x < Ventana::MAX_X && x > 0)
		 Vidrio::x = x;
	 if(y < Ventana::MAX_Y && y > 0)
		 Vidrio::y = y;
 }
	 
 void Ventana::Vidrio::mover(int x, int y)
 {
	 if(x < Ventana::MAX_X && x > 0)
		 Vidrio::x = x;
	 if(y < Ventana::MAX_Y && y > 0)
		 Vidrio::y = y;
 }
	 
 void Ventana::Vidrio::mostrar()
 {
	 std::cout << " x " << Vidrio::x;
	 std::cout << " y " << Vidrio::y << std::endl;
 }
	 
 int main( )
 {
	 Ventana::Vidrio vidrio;
		 
	 vidrio.mover(20, 20);
	 vidrio.mostrar( );
	 return 0 ;
 }
