 //Listado 7.16
 // Muestra de la instrucci�n switch

 #include <iostream.h>

 int main()
 {
	 unsigned short int numero;
	 cout << "Escriba un n�mero entre 1 y 5: ";
	 cin >> numero;
	 switch (numero)
 {
	 case 0: 
		cout << "Demasiado peque�o, �lo siento!";
		break; 
	 case 5: 
		cout << "�Buen trabajo!\n"; 
		// la ejecuci�n pasa a la siguiente cl�usula case
	 case 4: 
		cout << "�Buena elecci�n!\n"; 
		// la ejecuci�n pasa a la siguiente cl�usula case
	 case 3: 
		cout << "�Excelente!\n"; 
		// la ejecuci�n pasa a la siguiente cl�usula case
	 case 2: 
		cout << "�Magistral!\n"; 
		// la ejecuci�n pasa a la siguiente cl�usula case
	 case 1: 
		cout << "�Incre�ble!\n";
		break;
	 default: 
		cout << "�Demasiado grande!\n";
		break;
	 }
	 cout << "\n\n";
	 return 0;
 }
