 // Listado 9.6 Muestra el paso por 
 // referencia simulado usando apuntadores
 
 #include <iostream.h>
 
 void intercambiar(int * x, int * y);
 
 int main()
 {
	 int x = 5, y = 10;
	 
	 cout << "Main. Antes del intercambio, ";
	 cout << "x: " << x << " y: " << y << "\n";
	 intercambiar(&x, &y);
	 cout << "Main. Después del intercambio, ";
	 cout << "x: " << x << " y: " << y << "\n";
	 return 0;
 }
 
 void intercambiar (int * apx, int * apy)
 {
	 int temp;
	 
	 cout << "Intercambiar. Antes del intercambio, ";
	 cout << "*apx: " << *apx << " *apy: " << *apy << "\n";
	 
	 temp = *apx;
	 *apx = *apy;
	 *apy = temp;
	 
	 cout << "Intercambiar. Después del intercambio, ";
	 cout << "*apx: " << *apx << " *apy: " << *apy << "\n";
 }
