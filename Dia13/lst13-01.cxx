 // Listado 13.1. Si los caballos pudieran volar...
 // Infiltrando a Volar() en Caballo

 #include <iostream.h>

 class Caballo
 {
 public:
	 void Galopar()
		{ cout << "Galopando...\n"; }
	 virtual void Volar() 
		{ cout << "Los caballos no pueden volar.\n" ; }
 private:
	 int suEdad;
 };

 class Pegaso : public Caballo
 {
 public:
	 virtual void Volar() 
		{ cout << "¡Puedo volar! ¡Puedo volar! ¡Puedo volar!\n"; }
 };

 const int NumeroCaballos = 5;

 int main()
 {
	 Caballo* Rancho[NumeroCaballos];
	 Caballo* apCaballo;
	 int opcion,i;
	 for (i=0; i<NumeroCaballos; i++)
	 {
		 cout << "(1)Caballo (2)Pegaso: ";
		 cin >> opcion;
		 if (opcion == 2)
			 apCaballo = new Pegaso;
		 else
			 apCaballo = new Caballo;
		 Rancho[i] = apCaballo;
	 }
	 cout << "\n";
	 for (i=0; i<NumeroCaballos; i++)
	 {
		 Rancho[i]->Volar();
		 delete Rancho[i];
	 }
	 return 0;
 }
