 // Listado 5.7 - muestra el uso
 // de los valores predeterminados de parámetros

 #include <iostream.h>

 int VolumenCaja(int longitud, int ancho = 25, int altura = 1);

 int main()
 {
	 int longitud = 100;
	 int ancho = 50;
	 int altura = 2;
	 int volumen;

	 volumen = VolumenCaja(longitud, ancho, altura);
	 cout << "La primera vez el volumen es igual a: " << volumen << "\n";

	 volumen = VolumenCaja(longitud, ancho);
	 cout << "La segunda vez el volumen es igual a: " << volumen << "\n";

	 volumen = VolumenCaja(longitud);
	 cout << "La tercera vez el volumen es igual a: " << volumen << "\n";
	 return 0;
 }

 int VolumenCaja(int longitud, int ancho, int altura)
 {

	 return (longitud * ancho * altura);
 }
