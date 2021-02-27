 // Listado 21.2 Expansión de macros

 #include <iostream.h>
 #define CUBO(a) 	((a) * (a) * (a))
 #define TRIPLE(a) 	a * a * a


 int main()
 {
	 long x = 5;
	 long y = CUBO(x);
	 long z = TRIPLE(x);
	
	 cout << "y: " << y << endl;
	 cout << "z: " << z << endl;
	
	 long a = 5, b = 7;
	 y = CUBO(a + b);
	 z = TRIPLE(a + b);
	
	 cout << "y: " << y << endl;
	 cout << "z: " << z << endl;
	 return 0;
 }
