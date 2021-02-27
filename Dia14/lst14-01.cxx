 //Listado 14.1 datos miembro estáticos

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

 int main()
 {
	 const int MaxGatos = 5; int i;
	 Gato *CasaGatos[MaxGatos];
	 for (i = 0; i<MaxGatos; i++)
		 CasaGatos[i] = new Gato(i);
	
	 for (i = 0; i<MaxGatos; i++)
	 {
		 cout << "¡Quedan ";
		 cout << Gato::CuantosGatos;
		 cout << " gatos!\n";
		 cout << "Se va a eliminar el que tiene ";
		 cout << CasaGatos[i]->ObtenerEdad();
		 cout << " años de edad\n";
		 delete CasaGatos[i];
		 CasaGatos[i] = 0;
	 }
	 return 0;
 }
