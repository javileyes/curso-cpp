 //Listado 11.9 Varias funciones virtuales llamadas una por una
 
 #include <iostream.h>
 
 class Mamifero
 {
 public:
	 Mamifero() : suEdad(1) {}
	 virtual ~Mamifero() {}
	 virtual void Hablar() const 
		 { cout << "¡Mamifero habla!\n"; }
 protected:
	 int suEdad;
 };
 
 class Perro : public Mamifero
 {
 public:
	 void Hablar()const 
		 { cout << "¡Guau!\n"; }
 };
 
 class Gato : public Mamifero
 {
 public:
	 void Hablar()const 
		 { cout << "¡Miau!\n"; }
 };
 
 class Caballo : public Mamifero
 {
 public:
	 void Hablar()const 
		 { cout << "¡Yihii!\n"; }
 };
 
 class Cerdo: public Mamifero
 {
 public:
	 void Hablar()const 
		 { cout << "¡Oink!\n"; }
 };
 
 int main()
 {
	 Mamifero * elArreglo[ 5 ];
	 Mamifero * aptr;
	 int opcion, i;
	 
	 for (i = 0; i < 5; i++)
	 {
		 cout << "(1)perro (2)gato (3)caballo (4)cerdo: ";
		 cin >> opcion;
		 switch (opcion)
		 {
			 case 1: 
				 aptr = new Perro;
				 break;
			 case 2: 
				 aptr = new Gato;
				 break;
			 case 3: 
				 aptr = new Caballo;
				 break;
			 case 4: 
				 aptr = new Cerdo;
				 break; 
			 default: 
				 aptr = new Mamifero;
				 break;
		 }
		 elArreglo[ i ] = aptr;
	 }
	 for (i = 0; i < 5; i++)
		 elArreglo[ i ]->Hablar();
	 return 0;
 }
