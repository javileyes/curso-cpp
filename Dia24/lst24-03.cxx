 // Listado 24.3 Ejemplo de control de procesos

 #include "lst24-02.h" //#include "process1.h"

 int main(int argc, char** argv)
 {
	 Process p;
	 char * program = "ls";
	
	 p.Create();
	 if (p.isParent())
		 p.WaitForChild();
	 else if (p.isChild())
		 p.RunProgram(program);
	 return 0;
 }
