 // Listado 16.15 - Uso de printf()
 #include <stdio.h>
 
 int main()
 {
 	printf("%s", "¡Hola, mundo!\n");
	 
 	char * frase = "¡Hola de nuevo!\n";
 	printf("%s", frase);
	 
	int x = 5;
	printf("%d\n",x);
	 
	char * fraseDos = "He aquí algunos valores: ";
	char * fraseTres = " y aquí están otros: ";
	int y = 7, z = 35;
	long longVar = 98456;
	float floatVar = 8.8f;
	printf("%s %d %d %s %ld %f\n",fraseDos, y, z, fraseTres, longVar, floatVar);

	 
	char * fraseCuatro = "Con formato: ";
	printf("%s %5d %10d %10.5f\n", fraseCuatro, y, z, floatVar);
 	return 0;
 }
