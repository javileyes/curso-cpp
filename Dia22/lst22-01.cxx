 // Listado 22.1 Programa principal del juego Dado

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
 int tirarDado(void);

 int main(int argc, char * argv[])
 {
	 int i;
	 int iIter;
	 int Dado[ 6 ];
	
	 if (argc < 2) 
	 {
		 printf("Uso: %s n\n", argv[ 0 ]);
		 return 1;
	 }
	 iIter = atoi(argv[ 1 ]);
	 memset(Dado, 0, sizeof(Dado));
	 for(i = 0; i < iIter; i++) 
	 {
		 Dado[ tirarDado() - 1 ]++;
	 }
	 printf("%d tiradas\n", iIter);
	 printf("\tCara\tTiradas\n");
	 for(i = 0; i < 6; i++) 
	 {
		 printf("\t%d :\t%d\n", i + 1, Dado[ i ]);
	 }
 }
