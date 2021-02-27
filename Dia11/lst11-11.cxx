 //Listado 11.11 Constructor virtual de copia 
 
 #include <iostream.h>
 
 enum ANIMALES { MAMIFERO, PERRO, GATO};
 const int NumTiposAnimales = 3;
 
 class Mamifero
 {
 public:
	 Mamifero() : suEdad(1) 
		 { cout << "Constructor de Mamifero...\n"; }
	 virtual ~Mamifero() 
		 { cout << "Destructor de Mamifero...\n"; }
	 Mamifero(const Mamifero & rhs);
	 virtual void Hablar() const 
		 { cout << "¡Mamifero habla!\n"; }
	 virtual Mamifero * Clonar() 
		 { return new Mamifero(*this); }
	 int ObtenerEdad()const 
		 { return suEdad; }
 protected:
	 int suEdad;
 };
 
 Mamifero::Mamifero(const Mamifero & rhs):suEdad(rhs.ObtenerEdad())
 {
	 cout << "Constructor de copia de Mamifero...\n";
 }
 
 class Perro:public Mamifero
 {
 public:
	 Perro() 
		 { cout << "Constructor de Perro...\n"; }
	 virtual ~Perro() 
		 { cout << "Destructor de Perro...\n"; }
	 Perro(const Perro & rhs);
	 void Hablar()const 
		 { cout << "¡Guau!\n"; }
	 virtual Mamifero * Clonar() 
		 { return new Perro(*this); }
 };
 
 Perro::Perro(const Perro & rhs):
	 Mamifero(rhs)
 {
	 cout << "Constructor de copia de Perro...\n";
 }
 
 class Gato:public Mamifero
 {
 public:
	 Gato() 
		 { cout << "Constructor de Gato...\n"; }
	 ~Gato() 
		 { cout << "Destructor de Gato...\n"; }
	 Gato(const Gato &);
	 void Hablar()const 
		 { cout << "¡Miau!\n"; }
	 virtual Mamifero * Clonar() 
		 { return new Gato(*this); }
 };
 
 Gato::Gato(const Gato & rhs):
	 Mamifero(rhs)
 {
	 cout << "Constructor de copia de Gato...\n";
 }
 
 int main()
 {
	 Mamifero * elArreglo[ NumTiposAnimales ];
	 Mamifero * aptr;
	 int opcion, i;
	 
	 for (i = 0; i < NumTiposAnimales; i++)
	 {
		 cout << "(1)perro (2)gato (3)Mamifero: ";
		 cin >> opcion;
		 switch (opcion)
		 {
			 case PERRO: 
				 aptr = new Perro;
				 break;
			 case GATO: 
				 aptr = new Gato;
				 break;
			 default: 
				 aptr = new Mamifero;
				 break;
		 }
		 elArreglo[ i ] = aptr;
	 }
	 Mamifero * OtroArreglo[ NumTiposAnimales ];
	 for (i = 0; i < NumTiposAnimales; i++)
	 {
		 elArreglo[ i ]->Hablar();
		 OtroArreglo[ i ] = elArreglo[ i ]->Clonar();
	 }
	 for (i = 0; i < NumTiposAnimales; i++)
		 OtroArreglo[ i ]->Hablar();
	 return 0;
 }
