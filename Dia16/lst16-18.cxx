 // Listado 16.18 - 
 #include <fstream.h>
	 
 class Animal
 {
 public:
	 Animal(int peso, long dias) : 
	 suPeso(peso),
	 suNumeroDiasVivo(dias)
		 {}
	~Animal() {}
	int ObtenerPeso() const 
		{ return suPeso; }
	void AsignarPeso(int peso) 
		{ suPeso = peso; }
	long ObtenerDiasVivo() const 
		{ return suNumeroDiasVivo; }
	void AsignarDiasVivo(long dias) 
		{ suNumeroDiasVivo = dias; }
 private:
	int suPeso;
	long suNumeroDiasVivo;
 };
	 
 int main() // regresa 1 en caso de error
 {
	 char nombreArchivo[ 80 ];
	 
	 cout << "Escriba el nombre del archivo: ";
	 cin >> nombreArchivo;
	 ofstream fout(nombreArchivo, ios::binary);
	 if (!fout)
	 {
		 cout << "No se puede abrir" << nombreArchivo;
		 cout << " para escritura.\n";
		 return(1);
	 }
	 
	 Animal Oso(50, 100);
	 fout.write((char *) &Oso, sizeof Oso);
	 fout.close();
	 ifstream fin(nombreArchivo, ios::binary);
	 if (!fin)
	 {
		 cout << "No se puede abrir" << nombreArchivo;
		 cout << " para lectura.\n";
		 return(1);
	 }
	 
	 Animal OsoDos(1, 1);
	 cout << "OsoDos peso: " << OsoDos.ObtenerPeso() << endl;
	 cout << "OsoDos días: " << OsoDos.ObtenerDiasVivo() << endl;
	 fin.read((char*) &OsoDos, sizeof OsoDos);
	 cout << "OsoDos peso: " << OsoDos.ObtenerPeso() << endl;
	 cout << "OsoDos días: " << OsoDos.ObtenerDiasVivo() << endl;
	 fin.close();
	 return 0;
 }
