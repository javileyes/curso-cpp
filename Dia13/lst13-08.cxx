 class Figura
	 {
 public:
	 Figura(){}
	 ~Figura(){}
	 virtual long ObtenerArea() = 0; // error si se trata de instanciar
	 virtual long ObtenerPerim()= 0; // la clase Figura
	 virtual void Dibujar() = 0;
 private:
 };
