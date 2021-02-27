 // Listado 13.3. Herencia múltiple.
 // Herencia múltiple

 #include <iostream.h>

 class Caballo
 {
 public:
	 Caballo() 
		{ cout << "Constructor de Caballo... "; }
	 virtual ~Caballo() 
		{ cout << "Destructor de Caballo... "; }
	 virtual void Relinchar() const 
		{ cout << "¡Yihii!... "; }
 private:
	 int suEdad;
 };

 class Ave
 {
 public:
	 Ave() 
		{ cout << "Constructor de Ave... "; }
	 virtual ~Ave() 
		{ cout << "Destructor de Ave... "; }
	 virtual void Gorjear() const 
		{ cout << "Griii... "; }
	 virtual void Volar() const
		{ cout << "¡Puedo volar! ¡Puedo volar! ¡Puedo volar! "; }
 private:
	 int suPeso;
 };

 class Pegaso : public Caballo, public Ave
 {
 public:
	 void Gorjear() const 
		{ Relinchar(); }
	 Pegaso() 
		{ cout << "Constructor de Pegaso... "; }
	 ~Pegaso() 
		{ cout << "Destructor de Pegaso... "; }
 };

 const int NumeroMagico = 2;

 int main()
 {
	 Caballo* Rancho[NumeroMagico];
	 Ave* Pajarera[NumeroMagico];
	 Caballo * apCaballo;
	 Ave * apAve; 
	 int opcion,i;
	 for (i=0; i<NumeroMagico; i++)
	 {
		 cout << "\n(1)Caballo (2)Pegaso: ";
		 cin >> opcion;
		 if (opcion == 2)
			 apCaballo = new Pegaso;
		 else
			 apCaballo = new Caballo;
		 Rancho[i] = apCaballo;
	 }
	 for (i=0; i<NumeroMagico; i++)
	 {
		 cout << "\n(1)Ave (2)Pegaso: ";
		 cin >> opcion;
		 if (opcion == 2)
			 apAve = new Pegaso; 
		 else
			 apAve = new Ave;
		 Pajarera[i] = apAve;
	 }
	
	 cout << "\n";
	 for (i=0; i<NumeroMagico; i++)
	 {
		 cout << "\nRancho[" << i << "]: " ;
		 Rancho[i]->Relinchar();
		 delete Rancho[i];
	 }
	
	 for (i=0; i<NumeroMagico; i++)
	 {
		 cout << "\nPajarera[" << i << "]: " ;
		 Pajarera[i]->Gorjear();
		 Pajarera[i]->Volar();
		 delete Pajarera[i];
	 }
	 return 0;
 }
