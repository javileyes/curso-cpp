 // Listado 24.6 Clase virtual pura SyncLock (synclock.h)

 #ifndef C_SYNCLOCK_H
 #define C_SYNCLOCK_H

 class SyncLock
 {
 public:
	 SyncLock() {} ;
	 ~SyncLock() {};
	 virtual int Acquire() = 0;
	 virtual int Release() = 0;
 private:
	 SyncLock & operator= (const SyncLock &); // no permitir la copia
 };

 #endif
