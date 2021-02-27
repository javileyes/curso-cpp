 //Listado 14.2 datos miembro estáticos

 #include <iostream.h>

 class Gato
 {
 public:
	 Gato(int edad):suEdad(edad)
		{CuantosGatos++; }
	 virtual ~Gato() 
		{ CuantosGatos--; }
	 virtual int ObtenerEdad() 
		{ return suEdad; }
	 virtual void AsignarEdad(int edad) 
		{ suEdad = edad; }
	 static int CuantosGatos;
 private:
	 int suEdad;
 };

 int Gato::CuantosGatos = 0;

 void FuncionTelepatica();

 int main()
 {
	 const int MaxGatos = 5; int i;
	 Gato *CasaGatos[MaxGatos];
	 for (i = 0; i<MaxGatos; i++)
	 {
		 CasaGatos[i] = new Gato(i);
		 FuncionTelepatica();
	 }
	
	 for (i = 0; i<MaxGatos; i++)
	 {
		 delete CasaGatos[i];
		 FuncionTelepatica();
	 }
	 return 0;
 }

 void FuncionTelepatica()
 {
	 cout << "¡Hay ";
	 cout << Gato::CuantosGatos << " gatos vivos!\n";
 }
