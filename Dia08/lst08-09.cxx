 // Listado 8.9
 // Muestra de un apuntador perdido
 
 #include <iostream.h>
 
 typedef unsigned short int USHORT;
 
 int main()
 {
	 USHORT * apInt = new USHORT;
	 *apInt = 10;
	 cout << "*apInt: " << *apInt << endl;
	 delete apInt;
	 
	 long * apLong = new long;
	 *apLong = 90000;
	 cout << "*apLong: " << *apLong << endl;
	 
	 *apInt = 20; // ¡caramba, éste fue eliminado!
	 
	 cout << "*apInt: " << *apInt << endl;
	 cout << "*apLong: " << *apLong << endl;
	 delete apLong;
	 return 0;
 }
