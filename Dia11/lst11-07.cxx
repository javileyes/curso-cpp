 //Listado 11.7 Cómo llamar al método base desde el método redefinido.
 
 #include <iostream.h>
 
 class Mamifero
 {
 public:
	 void Mover() const 
		 { cout << "Mamifero se mueve un paso\n"; }
	 void Mover(int distancia) const
	 {
		 cout << "Mamifero se mueve " << distancia;
		 cout << " pasos.\n";
	 }
 protected:
	 int suEdad;
	 int suPeso;
 };
 
 class Perro : public Mamifero
 {
 public:
	 void Mover()const;
 };
 
 void Perro::Mover() const
 {
	 cout << "En perro se mueve...\n";
	 Mamifero::Mover(3);
 }
 
 int main()
 {
	 Mamifero animalGrande;
	 Perro fido;
	 
	 animalGrande.Mover(2);
	 fido.Mamifero::Mover(6);
	 return 0;
 }
