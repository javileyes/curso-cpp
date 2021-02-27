 // Listado 24.4 Clase Thread (tcreate.h)

 #ifndef C_TCREATE_H
 #define C_TCREATE_H

 #include <pthread.h>

 class Thread
 {
 public:
	 Thread(void * r, void * a); // ctor/dtor
	 virtual ~Thread();
	 int Create(); // crea el subproceso
	 int Destroy(); // sale del subproceso
 private:
	 Thread & operator= (const Thread &); // no permitir la copia
	 pthread_t thread;
	 pthread_attr_t attr;
	 void * fn;
	 void * fn_args;
	 bool init;
 };

 #endif
