 // Listado 24.9 Clase virtual pura Event (event.h)

 #ifndef C_EVENT_H
 #define C_EVENT_H

 class Event
 {
 public:
	 Event() {};
	 virtual ~Event() {};
	 virtual int Wait() = 0;
	 virtual int Signal() = 0;
 };

 #endif
