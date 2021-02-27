 // Listado 24.10 Clase variable de condición (cond.h)

 #ifndef C_COND_H
 #define C_COND_H

 #include <pthread.h>
 #include "lst24-09.h" //l#include "event.h"

 class CondVar : public Event
 {
 public:
	 CondVar();
	 virtual ~CondVar();
	 void Create();
	 void Destroy();
	 int Wait();
	 int Signal();
 private:
	 CondVar & operator= (const CondVar &); // no permitir la copia
	 pthread_cond_t cond;
	 pthread_condattr_t attr;
	 pthread_mutex_t mutex;
	 pthread_mutexattr_t mattr;
 };

 #endif
