 //Listado 9.2
 // Muestra del uso de referencias
 
 #include <iostream.h>
 
 int main()
 {
	 int intUno;
	 int & rUnaRef = intUno;
	 
	 intUno = 5;
	 cout << "intUno: " << intUno << endl;
	 cout << "rUnaRef: " << rUnaRef << endl;
	 
	 cout << "&intUno: " << &intUno << endl;
	 cout << "&rUnaRef: " << &rUnaRef << endl;
	 
	 return 0;
 }
