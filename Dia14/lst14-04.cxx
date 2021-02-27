 //Listado 14.4 Funciones miembro estáticas

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
	 static int ObtenerCuantos() 
		{ return CuantosGatos; }
 private:
	 int suEdad;
	 static int CuantosGatos;
 };

 int Gato::CuantosGatos = 0;

 void FuncionTelepatica();

 int main()
 {
	 const int MaxGatos = 5;
	 Gato *CasaGatos[MaxGatos]; int i;
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
	 cout << "¡Hay " << Gato::ObtenerCuantos() << " gatos vivos!\n";
 }
