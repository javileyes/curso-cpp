 //Listado 10.2 Valores predeterminados en funciones miembro
 
 #include <iostream.h>
 
 // Declaraci�n de la clase Rectangulo
 class Rectangulo
 {
 public:
	 // constructores
	 Rectangulo(int ancho, int altura);
	 ~Rectangulo(){}
	 void DibujarFigura(int unAncho, int unaAltura, 
	 bool UsarValsActuales = false) const;
 private:
	 int suAncho;
	 int suAltura;
 };
 
 //Implementaci�n del constructor
 Rectangulo::Rectangulo(int ancho, int altura):
	 suAncho(ancho), // inicializaciones
	 suAltura(altura)
 {} // cuerpo vac�o
 
 
 // valores predeterminados usados para el tercer par�metro
 void Rectangulo::DibujarFigura(int ancho, int altura,
 bool UsarValActual) const
 {
	 int imprimeAncho;
	 int imprimeAltura;
	 
	 if (UsarValActual == true)
	 { 
		 // usar los valores actuales de la clase
		 imprimeAncho = suAncho;
		 imprimeAltura = suAltura;
	 }
	 else
	 { 
		 // usar valores de los par�metros
		 imprimeAncho = ancho;
		 imprimeAltura = altura;
	 }
	 for (int i = 0; i < imprimeAltura; i++)
	 {
		 for (int j = 0; j < imprimeAncho; j++)
		 {
			 cout << "*";
		 }
		 cout << "\n";
	 }
 }
 
 // Programa controlador para mostrar las funciones sobrecargadas
 int main()
 {
	 // inicializar un rect�ngulo con 30,5
	 Rectangulo elRect(30, 5);
	 cout << "DibujarFigura(0, 0, true)...\n";
	 elRect.DibujarFigura(0, 0, true);
	 cout << "DibujarFigura(40, 2)...\n";
	 elRect.DibujarFigura(40, 2);
	 return 0;
 }
