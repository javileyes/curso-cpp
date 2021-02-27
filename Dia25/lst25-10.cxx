 // Listado 25.10 Una estructura de datos semid para 
 // cada conjunto de semáforos del sistema. 

 struct semid_ds 
 {
	 struct ipc_perm sem_perm; /* permisos .. ver ipc.h */
	 __kernel_time_t sem_otime; /* última vez semop */
	 __kernel_time_t sem_ctime; /* último cambio */
	 struct sem * sem_base; /* apuntador al primer semáforo del arreglo */
	 struct sem_queue * sem_pending; /* operaciones pendientes de procesar */
	 struct sem_queue ** sem_pending_last; /* última operación pendiente */
	 struct sem_undo * undo; /* solicitudes para deshacer en este arreglo */
	 unsigned short sem_nsems; /* núm. de semáforos del arreglo */
 };
