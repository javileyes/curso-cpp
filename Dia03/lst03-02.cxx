// Muestra de las variables
#include <iostream.h>

int main()
{
	unsigned short int Ancho = 5, Longitud;
	Longitud = 10;

	// crear una variable de tipo unsigned short e inicializarla con el 
	// resultado de la multiplicación de Ancho por Longitud
	unsigned short int Area = (Ancho * Longitud);

	cout << "Ancho:" << Ancho << "\n";
	cout << "Longitud: " << Longitud << endl;
	cout << "Area: " << Area << endl;
	return 0;
}
