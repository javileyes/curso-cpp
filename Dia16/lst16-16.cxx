 // Listado 16.16 - Lectura y escritura de archivos
 #include <fstream.h>
 
 int main()
 {
 	char nombreArchivo[ 80 ];
 	char bufer[ 255 ]; // para entrada del usuario
 
 	cout << "Nombre de archivo: ";
	cin >> nombreArchivo;
	ofstream fout(nombreArchivo); // abrir para escritura
	fout << "Esta línea se escribe directamente en el archivo...\n";
	cout << "Escriba el texto para el archivo: ";
	cin.ignore(1, '\n'); // elimina la nueva línea después del nombre Êdel archivo
	cin.getline(bufer, 255); // obtener la entrada del usuario
	fout << bufer << "\n"; // y escribirla en el archivo
	fout.close(); // cerrar el archivo, listo para volver a abrir
	 
	ifstream fin(nombreArchivo); // volver a abrir para lectura
	cout << "He aquí el contenido del archivo:\n";
	char ch;
	while (fin.get(ch))
 		cout << ch;
	 
	cout << "\n***Fin del contenido del archivo.***\n";
	 
	fin.close(); // siempre reditúa ser ordenado
 	return 0;
 }
