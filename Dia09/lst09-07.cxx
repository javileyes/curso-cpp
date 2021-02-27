 //Listado 9.7 Muestra del paso de par�metros por referencia
 // �uso de referencias!
 
 #include <iostream.h>
 
 void intercambiar(int & x, int & y);
 
 int main()
 {
	 int x = 5, y = 10;
	 
	 cout << "Main. Antes del intercambio, ";
	 cout << "x: " << x << " y: " << y << "\n";
	 intercambiar(x, y);
	 cout << "Main. Despu�s del intercambio, ";
	 cout << "x: " << x << " y: " << y << "\n";
	 return 0;
 }
 
 void intercambiar (int & rx, int & ry)
 {
	 int temp;
	 
	 cout << "Intercambiar. Antes del intercambio, ";
	 cout << "rx: " << rx << " ry: " << ry << "\n";
	 
	 temp = rx;
	 rx = ry;
	 ry = temp;
	 
	 cout << "Intercambiar. Despu�s del intercambio, ";
	 cout << "rx: " << rx << " ry: " << ry << "\n";
 }
