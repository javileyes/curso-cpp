// Listado 25.12 Muestra el uso de la llamada
// de sistema semop()

int Semaphore::Acquire()
{
	// probar el semáforo y decrementar
	static struct sembuf lock[ 1 ] = { { 0, 1, IPC_NOWAIT } };
	
	int len = sizeof(lock) / sizeof(struct sembuf);
	int stat = semop(semid_, lock, len);
	return stat;
}
