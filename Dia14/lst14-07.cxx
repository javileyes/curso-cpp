 // Listado 14.7 Muestra del uso de un arreglo deapuntadores a funciones

 #include <iostream.h>

 void Cuadrado (int&,int&);
 void Cubo (int&, int&);
 void Intercambiar (int&, int &);
 void ObtenerValores(int&, int&);
 void ImprimirValores(int, int);

 int main()
 {
	 int valUno=1, valDos=2;
	 int opcion, i;
	 const int MaxArreglo = 5;
	 void (*apFuncArreglo[MaxArreglo])(int&, int&);
	
	 for (i=0;i<MaxArreglo;i++)
	 {
		 cout << "(1)Cambiar Valores (2)Cuadrado (3)Cubo (4)Intercambiar: ";
		 cin >> opcion;
		 switch (opcion)
		 {
			 case 1:
				apFuncArreglo[i] = ObtenerValores; 
				break;
			 case 2:
				apFuncArreglo[i] = Cuadrado; 
				break;
			 case 3:
				apFuncArreglo[i] = Cubo; 
				break;
			 case 4:
				apFuncArreglo[i] = Intercambiar; 
				break;
			 default:
				apFuncArreglo[i] = 0;
		 }
	 }
	
	 for (i=0;i<MaxArreglo; i++)
	 {
		 if (apFuncArreglo[i] == 0)
			 continue;
		 apFuncArreglo[i](valUno,valDos);
		 ImprimirValores(valUno,valDos);
	 }
	 return 0;
 }

 void ImprimirValores(int x, int y)
 {
	 cout << "x: " << x << " y: " << y << endl;
 }

 void Cuadrado (int & rX, int & rY)
 {
	 rX *= rX;
	 rY *= rY;
 }
 
 void Cubo (int & rX, int & rY)
 {
	 int tmp;
	 
	 tmp = rX;
	 rX *= rX;
	 rX = rX * tmp;
	
	 tmp = rY;
	 rY *= rY;
	 rY = rY * tmp;
 }

 void Intercambiar(int & rX, int & rY)
 {
	 int temp;
	 temp = rX;
	 rX = rY;
	 rY = temp;
 }

 void ObtenerValores (int & rValUno, int & rValDos)
 {
	 cout << "Nuevo valor para valUno: ";
	 cin >> rValUno;
	 cout << "Nuevo valor para valDos: ";
	 cin >> rValDos;
 }
