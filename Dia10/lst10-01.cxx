 // Listado 10.1 Sobrecarga de funciones
 // miembro de una clase
 
 #include <iostream.h>
 
 // Declaraci�n de la clase Rectangulo 
 class Rectangulo
 {
 public:
	 // constructores
	 Rectangulo(int ancho, int altura);
	 ~Rectangulo(){}
	 // funci�n DibujarFigura() sobrecargada de la clase
	 void DibujarFigura() const;
	 void DibujarFigura(int unAncho, int unaAltura) const;
 private:
	 int suAncho;
	 int suAltura;
 };
 
 //Implementaci�n del constructor
 Rectangulo::Rectangulo(int ancho, int altura)
 {
	 suAncho = ancho;
	 suAltura = altura;
 }
 
 // Funci�n DibujarFigura sobrecargada - no toma valores
 // Dibuja con base en los valores miembro actuales de la clase
 void Rectangulo::DibujarFigura() const
 {
	 DibujarFigura(suAncho, suAltura);
 }
 
 // Funci�n DibujarFigura sobrecargada - toma dos valores 
 // dibuja la figura con base en los par�metros
 void Rectangulo::DibujarFigura(int ancho, int altura) const
 {
	 for (int i = 0; i < altura; i++)
	 {
		 for (int j = 0; j < ancho; j++)
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
	 cout << "DibujarFigura(): \n";
	 elRect.DibujarFigura();
	 cout << "\nDibujarFigura(40, 2): \n";
	 elRect.DibujarFigura(40, 2);
	 return 0;
 }
