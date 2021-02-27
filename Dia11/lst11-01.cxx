 //Listado 11.1 Herencia simple

 #include <iostream.h>

 enum RAZA { GOLDEN, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB };

 class Mamifero
 {
 public:
	 //constructores
	 Mamifero();
	 ~Mamifero();
	 //m�todos de acceso
	 int ObtenerEdad() const;
	 void AsignarEdad(int);
	 int ObtenerPeso() const;
	 void AsignarPeso();
	 //Otros m�todos
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
	 // M�todos de acceso
	 RAZA ObtenerRaza() const;
	 void AsignarRaza(RAZA);
	 // Otros m�todos
	 void MoverCola();
	 void PedirAlimento();
 protected:
	 RAZA suRaza;
 };
