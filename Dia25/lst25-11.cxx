 // Listado 25.11 Las llamadas de sistema semop
 // toman un arreglo de éstos. 

 struct sembuf 
 {
	 unsigned short sem_num; /* índice de semáforo del arreglo */
	 short sem_op; /* operación del semáforo */
	 short sem_flg; /* indicadores de operación */
 };
