 // Listado 5.1 - Muestra el uso de los prototipos de funciones
 //
 #include <iostream.h>
 int Area(int longitud, int ancho); //prototipo de la funci�n

 int main()
 {
	 int longitudDeJardin;
	 int anchoDeJardin;
	 int areaDeJardin;

	 cout << "\n�Cu�l es el ancho de su jard�n? ";
	 cin >> anchoDeJardin;
	 cout << "\n�Cu�l es la longitud de su jard�n? ";
	 cin >> longitudDeJardin;

	 areaDeJardin= Area(longitudDeJardin,anchoDeJardin);

	 cout << "\nSu jard�n es de ";
	 cout << areaDeJardin;
	 cout << " metros cuadrados\n\n";
	 return 0;
 }

 int Area(int jardinLongitud, int jardinAncho)
 {
	 return jardinLongitud * jardinAncho;
 }
