 // Listado 20.5: Paso de valores por referencia en las excepciones

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
	 friend ostream & operator<<(ostream &, const Arreglo &);
	 // definir las clases de excepciones
	 class xLimite {};
	 class xTamanio
	 {
	 public:
		 xTamanio(int tamanio) : suTamanio(tamanio) {}
		 ~xTamanio() {}
		 virtual int ObtenerTamanio() 
			 { return suTamanio; }
		 virtual void ImprimirError()
		 {
			 cout << "Error en tamaño. Se recibieron: ";
			 cout << suTamanio << endl;
		 }
	 protected:
		 int suTamanio;
	 };
	 class xMuyGrande : public xTamanio
	 {
	 public:
		 xMuyGrande(int tamanio) : xTamanio(tamanio) {}
		 virtual void ImprimirError()
		 {
			 cout << "¡Muy grande! Se recibieron: ";
			 cout << xTamanio::suTamanio << endl;
		 }
	 };
	 class xMuyChico : public xTamanio
	 {
	 public:
		 xMuyChico(int tamanio) : xTamanio(tamanio) {}
		 virtual void ImprimirError()
		 {
			 cout << "¡Muy chico! Se recibieron: ";
			 cout << xTamanio::suTamanio << endl;
		 }
	 };
	 class xCero : public xMuyChico
	 {
	 public:
		 xCero(int tamanio) : xMuyChico(tamanio) {}
		 virtual void ImprimirError()
		 {
			 cout << "¡Cero!. Se recibieron: " ;
			 cout << xTamanio::suTamanio << endl;
		 }
	 };
	 class xNegativo : public xTamanio
	 {
	 public:
		 xNegativo(int tamanio) : xTamanio(tamanio) {}
		 virtual void ImprimirError()
		 {
			 cout << "¡Negativo! Se recibieron: ";
			 cout << xTamanio::suTamanio << endl;
		 }
	 };
 private:
	 int * apTipo;
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
			 cout << "arregloInt[" << j << "] está bien...\n";
		 }
	 }
	 catch (Arreglo::xLimite)
	 {
		 cout << "¡No se pudo procesar su entrada!\n";
	 }
	 catch (Arreglo::xTamanio & laExcepcion)
	 {
		 laExcepcion.ImprimirError();
	 }
	 catch (...)
	 {
		 cout << "¡Algo salió mal!\n";
	 }
	 cout << "Listo.\n";
	 return 0;
 }
