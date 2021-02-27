 // Listado 24.8 Ejemplo de productor/consumidor con Mutex

 #include <iostream.h>
 #include "lst24-04.h" // #include "tcreate.h"
 #include "lst24-07.h" // #include "mutex.h"
 
 int data;
 
 void read_thread(void * param)
 {
	 Mutex * apMutex = static_cast< Mutex * >(param);
	
	 while (1)
	 {
		 apMutex->Acquire();
		 cout << "leer: " << data << endl;
		 apMutex->Release();
	 }
 }

 void write_thread(void * param)
 {
	 Mutex * apMutex = static_cast< Mutex * >(param);
	
	 while(1)
	 {
		 apMutex->Acquire();
		 cout << "escribir: " << data++ << endl;
		 apMutex->Release();
	 }
 }

 int main(int argc, char** argv)
 {
	 Mutex lock;
	 Thread thread1((void*)&write_thread, &lock);
	 Thread thread2((void*)&read_thread, &lock);
	
	 lock.Create();
	 thread1.Create();
	 thread2.Create();
	 for (int i = 0; i < 100000; i++)
		 ;
	 lock.Destroy();
	 thread1.Destroy();
	 thread2.Destroy();
	 return 0;
 }
