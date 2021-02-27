 // Listado 25.6 Una estructura msqid 
 // para cada cola en el sistema 

 struct msqid_ds 
 {
	 struct ipc_perm msg_perm;
	 struct msg * msg_first; /* primer mensaje en la cola */
	 struct msg * msg_last; /* último mensaje en la cola */
	 __kernel_time_t msg_stime; /* última vez msgsnd */
	 __kernel_time_t msg_rtime; /* última vez msgrcv */
	 __kernel_time_t msg_ctime; /* último cambio */
	 struct wait_queue * wwait;
	 struct wait_queue * rwait;
	 unsigned short msg_cbytes; /* número actual de bytes en la cola */
	 unsigned short msg_qnum; /* número de mensajes en la cola */
	 unsigned short msg_qbytes; /* número máximo de bytes en la cola */ 
	 __kernel_ipc_pid_t msg_lspid; /* pid del último msgsnd */
	 __kernel_ipc_pid_t msg_lrpid; /* último pid de recepción */
 };
