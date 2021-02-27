 //Implementación de funciones virtuales puras

 #include <iostream.h>

 class Figura
	 {
 public:
	 Figura(){}
	 virtual ~Figura(){}
	 virtual long ObtenerArea() = 0; 
	 virtual long ObtenerPerim()= 0;
	 virtual void Dibujar() = 0;
 private:
 };

 void Figura::Dibujar()
	 {
	 cout << "¡Mecanismo abstracto de dibujo!\n";
 }

 class Circulo : public Figura
	 {
 public:
	 Circulo(int radio):suRadio(radio){}
	 virtual ~Circulo(){}
		 long ObtenerArea() { return 3 * suRadio * suRadio; }
		 long ObtenerPerim() { return 9 * suRadio; }
	 void Dibujar();
 private:
	 int suRadio;
	 int suCircunferencia;
 };

 void Circulo::Dibujar()
	 {
	 cout << "¡Aquí va una rutina para dibujar un Circulo!\n";
	 Figura::Dibujar();
 }

 
 class Rectangulo : public Figura
	 {
 public:
	 Rectangulo(int longitud, int ancho):
	 suLongitud(longitud), suAncho(ancho){}
	 virtual ~Rectangulo(){}
		 long ObtenerArea() { return suLongitud * suAncho; }
		 long ObtenerPerim() {return 2*suLongitud + 2*suAncho; }
		 virtual int ObtenerLongitud() { return suLongitud; }
		 virtual int ObtenerAncho() { return suAncho; }
	 void Dibujar();
 private:
	 int suAncho;
	 int suLongitud;
 };

 void Rectangulo::Dibujar()
	 {
	 for (int i = 0; i<suLongitud; i++)
		 {
		 for (int j = 0; j<suAncho; j++)
		 cout << "x ";
		
		 cout << "\n";
	 }
	 Figura::Dibujar();
 }


 class Cuadrado : public Rectangulo
	 {
 public:
	 Cuadrado(int longitud);
	 Cuadrado(int longitud, int ancho);
	 virtual ~Cuadrado(){}
		 long ObtenerPerim() {return 4 * ObtenerLongitud();}
 };
 
 Cuadrado::Cuadrado(int longitud):
 Rectangulo(longitud,longitud)
 {}

 Cuadrado::Cuadrado(int longitud, int ancho):
 Rectangulo(longitud,ancho)

	 {
	 if (ObtenerLongitud() != ObtenerAncho())
	 cout << "Error, no es un cuadrado... ¿un Rectangulo??\n";
 }

 int main()
	 {
	 int opcion;
	 bool fSalir = false;
	 Figura * sp;
	 
	 while (1)
		 {
		 cout << "(1)Circulo (2)Rectangulo (3)Cuadrado (0)Salir: ";
		 cin >> opcion;
		
		 switch (opcion)
			 {
			 case 1: sp = new Circulo(5);
			 break;
			 case 2: sp = new Rectangulo(4,6);
			 break;
			 case 3: sp = new Cuadrado (5);
			 break;
			 default: fSalir = true;
			 break;
		 }
		 if (fSalir)
		 break;
		
		 sp->Dibujar();
		 delete sp;
		 cout << "\n";
	 }
	 return 0;
 }
