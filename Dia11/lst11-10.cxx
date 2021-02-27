 //Listado 11.10 Partición de datos al pasar parámetros por valor
 
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
 
 void ValorFuncion(Mamifero);
 void AptrFuncion(Mamifero *);
 void RefFuncion(Mamifero &);
 
 int main()
 {
	 Mamifero * aptr = NULL;
	 int opcion;
	 while (1)
	 { 
		 bool fSalir = false;
		 cout << "(1)perro (2)gato (0)Salir: ";
		 cin >> opcion;
		 switch (opcion)
		 {
			 case 0: 
				 fSalir = true;
				 break;
			 case 1: 
				 aptr = new Perro;
				 break;
			 case 2: 
				 aptr = new Gato;
				 break;
			 default: 
				 aptr = new Mamifero;
				 break;
		 }
		 if (fSalir)
			 break;
		 AptrFuncion(aptr);
		 RefFuncion(*aptr);
		 ValorFuncion(*aptr);
	 }
	 return 0;
 }
 
 void ValorFuncion(Mamifero MamiferoValor)
 {
	 MamiferoValor.Hablar();
 }
 
 void AptrFuncion(Mamifero * apMamifero)
 {
	 apMamifero->Hablar();
 }
 
 void RefFuncion(Mamifero & rMamifero)
 {
	 rMamifero.Hablar();
 }
