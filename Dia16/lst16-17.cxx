 //Listado 16.17 - Concatena texto al final de un archivo
 #include <fstream.h>
	 
 int main() // regresa 1 en caso de error
 {
 	char nombreArchivo[ 80 ];
 	char bufer[ 255 ];
	 
 	cout << "Vuelva a escribir el nombre del archivo: ";
	cin >> nombreArchivo;
	ifstream fin(nombreArchivo);
	if (fin) // ¿ya existe?
	{
		 cout << "Contenido actual del archivo:\n";
		 char ch;
		 while (fin.get(ch))
			 cout << ch;
		 cout << "\n***Fin del contenido del archivo.***\n";
	}
	fin.close();
	cout << "\nAbriendo " << nombreArchivo; 
	cout << " en modo agregar...\n";
	ofstream fout(nombreArchivo, ios::app);
	if (!fout)
	{
		 cout << "No se puede abrir" << nombreArchivo;
		 cout << " para agregar.\n";
		 return(1);
	}
	cout << "\nEscriba el texto para el archivo: ";
	cin.ignore(1, '\n');
	cin.getline(bufer, 255);
	fout << bufer << "\n";
	fout.close();
	fin.open(nombreArchivo); // ¡reasignar objeto fin existente!
	if (!fin)
	{
		 cout << "No se puede abrir" << nombreArchivo;
		 cout << " para lectura.\n";
		 return(1);
	 }
	 cout << "\nHe aquí el contenido del archivo:\n";
	 char ch;
	 while (fin.get(ch))
		 cout << ch;
	 cout << "\n***Fin del contenido del archivo.***\n";
	 fin.close();
	 return 0;
}
