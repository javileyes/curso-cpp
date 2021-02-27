 // Listado 25.4 Clase Key (key.h)

 #ifndef C_KEY_H
 #define C_KEY_H

 #include <sys/types.h>
 #include <sys/ipc.h>
 #include "lst25-01.h" // #include "object.h"

 class Key
 {
 public:
	 Key();
	 ~Key();
	 int Create(char * name, char id);
	 int Create(key_t key);
	 void Destroy();
	 key_t Get(void);
 private:
	 // no permitir la copia
	 Key & operator=(const Key &); 
	 bool init_;
	 key_t key_;
 };

 #endif
