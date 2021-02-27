 // Listado 14.6 Sin apuntadores a funciones

 #include <iostream.h>

 void Cuadrado (int&,int&);
 void Cubo (int&, int&);
 void Intercambiar (int&, int &);
 void ObtenerValores(int&, int&);
 void ImprimirValores(int, int);

 int main()
 {
	 bool fSalir = false;
	 int valUno=1, valDos=2;
	 int opcion;
	 while (fSalir == false)
	 {
		 cout << "(0)Salir (1)Cambiar Valores (2)Cuadrado (3)Cubo (4)Intercambiar: ";
		 cin >> opcion;
		 switch (opcion)
		 {
			 case 1:
				 ImprimirValores(valUno, valDos);
				 ObtenerValores(valUno, valDos);
				 ImprimirValores(valUno, valDos);
				 break;
			
			 case 2:
				 ImprimirValores(valUno, valDos);
				 Cuadrado(valUno,valDos);
				 ImprimirValores(valUno, valDos);
				 break;
			
			 case 3:
				 ImprimirValores(valUno, valDos);
				 Cubo(valUno, valDos);
				 ImprimirValores(valUno, valDos);
				 break;
			
			 case 4:
				 ImprimirValores(valUno, valDos);
				 Intercambiar(valUno, valDos);
				 ImprimirValores(valUno, valDos);
				 break;
			
			 default :
				 fSalir = true;
				 break;
		 }
		 
		 if (fSalir)
			 break;
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
