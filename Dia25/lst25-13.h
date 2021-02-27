 // Listado 25-13 Clase Semaphore (semap.h)

 #ifndef C_SEMAP_H
 #define C_SEMAP_H

 #include <sys/sem.h>
 #include "lst25-04.h" // #include "key.h"
 #include "lst25-01.h" // #include "object.h"

 class Semaphore : public Object
 {
 public:
	 Semaphore(Key);
	 ~Semaphore();
	 int Create();
	 int Create(int flags);
	 int Destroy();
	 int QueryValue();
	 int Acquire();
	 int Release();
 private:
	 // no permitir la copia
	 Semaphore & operator=(const Semaphore &); 
	 bool init_;
	 Key key_;
	 int semid_;
};

#endif
