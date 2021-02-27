 //Listado 11.6 Ocultamiento de métodos
 
 #include <iostream.h>
 
 class Mamifero
 {
 public:
	 void Mover() const 
		 { cout << "Mamifero se mueve un paso\n"; }
	 void Mover(int distancia) const
	 {
		 cout << "Mamifero se mueve ";
		 cout << distancia <<" pasos.\n";
	 }
 protected:
	 int suEdad;
	 int suPeso;
 };
 
 class Perro : public Mamifero
 {
 public:
	 // ¡Otros compiladores tal vez emitan una advertencia 
	 // de que se está ocultando una función!
	 void Mover() const 
		 { cout << "Perro se mueve 5 pasos.\n"; }
 };
 
 int main()
 {
	 Mamifero animalGrande;
	 Perro fido;
	 
	 animalGrande.Mover();
	 animalGrande.Mover(2);
	 fido.Mover();
	 // fido.Mover(10);
	 return 0;
 }
