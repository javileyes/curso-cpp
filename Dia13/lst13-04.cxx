 // Listado 13.4
 // Cómo llamar varios constructores
 #include <iostream.h>
 typedef int CUARTAS;
 enum COLOR { Rojo, Verde, Azul, Amarillo, Blanco, Negro, Cafe } ;

 class Caballo
 {
 public:
	 Caballo(COLOR color, CUARTAS altura);
	 virtual ~Caballo() 
		{ cout << "Destructor de Caballo...\n"; }
	 virtual void Relinchar()const 
		{ cout << "¡Yihii!... "; }
	 virtual CUARTAS ObtenerAltura() const 
		{ return suAltura; }
	 virtual COLOR ObtenerColor() const 
		{ return suColor; }
 private:
	 CUARTAS suAltura;
	 COLOR suColor;
 };

 Caballo::Caballo(COLOR color, CUARTAS altura):
	 suColor(color),suAltura(altura)
 {
	 cout << "Constructor de Caballo...\n";
 }

 class Ave
 {
 public:
	 Ave(COLOR color, bool emigra);
	 virtual ~Ave() 
		{ cout << "Destructor de Ave...\n"; }
	 virtual void Gorjear()const 
		{ cout << "Griii... "; }
	 virtual void Volar()const
		 { cout << "¡Puedo volar! ¡Puedo volar! ¡Puedo volar! "; }
	 virtual COLOR ObtenerColor()const 
		{ return suColor; }
	 virtual bool ObtenerMigracion() const 
		{ return suMigracion; }
 private:
	 COLOR suColor;
	 bool suMigracion;
 };

 Ave::Ave(COLOR color, bool emigra):
	 suColor(color), 
	 suMigracion(emigra)
 {
	 cout << "Constructor de Ave...\n";
 }

 class Pegaso : public Caballo, public Ave
 {
 public:
	 void Gorjear()const 
		{ Relinchar(); }
	 Pegaso(COLOR, CUARTAS, bool,long);
	 ~Pegaso() 
		{cout << "Destructor de Pegaso...\n";}
	 virtual long ObtenerNumeroCreyentes() const
		 { return suNumeroCreyentes; }
 private:
	 long suNumeroCreyentes;
 };
 
 Pegaso::Pegaso( COLOR aColor,
	         CUARTAS altura,
	         bool emigra,
	         long NumCreyen):
	 Caballo(aColor, altura),
	 Ave(aColor, emigra),
	 suNumeroCreyentes(NumCreyen)
 {
	 cout << "Constructor de Pegaso...\n";
 }

 int main()
 {
	 Pegaso *apPeg = new Pegaso(Rojo, 5, true, 10);
	 apPeg->Volar();
	 apPeg->Relinchar();
	 cout << "\nSu Pegaso mide " << apPeg->ObtenerAltura();
	 cout << " cuartas de altura y ";
	 if (apPeg->ObtenerMigracion())
		 cout << "sí emigra.";
	 else
		 cout << "no emigra.";
	 cout << "\nUn total de " << apPeg->ObtenerNumeroCreyentes();
	 cout << " personas creen que sí existe.\n";
	 delete apPeg;
	 return 0;
 }
