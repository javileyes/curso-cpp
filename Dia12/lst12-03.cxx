 // Listado 12.3
 // Cómo dimensionar arreglos con constantes y enumeraciones

 #include <iostream.h>

 int main()
 {
	 enum SemanaDias { Dom, Lun, Mar, Mie, Jue, 
	 	           Vie, Sab, DiasDeLaSemana };
	
	 int ArregloSemana[ DiasDeLaSemana ] = { 10, 20, 30, 40, 50, 60, 70 };
	
	 cout << "El valor de Jueves es: " << ArregloSemana[ Jue ] << endl;
	 return 0;
 }
