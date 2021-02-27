 //Listado 13.7. Clases de Figura.

 #include <iostream.h>


 class Figura
	 {
 public:
	 Figura(){}
	 virtual ~Figura(){}
		 virtual long ObtenerArea() { return -1; } 
		 virtual long ObtenerPerim() { return -1; }
	 virtual void Dibujar() {}
 private:
 };

 class Circulo : public Figura
	 {
 public:
	 Circulo(int radio):suRadio(radio){}
	 ~Circulo(){}
		 long ObtenerArea() { return 3 * suRadio * suRadio; }
		 long ObtenerPerim() { return 6 * suRadio; }
	 void Dibujar();
 private:
	 int suRadio;
	 int suCircunferencia;
 };
 
 void Circulo::Dibujar()
	 {
	 cout << "¡Aquí va la rutina para dibujar un Circulo!\n";
 }


 class Rectangulo : public Figura
	 {
 public:
	 Rectangulo(int longitud, int ancho):
	 suLongitud(longitud), suAncho(ancho){}
	 virtual ~Rectangulo(){}
		 virtual long ObtenerArea() { return suLongitud * suAncho; }
		 virtual long ObtenerPerim() {return 2*suLongitud + 2*suAncho; }
		 virtual int ObtenerLongitud() { return suLongitud; }
		 virtual int ObtenerAncho() { return suAncho; }
	 virtual void Dibujar();
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
 }

 class Cuadrado : public Rectangulo
	 {
 public:
	 Cuadrado(int longitud);
	 Cuadrado(int longitud, int ancho);
	 ~Cuadrado(){}
		 long ObtenerPerim() {return 4 * ObtenerLongitud();}
 };

 Cuadrado::Cuadrado(int longitud):
 Rectangulo(longitud,longitud)
 {}

 Cuadrado::Cuadrado(int longitud, int ancho):
 Rectangulo(longitud,ancho) 

	 {
	 if (ObtenerLongitud() != ObtenerAncho())
	 cout << "Error, no es un Cuadrado... ¿un Rectangulo??\n";
 }

 int main()
	 {
	 int opcion;
	 bool fSalir = false;
	 Figura * sp;
	
	 while (! fSalir)
		 {
		 cout << "(1)Circulo (2)Rectangulo (3)Cuadrado (0)Salir: ";
		 cin >> opcion;
		
		 switch (opcion)
			 {
			 case 0: fSalir = true;
			 break;
			 case 1: sp = new Circulo(5);
			 break;
			 case 2: sp = new Rectangulo(4,6);
			 break;
			 case 3: sp = new Cuadrado(5);
			 break;
			 default: cout << "Escriba un número entre 0 y 3" << endl;
			 continue;
			 break;
		 }
		 if(fSalir) break;
		 sp->Dibujar();
		 delete sp;
		 cout << "\n";
	 }
	 return 0;
 }
