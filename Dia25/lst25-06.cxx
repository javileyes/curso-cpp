 // Listado 25.6 Una estructura msqid 
 // para cada cola en el sistema 

 struct msqid_ds 
 {
	 struct ipc_perm msg_perm;
	 struct msg * msg_first; /* primer mensaje en la cola */
	 struct msg * msg_last; /* �ltimo mensaje en la cola */
	 __kernel_time_t msg_stime; /* �ltima vez msgsnd */
	 __kernel_time_t msg_rtime; /* �ltima vez msgrcv */
	 __kernel_time_t msg_ctime; /* �ltimo cambio */
	 struct wait_queue * wwait;
	 struct wait_queue * rwait;
	 unsigned short msg_cbytes; /* n�mero actual de bytes en la cola */
	 unsigned short msg_qnum; /* n�mero de mensajes en la cola */
	 unsigned short msg_qbytes; /* n�mero m�ximo de bytes en la cola */ 
	 __kernel_ipc_pid_t msg_lspid; /* pid del �ltimo msgsnd */
	 __kernel_ipc_pid_t msg_lrpid; /* �ltimo pid de recepci�n */
 };
