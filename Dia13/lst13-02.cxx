 // Listado 13.2 Uso de dynamic_cast.
 // Uso de rtti

 #include <iostream.h>
 enum TIPO { CABALLO, PEGASO };

 class Caballo
 {
 public:
	 virtual void Galopar()
		{ cout << "Galopando...\n"; }
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
		 Pegaso *apPeg = dynamic_cast< Pegaso *> (Rancho[i]);
		 if (apPeg)
			 apPeg->Volar();
		 else
			 cout << "Sólo es un caballo\n";
		
		 delete Rancho[i];
	 }
	 return 0;
 }
