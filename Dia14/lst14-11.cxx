 //Listado 14.11 Arreglo de apuntadores a funciones miembro

 #include <iostream.h>

 class Perro
 {
 public:
	 void Hablar()const 
		{ cout << "¡Guau!\n"; }
	 void Mover() const 
		{ cout << "Caminando hacia el amo...\n"; }
	 void Comer() const 
		{ cout << "Devorando la comida...\n"; }
	 void Grunir() const 
		{ cout << "Grrrrr\n"; }
	 void Gimotear() const 
		{ cout << "Sonidos de gimoteos...\n"; }
	 void DarVuelta() const 
		{ cout << "Dando vuelta...\n"; }
	 void HacerMuerto() const 
		{ cout << "¿Es éste el final del pequeño César?\n"; }
 };

 typedef void (Perro::*AFM)()const ;

 int main()
 {
	 const int MaxFuncs = 7;
	 AFM PerroFunciones[MaxFuncs] =
	 { 
		 Perro::Hablar,
		 Perro::Mover,
		 Perro::Comer,
		 Perro::Grunir,
		 Perro::Gimotear,
		 Perro::DarVuelta,
		 Perro::HacerMuerto 
	 };
	
	 Perro* apPerro =NULL;
	 int Metodo;
	 bool fSalir = false;
	 
	 while (!fSalir)
	 {
		 cout << "(0)Salir (1)Hablar (2)Mover (3)Comer (4)Grunir";
		 cout << " (5)Gimotear (6)Dar vuelta (7)Hacerse el muerto: ";
		 cin >> Metodo;
		 if (Metodo == 0)
		 {
			 fSalir = true;
		 }
		 else
		 {
			 apPerro = new Perro;
			 (apPerro->*PerroFunciones[Metodo-1])();
			 delete apPerro;
		 }
	 }
	 return 0;
 }
