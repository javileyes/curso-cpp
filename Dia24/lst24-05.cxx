 // Listado 24.5 Ejemplo de productor/consumidor

 #include <iostream.h>
 #include "lst24-04.h" //#include "tcreate.h"

 int data = 0;

 void read_thread(void * param)
 {
	 while (1)
		 cout << "leer: " << data << endl;
 }

 void write_thread(void * param)
 {
	 while (1)
		 cout << "escribir: " << data++ << endl;
 }

 int main(int argc, char** argv)
 {
	 Thread thread1((void*)&write_thread, NULL);
	 Thread thread2((void*)&read_thread, NULL);
	
	 thread1.Create();
	 thread2.Create();
	 for (int i = 0; i < 10000; i++)
		 ;
	 thread1.Destroy();
	 thread2.Destroy();
 }
