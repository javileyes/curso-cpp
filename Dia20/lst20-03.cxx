 // Listado 20.3: Jerarqu�as de clases y excepciones 

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
	 // m�todos de acceso
	 int ObtenersuTamanio() const 
		 { return suTamanio; }
	 // funci�n amiga 
	 friend ostream & operator<< (ostream &, const Arreglo &);
	 // definir las clases de excepciones
	 class xLimite {};
	 class xTamanio {};
	 class xMuyGrande : public xTamanio {};
	 class xMuyChico : public xTamanio {};
	 class xCero : public xMuyChico {};
	 class xNegativo : public xTamanio {};
 private:
	 int *apTipo;
	 int suTamanio;
 };

 Arreglo::Arreglo(int tamanio):
	 suTamanio(tamanio)
 {
	 if (tamanio == 0)
		 throw xCero();
	 if (tamanio > 30000)
		 throw xMuyGrande();
	 if (tamanio < 0)
		 throw xNegativo();
	 if (tamanio < 10)
		 throw xMuyChico();
	 apTipo = new int[ tamanio ];
	 for (int i = 0; i < tamanio; i++)
		 apTipo[ i ] = 0;
 }

 int & Arreglo::operator[](int desplazamiento)
 {
	 int tamanio = ObtenersuTamanio();
	
	 if (desplazamiento >= 0 && desplazamiento < ObtenersuTamanio())
		 return apTipo[ desplazamiento ];
	 throw xLimite();
	 // apaciguar a MFC
	 return apTipo[ 0 ];
 }

 const int & Arreglo::operator[](int desplazamiento) const
 {
	 int mitamanio = ObtenersuTamanio();
	
	 if (desplazamiento >= 0 && desplazamiento < ObtenersuTamanio())
		 return apTipo[ desplazamiento ];
	 throw xLimite();
	 // apaciguar a MFC
	 return apTipo[ 0 ];
 }

 int main()
 {
	 try
	 {
		 Arreglo arregloInt(0);
		
		 for (int j = 0; j < 100; j++)
		 {
			 arregloInt[ j ] = j;
			 cout << "arregloInt[" << j << "] est� bien...\n";
		 }
	 }
	 catch (Arreglo::xLimite)
	 {
		 cout << "�No se pudo procesar su entrada!\n";
	 }
	 catch (Arreglo::xMuyGrande)
	 {
		 cout << "Este arreglo es muy grande...\n";
	 } 
	 catch (Arreglo::xMuyChico)
	 {
		 cout << "Este arreglo es muy chico...\n";
	 }
	 catch (Arreglo::xCero)
	 {
		 cout << "�Pidi� un arreglo";
		 cout << " de cero objetos!\n";
	 }
	 catch (...)
	 {
		 cout << "�Algo sali� mal!\n";
	 }
	 cout << "Listo.\n";
	 return 0;
 }
