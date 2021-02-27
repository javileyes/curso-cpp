 //Listado 11.5 Redefinición de un método 
 // de la clase base en una clase derivada
 
 #include <iostream.h>
 
 enum RAZA { GOLDEN, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB };
 
 class Mamifero
 {
 public:
	 // constructores
	 Mamifero() 
		 { cout << "Constructor de Mamifero...\n"; }
	 ~Mamifero() 
		 { cout << "Destructor de mamifero...\n"; }
	 //Otros métodos
	 void Hablar()const 
		 { cout << "¡Sonido de mamífero!\n"; }
	 void Dormir()const 
		 { cout << "shhh. Estoy durmiendo.\n"; }
 protected:
	 int suEdad;
	 int suPeso;
 };
 
 class Perro : public Mamifero
 {
 public:
	 // Constructores
	 Perro()
		 { cout << "Constructor de Perro...\n"; }
	 ~Perro()
		 { cout << "Destructor de Perro...\n"; }
	 // Otros métodos
	 void MoverCola() const 
		 { cout << "Moviendo la cola...\n"; }
	 void PedirAlimento() const 
		 { cout << "Pidiendo alimento...\n"; }
	 void Hablar() const 
		 { cout << "¡Guau!\n"; }
 private:
	 RAZA suRaza;
 };
 
 int main()
 {
	 Mamifero animalGrande;
	 Perro fido;
	 
	 animalGrande.Hablar();
	 fido.Hablar();
	 return 0;
 }
