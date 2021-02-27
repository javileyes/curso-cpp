 // Listado 25.1 Clase Object (object.h)

 #ifndef C_OBJECT_H
 #define C_OBJECT_H

 class Object
 {
 public:
	 virtual int Create() = 0;
	 virtual int Destroy() = 0;
 };

 #endif
