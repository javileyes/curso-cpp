 // Listado 20.4: Obtención de los datos de un objeto de excepción

 #include <iostream.h>

 const int TamanioPredet = 10;


 class Arreglo
 {
 public:
	 // constructores
	 Arreglo(int suTamanio = TamanioPredet);
	 Arreglo(const Arreglo & rhs);
	 ~Arreglo() 
		 { delete [] apTipo; }
	 // operadores
	 Arreglo & operator=(const Arreglo &);
	 int & operator[](int desplazamiento);
	 const int & operator[](int desplazamiento) const;
	 // métodos de acceso
	 int ObtenersuTamanio() const 
		 { return suTamanio; }
	 // función amiga
	 friend ostream & operator<< (ostream &, const Arreglo &);
	 // definir las clases de excepciones
	 class xLimite {};
	 class xTamanio
	 {
	 public:
		 xTamanio(int tamanio) : suTamanio(tamanio) {}
		 ~xTamanio(){}
		 int ObtenerTamanio() 
			 { return suTamanio; }
	 private:
		 int suTamanio;
	 };
	 class xMuyGrande : public xTamanio
	 {
	 public:
		 xMuyGrande(int tamanio) : xTamanio(tamanio) {}
	 };
	 class xMuyChico : public xTamanio
	 {
	 public:
		 xMuyChico(int tamanio) : xTamanio(tamanio) {}
	 };
	 class xCero : public xMuyChico
	 {
	 public:
		 xCero(int tamanio) : xMuyChico(tamanio) {}
	 };
	 class xNegativo : public xTamanio
	 {
	 public:
		 xNegativo(int tamanio) : xTamanio(tamanio) {}
	 };
 private:
	 int *apTipo;
	 int suTamanio;
 };


 Arreglo::Arreglo(int tamanio):
	 suTamanio(tamanio)
 {
	 if (tamanio == 0)
		 throw xCero(tamanio);
	 if (tamanio > 30000)
		 throw xMuyGrande(tamanio);
	 if (tamanio < 0)
		 throw xNegativo(tamanio);
	 if (tamanio < 10)
		 throw xMuyChico(tamanio);
	 apTipo = new int[ tamanio ];
	 for (int i = 0; i < tamanio; i++)
		 apTipo[ i ] = 0;
 }

 int & Arreglo::operator[] (int desplazamiento)
 {
	 int tamanio = ObtenersuTamanio();
	
	 if (desplazamiento >= 0 && desplazamiento < ObtenersuTamanio())
		 return apTipo[ desplazamiento ];
	 throw xLimite();
	 return apTipo[0];
 }

 const int & Arreglo::operator[] (int desplazamiento) const
 {
	 int tamanio = ObtenersuTamanio();
	
	 if (desplazamiento >= 0 && desplazamiento < ObtenersuTamanio())
		 return apTipo[ desplazamiento ];
	 throw xLimite();
	 return apTipo[ 0 ];
 }

 int main()
 {
	 try
	 {
		 Arreglo arregloInt(9);
		
		 for (int j = 0; j < 100; j++)
		 {
			 arregloInt[ j ] = j;
			 cout << "arregloInt[" << j << "] está bien..." << endl;
		 }
	 }
	 catch (Arreglo::xLimite)
	 {
		 cout << "¡No se pudo procesar su entrada!\n";
	 }
	 catch (Arreglo::xCero laExcepcion)
	 {
		 cout << "¡Pidió un arreglo de cero objetos!" << endl;
		 cout << "Se recibieron ";
		 cout << laExcepcion.ObtenerTamanio() << endl;
	 }
	 catch (Arreglo::xMuyGrande laExcepcion)
	 {
		 cout << "Este Arreglo es muy grande..." << endl;
		 cout << "Se recibieron ";
		 cout << laExcepcion.ObtenerTamanio() << endl;
	 }
	 catch (Arreglo::xMuyChico laExcepcion)
	 {
		 cout << "Este Arreglo es muy chico..." << endl;
		 cout << "Se recibieron ";
		 cout << laExcepcion.ObtenerTamanio() << endl;
	 }
	 catch (...)
	 {
		 cout << "Algo salió mal,";
		 cout << " pero ¡no tengo idea de qué fue!\n";
	 }
	 cout << "Listo.\n";
	 return 0;
 }
