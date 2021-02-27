 // Listado 5.5 - muestra de parámetros pasados por valor

 #include <iostream.h>

 void intercambiar(int x, int y);

 int main()
 {
	 int x = 5, y = 10;
	 cout << "main(). Antes del intercambio, x: " << x << " y: " << y << "\n";
	 intercambiar(x,y); cout << "main(). Después del intercambio, x: " << x << " y: " << y << "\n";
	 return 0;
 }

 void intercambiar (int x, int y)
 {
	 int temp;
	 cout << "Intercambiar(). Antes del intercambio, x: " << x << " y: " << y << "\n";
	
	 temp = x;
	 x = y;
	 y = temp;
	 cout << "Intercambiar(). Después del intercambio, x: " << x << " y: " << y << "\n";
	
 }
