 // Listado 21.3: Uso de una funci�n en l�nea en lugar de una macro

 #include <iostream.h>

 inline unsigned long Cuadrado(unsigned long a) 
			 { return a * a; }
 inline unsigned long Cubo(unsigned long a)
			 { return a * a * a; }


 int main()
 {
	 unsigned long x = 1 ;
	
	 for (;;)
	 {
		 cout << "Escriba un n�mero (0 para salir): ";
		 cin >> x;
		 if (x == 0)
			 break;
		 cout << "Usted escribi�: " << x;
		 cout << ". Cuadrado(" << x << "): ";
		 cout << Cuadrado(x);
		 cout<< ". Cubo(" << x << "): ";
		 cout << Cubo(x) << "." << endl;
	 }
	 return 0;
 }
