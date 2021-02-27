 #include <iostream.h>
 // Archivo del listado lstr1-01.cxx

 enum OPCION { DibujaRect = 1, ObtenArea,
	       ObtenPerim, CambiaDimensiones, Salir};

 // Declaraci�n de clase Rectangulo 
 class Rectangulo
 {
 public:
 	// constructores
	 Rectangulo(int anchura, int altura);
	~Rectangulo();

	 // funciones de acceso
	 int ObtenAltura() const 
		{ return suAltura; }
	 int ObtenAnchura() const 
		{ return suAnchura; }
	 int ObtenArea() const 
		{ return suAltura * suAnchura; }
	 int ObtenPerim() const 
		{ return 2*suAltura + 2*suAnchura; }
	 void AsignaTamanio(int nuevaAnchura, int nuevaAltura);

	 // M�todos miscel�neos 


 private:
	 int suAnchura;
	 int suAltura;
 };

 // Implementaciones de los m�todos de la clase 
 void Rectangulo::AsignaTamanio(int nuevaAnchura, int nuevaAltura)
 {
	 suAnchura = nuevaAnchura;
	 suAltura = nuevaAltura;
 }


 Rectangulo::Rectangulo(int anchura, int altura)
 {
	 suAnchura = anchura;
	 suAltura = altura;
 }

 Rectangulo::~Rectangulo() {}

 int HacerMenu();
 void HacerDibujaRect(Rectangulo);
 void HacerDibujaArea(Rectangulo);
 void HacerDibujaPerim(Rectangulo);

 int main ()
 {
	 // inicializar un rect�ngulo con 30,5
	 Rectangulo elRect(30,5);

	 int opcion = DibujaRect;
	 int fSalir = false;

	 while (!fSalir)
	 {
		 opcion = HacerMenu();
		 if (opcion < DibujaRect || opcion > Salir)
		 {
			 cout << "\nOpci�n inv�lida, por favor intente de nuevo.\n\n";
			 continue;
		 }
		 switch (opcion)
		 {
			 case DibujaRect:
				 HacerDibujaRect(elRect);
				 break;
			 case ObtenArea:
				 HacerDibujaArea(elRect);
				 break;
			 case ObtenPerim:
				 HacerDibujaPerim(elRect);
				 break;
			 case CambiaDimensiones:
				 int nuevaLongitud, nuevaAnchura;
				 cout << "\nNueva anchura: ";
				 cin >> nuevaAnchura;
				 cout << "Nueva altura: ";
				 cin >> nuevaLongitud;
				 elRect.AsignaTamanio(nuevaAnchura, nuevaLongitud);
				 HacerDibujaRect(elRect);
				 break;
			 case Salir:
				 fSalir = true;
				 cout << "\nSaliendo...\n\n";
				 break;
			 default:
				 cout << "�Error en opci�n!\n";
				 fSalir = true;
				 break;
		 } // fin de switch
	 } // fin de while
	 return 0;
 } // fin de main

 int HacerMenu()
 {
	 int opcion;
	 cout << "\n\n *** Men� *** \n";
	 cout << "(1) Dibujar rect�ngulo\n";
	 cout << "(2) �rea\n";
	 cout << "(3) Per�metro\n";
	 cout << "(4) Cambiar tama�o\n";
	 cout << "(5) Salir\n";

	 cin >> opcion;
	 return opcion;
 }

 void HacerDibujaRect(Rectangulo elRect)
 {
	 int altura = elRect.ObtenAltura();
	 int anchura = elRect.ObtenAnchura();
	
	 for (int i = 0; i<altura; i++)
	 {
		 for (int j = 0; j< anchura; j++)
			 cout << "*";
		 cout << "\n";
	 }
 }


 void HacerDibujaArea(Rectangulo elRect)
 {
	 cout << "�rea: " << elRect.ObtenArea() << endl;
 }

 void HacerDibujaPerim(Rectangulo elRect)
 {
	 cout << "Per�metro: " << elRect.ObtenPerim() << endl;
 }
