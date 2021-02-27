 // Listado 25.8 Estructura de muestra para mensajes IPC

 typedef struct ipc_message
 {
	 long mtype;
	 long header
	 char payload[ 8 ];
 } ipc_message;
