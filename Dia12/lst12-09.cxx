 //Listado 12.9 uso de cin.get()

 #include <iostream.h>

 int main()
 {
	 char bufer[ 80 ];
	
	 cout << "Escriba la cadena: ";
	 cin.get(bufer, 79 ); // llegar hasta 79 o a newline
	 cout << "Aqu� est� el b�fer: " << bufer << endl;
	 return 0;
 }
