 // Listado 5.1 - Muestra el uso de los prototipos de funciones
 //
 #include <iostream.h>
 int Area(int longitud, int ancho); //prototipo de la función

 int main()
 {
	 int longitudDeJardin;
	 int anchoDeJardin;
	 int areaDeJardin;

	 cout << "\n¿Cuál es el ancho de su jardín? ";
	 cin >> anchoDeJardin;
	 cout << "\n¿Cuál es la longitud de su jardín? ";
	 cin >> longitudDeJardin;

	 areaDeJardin= Area(longitudDeJardin,anchoDeJardin);

	 cout << "\nSu jardín es de ";
	 cout << areaDeJardin;
	 cout << " metros cuadrados\n\n";
	 return 0;
 }

 int Area(int jardinLongitud, int jardinAncho)
 {
	 return jardinLongitud * jardinAncho;
 }
