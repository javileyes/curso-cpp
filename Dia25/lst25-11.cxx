 // Listado 25.11 Las llamadas de sistema semop
 // toman un arreglo de �stos. 

 struct sembuf 
 {
	 unsigned short sem_num; /* �ndice de sem�foro del arreglo */
	 short sem_op; /* operaci�n del sem�foro */
	 short sem_flg; /* indicadores de operaci�n */
 };
