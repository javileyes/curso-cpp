 // Listado 24.2 Clase Process (process1.h)

 #include <wait.h>
 #include <unistd.h>

 #ifndef C_PROCESS1_H
 #define C_PROCESS1_H

 class Process
 {
 public:
	 Process();
	 ~Process();
	 void Create();
	 int WaitForChild();
	 int RunProgram(char * program);
	 bool isParent() 
		 { return (pid != 0); }
	 bool isChild() 
		 { return (pid == 0); }
 private:
	 Process & operator= (const Process &); // no permitir la copia
	 int pid;
	 int wait_status;
	 int exec_status;
 };

 #endif
