 // Listado 25.14 Definici�n de una estructura shmid_ds

 struct shmid_ds 
 {
	 struct ipc_perm shm_perm; /* permisos de operaci�n */
	 int shm_segsz; /* tama�o del segmento (en bytes) */
	 __kernel_time_t shm_atime; /* �ltima uni�n */
	 __kernel_time_t shm_dtime; /* �ltima separaci�n */
	 __kernel_time_t shm_ctime; /* �ltimo cambio */
	 __kernel_ipc_pid_t shm_cpid; /* pid del creador */
	 __kernel_ipc_pid_t shm_lpid; /* pid del �ltimo operador */
	 unsigned short shm_nattch; /* n�m. de uniones actuales */
	 unsigned short shm_unused; /* compatibilidad */
	 void * shm_unused2; /* �dem - usado por DIPC */
	 void * shm_unused3; /* no utilizado */
};0
