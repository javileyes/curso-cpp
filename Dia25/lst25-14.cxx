 // Listado 25.14 Definición de una estructura shmid_ds

 struct shmid_ds 
 {
	 struct ipc_perm shm_perm; /* permisos de operación */
	 int shm_segsz; /* tamaño del segmento (en bytes) */
	 __kernel_time_t shm_atime; /* última unión */
	 __kernel_time_t shm_dtime; /* última separación */
	 __kernel_time_t shm_ctime; /* último cambio */
	 __kernel_ipc_pid_t shm_cpid; /* pid del creador */
	 __kernel_ipc_pid_t shm_lpid; /* pid del último operador */
	 unsigned short shm_nattch; /* núm. de uniones actuales */
	 unsigned short shm_unused; /* compatibilidad */
	 void * shm_unused2; /* ídem - usado por DIPC */
	 void * shm_unused3; /* no utilizado */
};0
