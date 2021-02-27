 // Listado 16.5 - Uso de get() con parámetros
 #include <iostream.h>
 
 int main()
 {
 	char a, b, c;
	 
 	cout << "Escriba tres letras: ";
 	cin.get(a).get(b).get(c);
	cout << "a: " << a << "\nb: " << b << "\nc: " << c << endl;
 	return 0;
 }
