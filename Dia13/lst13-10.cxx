 // Listado 13.10
 // Derivación de ADTs de otros ADTs
 #include <iostream.h>

	 enum COLOR { Rojo, Verde, Azul, Amarillo, Blanco, Negro, Cafe } ;

 class Animal // base común para Mamifero y Pez
	 {
 public:
	 Animal(int);
		 virtual ~Animal() { cout << "Destructor de Animal...\n"; }
		 virtual int ObtenerEdad() const { return suEdad; }
		 virtual void AsignarEdad(int edad) { suEdad = edad; }
	 virtual void Dormir() const = 0;
	 virtual void Comer() const = 0;
	 virtual void Reproducir() const = 0;
	 virtual void Mover() const = 0;
	 virtual void Hablar() const = 0;
 private:
	 int suEdad;
 };

 Animal::Animal(int edad):
 suEdad(edad)
	 {
	 cout << "Constructor de Animal...\n";
 }

 class Mamifero : public Animal
	 {
 public:
	 Mamifero(int edad):Animal(edad)
		 { cout << "Constructor de Mamifero...\n";}
		 virtual ~Mamifero() { cout << "Destructor de Mamifero...\n";}
	 virtual void Reproducir() const
		 { cout << "Reproducción de Mamifero representada...\n"; }
 };
 
 class Pez : public Animal
	 {
 public:
	 Pez(int edad):Animal(edad)
		 { cout << "Constructor de Pez...\n";}
		 virtual ~Pez() {cout << "Destructor de Pez...\n"; }
		 virtual void Dormir() const { cout << "Pez roncando...\n"; }
		 virtual void Comer() const { cout << "Pez comiendo...\n"; }
	 virtual void Reproducir() const
		 { cout << "Pez poniendo huevos...\n"; }
	 virtual void Mover() const
		 { cout << "Pez nadando...\n"; }
		 virtual void Hablar() const { }
 };

 class Caballo : public Mamifero
	 {
 public:
	 Caballo(int edad, COLOR color):
	 Mamifero(edad), suColor(color)
		 { cout << "Constructor de Caballo...\n"; }
		 virtual ~Caballo() { cout << "Destructor de Caballo...\n"; }
		 virtual void Hablar()const { cout << "¡Yihii!... \n"; }
		 virtual COLOR ObtenerSuColor() const { return suColor; }
	 virtual void Dormir() const
		 { cout << "Caballo roncando...\n"; }
		 virtual void Comer() const { cout << "Caballo comiendo...\n"; }
		 virtual void Mover() const { cout << "Caballo corriendo...\n";}
	
 protected:
	 COLOR suColor;
 };

 class Perro : public Mamifero
	 {
 public:
	 Perro(int edad, COLOR color):
	 Mamifero(edad), suColor(color)
		 { cout << "Constructor de Perro...\n"; }
		 virtual ~Perro() { cout << "Destructor de Perro...\n"; }
		 virtual void Hablar()const { cout << "¡Guau!... \n"; }
		 virtual void Dormir() const { cout << "Perro roncando...\n"; }
		 virtual void Comer() const { cout << "Perro comiendo...\n"; }
		 virtual void Mover() const { cout << "Perro corriendo...\n"; }
	 virtual void Reproducir() const
		 { cout << "Perro reproduciéndose...\n"; }
	 
 protected:
	 COLOR suColor;
 };

 int main()
	 {
	 Animal *apAnimal=NULL;
	 int opcion;
	 bool fSalir = false;
	
	 while (1)
		 {
		 cout << "(1)Perro (2)Caballo (3)Pez (0)Salir: ";
		 cin >> opcion;
		
		 switch (opcion)
			 {
			 case 1: apAnimal = new Perro(5,Cafe);
			 break;
			 case 2: apAnimal = new Caballo(4,Negro);
			 break;
			 case 3: apAnimal = new Pez (5);
			 break;
			 default: fSalir = true;
			 break;
		 }
		 if (fSalir)
		 break;
		
		 apAnimal->Hablar();
		 apAnimal->Comer();
		 apAnimal->Reproducir();
		 apAnimal->Mover();
		 apAnimal->Dormir();
		 delete apAnimal;
		 cout << "\n";
	 }
	 return 0;
 }
