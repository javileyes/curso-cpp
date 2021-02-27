 //Listado 7.16
 // Muestra de la instrucción switch

 #include <iostream.h>

 int main()
 {
	 unsigned short int numero;
	 cout << "Escriba un número entre 1 y 5: ";
	 cin >> numero;
	 switch (numero)
 {
	 case 0: 
		cout << "Demasiado pequeño, ¡lo siento!";
		break; 
	 case 5: 
		cout << "¡Buen trabajo!\n"; 
		// la ejecución pasa a la siguiente cláusula case
	 case 4: 
		cout << "¡Buena elección!\n"; 
		// la ejecución pasa a la siguiente cláusula case
	 case 3: 
		cout << "¡Excelente!\n"; 
		// la ejecución pasa a la siguiente cláusula case
	 case 2: 
		cout << "¡Magistral!\n"; 
		// la ejecución pasa a la siguiente cláusula case
	 case 1: 
		cout << "¡Increíble!\n";
		break;
	 default: 
		cout << "¡Demasiado grande!\n";
		break;
	 }
	 cout << "\n\n";
	 return 0;
 }
