 // Listado 25.7 Búfer de mensajes para 
 // las llamadas msgsnd y msgrcv 

 struct msgbuf 
 {
	 long mtype; /* tipo de mensaje */
	 char mtext[ 1 ]; /* texto del mensaje */
 };
