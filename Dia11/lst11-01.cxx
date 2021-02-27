 //Listado 11.1 Herencia simple

 #include <iostream.h>

 enum RAZA { GOLDEN, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB };

 class Mamifero
 {
 public:
	 //constructores
	 Mamifero();
	 ~Mamifero();
	 //métodos de acceso
	 int ObtenerEdad() const;
	 void AsignarEdad(int);
	 int ObtenerPeso() const;
	 void AsignarPeso();
	 //Otros métodos
	 void Hablar() const;
	 void Dormir() const;
 protected:
	 int suEdad;
	 int suPeso;
 };

 class Perro : public Mamifero
 {
 public:
	 // Constructores
	 Perro();
	 ~Perro();
	 // Métodos de acceso
	 RAZA ObtenerRaza() const;
	 void AsignarRaza(RAZA);
	 // Otros métodos
	 void MoverCola();
	 void PedirAlimento();
 protected:
	 RAZA suRaza;
 };
