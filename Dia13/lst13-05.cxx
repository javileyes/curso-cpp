 // Listado 13.5
 // Clases base comunes
 #include <iostream.h>

 typedef int CUARTAS;
	 enum COLOR { Rojo, Verde, Azul, Amarillo, Blanco, Negro, Cafe } ;

 class Animal // base común para caballo y ave
	 {
 public:
	 Animal(int);
		 virtual ~Animal() { cout << "Destructor de Animal...\n"; }
		 virtual int ObtenerEdad() const { return suEdad; }
		 virtual void AsignarEdad(int edad) { suEdad = edad; }
 private:
	 int suEdad;
 };

 Animal::Animal(int edad):
 suEdad(edad)
	 {
	 cout << "Constructor de Animal...\n";
 }

 class Caballo : public Animal
	 {
 public:
	 Caballo(COLOR color, CUARTAS altura, int edad);
		 virtual ~Caballo() { cout << "Destructor de Caballo...\n"; }
		 virtual void Relinchar()const { cout << "¡Yihii!... "; }
		 virtual CUARTAS ObtenerAltura() const { return suAltura; }
		 virtual COLOR ObtenerColor() const { return suColor; }
 protected:
	 CUARTAS suAltura;
	 COLOR suColor;
 };
 
 Caballo::Caballo(COLOR color, CUARTAS altura, int edad):
 Animal(edad),
 suColor(color),suAltura(altura)
	 {
	 cout << "Constructor de Caballo...\n";
 }

 class Ave : public Animal
	 {
 public:
	 Ave(COLOR color, bool migra, int edad);
		 virtual ~Ave() {cout << "Destructor de Ave...\n"; }
		 virtual void Gorjear()const { cout << "Griii... "; }
	 virtual void Volar()const
		 { cout << "¡Puedo volar! ¡Puedo volar! ¡Puedo volar! "; }
		 virtual COLOR ObtenerColor()const { return suColor; }
		 virtual bool ObtenerMigracion() const { return suMigracion; }
 protected:
	 COLOR suColor;
	 bool suMigracion;
 };

 Ave::Ave(COLOR color, bool emigra, int edad):
 Animal(edad),
 suColor(color), suMigracion(emigra)
	 {
	 cout << "Constructor de Ave...\n";
 }

 class Pegaso : public Caballo, public Ave
	 {
 public:
		 void Gorjear()const { Relinchar(); }
	 Pegaso(COLOR, CUARTAS, bool, long, int);
		 virtual ~Pegaso() {cout << "Destructor de Pegaso...\n";}
	 virtual long ObtenerNumeroCreyentes() const
		 { return suNumeroCreyentes; }
		 virtual COLOR ObtenerColor()const { return Caballo::suColor; }
		 virtual int ObtenerEdad() const { return Caballo::ObtenerEdad(); }
 private:
	 long suNumeroCreyentes;
 };
 
 Pegaso::Pegaso(
 COLOR aColor,
 CUARTAS altura,
 bool emigra,
 long NumCreyen,
 int edad):
 Caballo(aColor, altura,edad),
 Ave(aColor, emigra,edad),
 suNumeroCreyentes(NumCreyen)
	 {
	 cout << "Constructor de Pegaso...\n";
 }

 int main()
	 {
	 Pegaso *apPeg = new Pegaso(Rojo, 5, true, 10, 2);
	 int edad = apPeg->ObtenerEdad();
	 cout << "Este Pegaso tiene " << edad << " años de edad.\n";
	 delete apPeg;
	 return 0;
 }
