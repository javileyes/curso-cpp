 // Inicio de lst06-07.hpp
 #include <iostream.h>
 class Punto // guarda las coordenadas (x, y)
 {
 // no hay constructor, usar el predeterminado
 public:
	 void AsignarX(int x) { suX = x; }
	 void AsignarY(int y) { suY = y; }
	 int ObtenerX() const { return suX;}
	 int ObtenerY() const { return suY;}
 private:
	 int suX;
	 int suY;
 }; // fin de la declaración de la clase Punto


 class Rectangulo
 {
 public:
	 Rectangulo (int superior, int izquierdo, int inferior, int derecho);
	 ~Rectangulo () {}

	 int ObtenerSuperior() const { return suSuperior; }
	 int ObtenerIzquierdo() const { return suIzquierdo; }
	 int ObtenerInferior() const { return suInferior; }
	 int ObtenerDerecho() const { return suDerecho; }

	 Punto ObtenerSupIzq() const { return suSupIzq; }
	 Punto ObtenerInfIzq() const { return suInfIzq; }
	 Punto ObtenerSupDer() const { return suSupDer; }
	 Punto ObtenerInfDer() const { return suInfDer; }

	 void AsignarSupIzq(Punto Ubicacion) {suSupIzq = Ubicacion;}
	 void AsignarInfIzq(Punto Ubicacion) {suInfIzq = Ubicacion;}
	 void AsignarSupDer(Punto Ubicacion) {suSupDer = Ubicacion;}
	 void AsignarInfDer(Punto Ubicacion) {suInfDer = Ubicacion;}

	 void AsignarSuperior(int superior) { suSuperior = superior; }
	 void AsignarIzquierdo (int izquierdo) { suIzquierdo = izquierdo; }
	 void AsignarInferior (int inferior) { suInferior = inferior; }
	 void AsignarDerecho (int derecho) { suDerecho = derecho; }

	 int ObtenerArea() const;

 private:
	 Punto suSupIzq;
	 Punto suSupDer;
	 Punto suInfIzq;
	 Punto suInfDer;
	 int suSuperior;
	 int suIzquierdo;
	 int suInferior;
	 int suDerecho;
 };
