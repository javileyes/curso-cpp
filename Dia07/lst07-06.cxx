 // Listado 7.6
 // Muestra c�mo se salta el cuerpo del
 // ciclo while cuando la condici�n es falsa.

 #include <iostream.h>

 int main()
 {
 	int contador;
 	cout << "�Cu�ntos holas?: ";
 	cin >> contador;
 	while (contador > 0)
 {
 	cout << "�Hola!\n";
 	contador--;
 	}
 	 cout << "Contador vale: " << contador << endl;
 	return 0;
 }
