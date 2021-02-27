
 // Listado 25.15 Clase para memoria compartida (smem.h)

 #ifndef C_SMEM_H
 #define C_SMEM_H

 #include <sys/shm.h>
 #include <string.h>
 #include "lst25-04.h" // #include "key.h"
 #include "lst25-01.h" // #include "object.h"

 class SharedMemory : public Object
 {
 public:
	 SharedMemory(Key k);
	 ~SharedMemory();
	 int Create();
	 int Create(int flags, int size);
	 int Destroy();
	 char * Attach();
	 void Detach();
	 int Read(char * buf, int len, int offset);
	 int Write(char * buf, int len, int offset);
 private:
	 // no permitir la copia
	 SharedMemory & operator=(const SharedMemory &);
	 bool init_;
	 Key key_;
	 int shmid_;
	 char * shmaddr_;
 };

 #endif
