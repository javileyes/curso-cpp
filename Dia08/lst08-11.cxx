 // Listado 8.11 Muestra el análisis sintáctico de 
 // palabras en una cadena de caracteres
 
 #include <iostream.h>
 #include <ctype.h>
 #include <string.h>
 
 bool ObtenerPalabra(char* cadena, 
 		     char* palabra, 
		     int & desplazamientoDePalabra);
 
 // programa controlador
 int main()
 {
	 const int tamBufer = 255;
	 char buffer[ tamBufer + 1 ]; // guardar toda la cadena
	 char palabra[ tamBufer + 1 ]; // guardar una palabra
	 int desplazamientoDePalabra = 0; // empezar al principio
	 
	 cout << "Escriba una cadena: ";
	 cin.getline(buffer, tamBufer);
	 while ( ObtenerPalabra( buffer, 
		  	        palabra, 
			        desplazamientoDePalabra) )
	 {
		 cout << "Obtuve esta palabra: " << palabra << endl;
	 }
	 return 0;
 }
 
 // función para analizar sintácticamente 
 // palabras de una cadena.
 bool ObtenerPalabra(char* cadena, 
		     char* palabra, 
		     int & desplazamientoDePalabra)
 {
	 // ¿es fin de cadena?
	 if (!cadena[ desplazamientoDePalabra ]) 
		 return false;
	 char * ap1, * ap2;
	 
	 // apuntar a la siguiente palabra
	 ap1 = ap2 = cadena + desplazamientoDePalabra;
	 
	 // saltarse los primeros espacios en blanco
	 for ( int i = 0; 
	       i < (int)strlen(ap1) && !isalnum(ap1[ 0 ]); 
	       i++ )
		 ap1++;
	 
	 // ver si se tiene una palabra
	 if (!isalnum(ap1[ 0 ]))
		 return false;
	 
	 // ap1 ahora apunta al inicio de la siguiente palabra
	 // hacer que ap2 apunte ahí también
	 ap2 = ap1; 
	 
	 // hacer que ap2 apunte al final de la palabra
	 while (isalnum(ap2[ 0 ]))
		 ap2++;
	 
	 // ap2 ahora se encuentra al final de la palabra
	 // ap1 está al principio de la palabra
	 // la longitud de la palabra es la diferencia
	 int len = int (ap2 - ap1);
	 
	 // copiar la palabra en el búfer
	 strncpy (palabra, ap1, len);
	 
	 // hacer que termine con el carácter nulo
	 palabra[ len ]='\0';
	 
	 // ahora encontrar el principio de la siguiente palabra
	 for ( int i = int(ap2 - cadena); 
	       i < (int)strlen(cadena) && !isalnum(ap2[ 0 ]); 
	       i++)
		 ap2++;
	 desplazamientoDePalabra = int(ap2 - cadena);
	 return true;
 } 
