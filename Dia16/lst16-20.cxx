 // Listado 16.20 - Ejemplo del manejo de los argumentos
 #include <fstream.h>
	 
 class Animal
 {
 public:
	 Animal(int peso, long dias):
	 suPeso(peso),
	 suNumeroDiasVivo(dias)
		 {}
	 ~Animal(){}
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
	 
 int main(int argc, char *argv[]) // regresa 1 en caso de error
 {
	 if (argc != 2)
	 {
		 cout << "Uso: " << argv[ 0 ];
		 cout << " <nombrearchivo>" << endl;
		 return(1);
	 }
	 ofstream fout(argv[ 1 ], ios::binary);
	 if (!fout)
	 {
		 cout << "No se puede abrir" << argv[1];
		 cout << " para escritura.\n";
		 return(1);
	 }
	 
	 Animal Oso(50, 100);
	 fout.write((char*) &Oso, sizeof Oso);
	 fout.close();
	 ifstream fin(argv[ 1 ], ios::binary);
	 if (!fin)
	 {
		 cout << "No se puede abrir" << argv[ 1 ];
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
