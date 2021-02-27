
 #include <iostream.h>

 class Mamifero
 {
 public:
	 Mamifero():suEdad(1) {}
	 virtual ~Mamifero() {}
	 virtual void Hablar() const = 0;
	 virtual void Mover() const = 0;
 protected:
	 int suEdad;
 };

 class Perro : public Mamifero
 {
 public:
	 void Hablar()const 
		{ cout << "¡Guau!\n"; }
	 void Mover() const 
		{ cout << "Caminando hacia el amo...\n"; }
 };


 class Gato : public Mamifero
 {
 public:
	 void Hablar()const 
		{ cout << "¡Miau!\n"; }
	 void Mover() const 
		{ cout << "caminando sigilosamente...\n"; }
 };


 class Caballo : public Mamifero
 {
 public:
	 void Hablar()const 
		{ cout << "¡Yihii!\n"; }
	 void Mover() const 
		{ cout << "Galopando...\n"; }
 };

 
 int main()
 {
	 void (Mamifero::*apFunc)() const =0;
	 Mamifero* aptr =NULL;
	 int Animal;
	 int Metodo;
	 bool fSalir = false;
	
	 while (fSalir == false)
	 {
		 cout << "(0)Salir (1)perro (2)gato (3)caballo: ";
		 cin >> Animal;
		 switch (Animal)
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
			 default: 
				fSalir = true; 
				break;
		 }
		 if (fSalir)
			 break;
		
		 cout << "(1)Hablar (2)Mover: ";
		 cin >> Metodo;
		 switch (Metodo)
		 {
			 case 1: 
				apFunc = Mamifero::Hablar; 
				break;
			 default: 
				apFunc = Mamifero::Mover; 
				break;
		 }
		
		 (aptr->*apFunc)();
		 delete aptr;
	 }
	 return 0;
 }
