 // Listado 24.7 Clase Mutex (mutex.h)

 #ifndef C_MUTEX_H
 #define C_MUTEX_H

 #include <pthread.h>
 #include "lst24-06.h" //#include "synclock.h"

 class Mutex: public SyncLock
 {
 public:
	 Mutex(); // ctor/dtor
	 ~Mutex();
	 int Create();
	 int Destroy();
	 int Acquire(); // obtener el bloqueo
	 int Release(); // liberar el bloqueo
 private:
	 Mutex & operator= (const Mutex &); // no permitir la copia
	 bool init;
	 pthread_mutex_t mutex;
	 pthread_mutexattr_t attr;
 };

 #endif
