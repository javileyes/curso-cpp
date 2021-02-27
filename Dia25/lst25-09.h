 // Listado 25.9 Clase Message (message.h)

 #ifndef C_MESSAGE_H
 #define C_MESSAGE_H

 #include <sys/types.h>
 #include <sys/ipc.h>
 #include <sys/msg.h>
 #include "lst25-01.h" // #include "object.h"
 #include "lst25-04.h" // #include "key.h"

 class Message : public Object
 {
 public:
	 Message(Key k);
	 ~Message(void);
	 int Create(void);
	 int Create(int flags);
	 int Destroy(void);
	 virtual int Read(char * buf, int len, long type);
	 virtual int Write(char * buf, int len, long type);
 private:
	 // no permitir la copia
	 Message & operator=(const Message &); 
	 typedef struct
	 {
		 long type;
		 char * payload;
	 } TheMessage;
	 bool init_;
	 Key key_;
	 int msgqid_;
 };

 #endif
