 // Listado 24.1 Clase Process (process.h)

 #ifndef C_PROCESS_H
 #define C_PROCESS_H

 class Process
 {
 public:
	 Process();
	 ~Process();
	 void Create();
	 bool isParent() 
		 { return (pid != 0); }
	 bool isChild() 
		 { return (pid == 0); }
 private:
	 Process & operator= (const Process &); // no permitir la copia
	 int pid;
 };

 #endif
