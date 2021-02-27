 // Listado 25.3 Clase NamedPipe (npipe.h)

 #ifndef C_NP_H
 #define C_NP_H

 #include <sys/types.h>
 #include <sys/stat.h>
 #include <stdio.h>
 #include "lst25-01.h" // #include "object.h"

 class NamedPipe : public Object
 {
 public:
	 NamedPipe();
	 ~NamedPipe();
	 int Create();
	 int Create(char * name);
	 int Destroy();
	 int Open();
	 int Close();
	 int Read(char * buf, int len);
	 int Write(char * buf, int len);
 private:
	 // no permitir la copia
	 NamedPipe & operator=(const NamedPipe &); 
	 bool init_;
	 FILE * fp_;
	 char * name_;
 };

 #endif
