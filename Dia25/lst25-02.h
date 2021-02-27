 // Listado 25.2 Clase Pipe (pipe.h)

 #ifndef C_PIPE_H
 #define C_PIPE_H
 
 #include <unistd.h>
 #include "lst25-01.h" // #include "object.h"

 class Pipe : public Object
 {
 public:
	 Pipe();
	 ~Pipe();
	 int Create();
	 int Destroy();
	 void SetToRead();
	 void SetToWrite();
	 int ReadFromPipe(char *);
	 int WriteToPipe(char *);
 private:
	 // no permitir la copia 
	 Pipe & operator=(const Pipe &);
	 bool init_;
	 bool read_;
	 int pipe_[ 2 ];
 };

 #endif
