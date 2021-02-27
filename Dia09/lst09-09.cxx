 //Listado 9.9 Regreso de varios valores de 
 // una funci�n por medio de referencias
 
 #include <iostream.h>
 
 typedef unsigned short USHORT;
 enum CODIGO_ERR { EXITO, ERROR };
 
 CODIGO_ERR Factor(USHORT, USHORT &, USHORT &);
 
 int main()
 {
	 USHORT numero, alcuadrado, alcubo;
	 CODIGO_ERR resultado;
	 
	 cout << "Escriba un n�mero (0 - 20): ";
	 cin >> numero;
	 
	 resultado = Factor(numero, alcuadrado, alcubo);
	 
	 if (resultado == EXITO)
	 {
		 cout << "n�mero: " << numero << "\n";
		 cout << "al cuadrado: " << alcuadrado << "\n";
		 cout << "al cubo: " << alcubo << "\n";
	 }
	 else
		 cout << "�Se encontr� un error!!\n";
	 return 0;
 }
 
 CODIGO_ERR Factor(USHORT n, USHORT & rAlCuadrado, USHORT & rAlCubo)
 {
	 if (n > 20)
		 return ERROR; // codigo simple de error
	 else
	 {
		 rAlCuadrado = n * n;
		 rAlCubo = n * n * n;
		 return EXITO;
	 }
 }
