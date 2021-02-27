 // Listado 5.8 - muestra el
 // polimorfismo de funciones

 #include <iostream.h>

 int Duplicar(int);
 long Duplicar(long);
 float Duplicar(float);
 double Duplicar(double);

 int main()
 {
	 int miEntero = 6500;
	 long miLargo = 65000;
	 float miFlotante = 6.5F;
	 double miDoble = 6.5e20;

	 int enteroDuplicado;
	 long largoDuplicado;
	 float flotanteDuplicado;
	 double dobleDuplicado;
 
	 cout << "miEntero: " << miEntero << "\n";
	 cout << "miLargo: " << miLargo << "\n";
	 cout << "miFlotante: " << miFlotante << "\n";
	 cout << "miDoble: " << miDoble << "\n";

	 enteroDuplicado = Duplicar(miEntero);
	 largoDuplicado = Duplicar(miLargo);
	 flotanteDuplicado = Duplicar(miFlotante);
	 dobleDuplicado = Duplicar(miDoble);

	 cout << "enteroDuplicado: " << enteroDuplicado << "\n";
	 cout << "largoDuplicado: " << largoDuplicado<< "\n";
	 cout << "flotanteDuplicado: " << flotanteDuplicado<< "\n";
	 cout << "dobleDuplicado: " << dobleDuplicado<< "\n";

	 return 0;
 }

 int Duplicar(int original)
 {
	 cout << "En Duplicar(int)\n";
	 return original * 2;
 }

 long Duplicar(long original)
 {
	 cout << "En Duplicar(long)\n";
	 return original * 2;
 }

 float Duplicar(float original)
 {
	 cout << "En Duplicar(float)\n";
	 return original * 2;
 }

 double Duplicar(double original)
 {
	 cout << "En Duplicar(double)\n";
	 return original * 2;
 }
