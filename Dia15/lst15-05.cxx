 // Listado 15.5 - Ejemplo de la delegación de responsabilidades 
 // a los miembros de una lista
 
 #include <iostream.h>
 
 
 // **************** Pieza ************
 // Clase base abstracta de piezas
 class Pieza
 {
 public:
	 Pieza() : suNumeroPieza(1) {}
	 Pieza(int NumeroPieza):
	 suNumeroPieza(NumeroPieza) {}
	 virtual ~Pieza() {}
	 int ObtenerNumeroPieza() const
		 { return suNumeroPieza; }
	 virtual void Desplegar() const = 0;
 private:
	 int suNumeroPieza;
 };
 
 // implementación de una función virtual pura para que
 // las clases derivadas se puedan encadenar
 void Pieza::Desplegar() const
 {
	 cout << "\nNúmero de pieza: " << suNumeroPieza << endl;
 }
 
 // **************** Pieza de Auto ************
 class PiezaAuto : public Pieza
 {
 public:
	 PiezaAuto() : suAnioModelo(94){}
	 PiezaAuto(int anio, int numeroPieza);
	 virtual void Desplegar() const
	 {
		 Pieza::Desplegar();
		 cout << "Año del modelo: ";
		 cout << suAnioModelo << endl;
	 }
 private:
	 int suAnioModelo;
 };
 
 PiezaAuto::PiezaAuto(int anio, int numeroPieza):
	 suAnioModelo(anio),
	 Pieza(numeroPieza)
 {}
 
 
 // **************** Pieza de AeroPlano ************
 class PiezaAeroPlano : public Pieza
 {
 public:
	 PiezaAeroPlano() : suNumeroMotor(1){};
	 PiezaAeroPlano(int NumeroMotor, int NumeroPieza);
	 virtual void Desplegar() const
	 {
		 Pieza::Desplegar();
		 cout << "Motor número: ";
		 cout << suNumeroMotor << endl;
	 }
 private:
	 int suNumeroMotor;
 };
 
 PiezaAeroPlano::PiezaAeroPlano(int NumeroMotor, int NumeroPieza):
	 suNumeroMotor(NumeroMotor),
	 Pieza(NumeroPieza)
 {}
 
 // **************** Nodo Pieza ************
 class NodoPieza
 {
 public:
	 NodoPieza(Pieza *);
	 ~NodoPieza();
	 void AsignarSiguiente(NodoPieza * nodo)
		 { suSiguiente = nodo; }
	 NodoPieza * ObtenerSiguiente() const;
	 Pieza * ObtenerPieza() const;
 private:
	 Pieza * suPieza;
	 NodoPieza * suSiguiente;
 };
 
 // Implementaciones de NodoPieza...
 NodoPieza::NodoPieza(Pieza * apPieza):
	 suPieza(apPieza),
	 suSiguiente(0)
 {}
 
 NodoPieza::~NodoPieza()
 {
	 delete suPieza;
	 suPieza = NULL;
	 delete suSiguiente;
	 suSiguiente = NULL;
 }
 
 // Regresa NULL si no hay NodoPieza siguiente
 NodoPieza * NodoPieza::ObtenerSiguiente() const
 {
	 return suSiguiente;
 }
 
 Pieza * NodoPieza::ObtenerPieza() const
 {
	 if (suPieza)
		 return suPieza;
	 else
		 return NULL; //error
 }
 
 // **************** Lista de Piezas ************
 class ListaPiezas
 {
 public:
	 ListaPiezas();
	 ~ListaPiezas();
	 // ¡necesita constructor de copia y operador igual a!
	 void Iterar(void (Pieza::*f)() const) const;
	 Pieza * Encontrar(int & posicion, int NumeroPieza) const;
	 Pieza * ObtenerPrimero() const;
	 void Insertar(Pieza *);
	 Pieza * operator[](int) const;
	 int ObtenerCuenta() const 
		 { return suCuenta; }
	 static ListaPiezas& ObtenerListaPiezasGlobal()
		 { return ListaPiezasGlobal; }
 private:
	 NodoPieza * apCabeza;
	 int suCuenta;
	 static ListaPiezas ListaPiezasGlobal;
 };
 
 ListaPiezas ListaPiezas::ListaPiezasGlobal;
 
 ListaPiezas::ListaPiezas():
	 apCabeza(0),
	 suCuenta(0)
 {}
 
 ListaPiezas::~ListaPiezas()
 {
	 delete apCabeza;
 }
 
 Pieza* ListaPiezas::ObtenerPrimero() const
 {
	 if (apCabeza)
		 return apCabeza->ObtenerPieza();
	 else
		 return NULL; // atrapar error aquí
 }
 
 Pieza * ListaPiezas::operator[](int desplazamiento) const
 {
	 NodoPieza * apNodo = apCabeza;
	 
	 if (!apCabeza)
		 return NULL; // atrapar error aquí
	 if (desplazamiento > suCuenta)
		 return NULL; // error
	 for (int i = 0; i < desplazamiento; i++)
		 apNodo = apNodo->ObtenerSiguiente();
	 return apNodo->ObtenerPieza();
 }
 
 Pieza* ListaPiezas::Encontrar(int & posicion, int NumeroPieza) const
 {
	 NodoPieza * apNodo = NULL;
	 
	 for (apNodo = apCabeza, posicion = 0;
		 apNodo!=NULL;
	 apNodo = apNodo->ObtenerSiguiente(), posicion++)
	 {
		 if (apNodo->ObtenerPieza()->ObtenerNumeroPieza() == NumeroPieza)
			 break;
	 }
	 if (apNodo == NULL)
		 return NULL;
	 else
		 return apNodo->ObtenerPieza();
 }
 
 void ListaPiezas::Iterar(void (Pieza::*func)() const) const
 {
	 if (!apCabeza)
		 return;
	 NodoPieza * apNodo = apCabeza;
	 do
		 (apNodo->ObtenerPieza()->*func)();
	 while (apNodo = apNodo->ObtenerSiguiente());
 }
 
 void ListaPiezas::Insertar(Pieza * apPieza)
 {
	 NodoPieza * apNodo = new NodoPieza(apPieza);
	 NodoPieza * apActual = apCabeza;
	 NodoPieza * apSiguiente = NULL;
	 int Nuevo = apPieza->ObtenerNumeroPieza();
	 int Siguiente = 0;
	 
	 suCuenta++;
	 if (!apCabeza)
	 {
		 apCabeza = apNodo;
		 return;
	 }
	 // si éste es más pequeño que el nodo cabeza
	 // entonces se convierte en el nuevo nodo cabeza
	 if (apCabeza->ObtenerPieza()->ObtenerNumeroPieza() > Nuevo)
	 {
		 apNodo->AsignarSiguiente(apCabeza);
		 apCabeza = apNodo;
		 return;
	 }
	 for (;;)
	 {
		 // si no hay siguiente, agregar éste 
		 if (!apActual->ObtenerSiguiente())
		 {
			 apActual->AsignarSiguiente(apNodo);
			 return;
		 }
		 // si va después de éste y antes del siguiente
		 // entonces insertarlo aquí, de no ser así 
		 // obtener el siguiente
		 apSiguiente = apActual->ObtenerSiguiente();
		 Siguiente = apSiguiente->ObtenerPieza()->ObtenerNumeroPieza();
		 if (Siguiente > Nuevo)
		 {
			 apActual->AsignarSiguiente(apNodo);
			 apNodo->AsignarSiguiente(apSiguiente);
			 return;
		 }
		 apActual = apSiguiente;
	 }
 }
 
 class CatalogoPiezas
 {
 public:
	 void Insertar(Pieza *);
	 int Existe(int NumeroPieza);
	 Pieza * Obtener(int NumeroPieza);
	 operator+(const CatalogoPiezas &);
	 void MostrarTodo() 
		 { laListaPiezas.Iterar(&Pieza::Desplegar); }
 private:
	 ListaPiezas laListaPiezas;
 };
 
 void CatalogoPiezas::Insertar(Pieza * nuevaPieza)
 {
	 int numeroPieza = nuevaPieza->ObtenerNumeroPieza();
	 int desplazamiento;
	 
	 if (!laListaPiezas.Encontrar(desplazamiento, numeroPieza))
		 laListaPiezas.Insertar(nuevaPieza);
	 else
	 {
		 cout << numeroPieza << " fue la ";
		 switch (desplazamiento)
		 {
			 case 0: cout << "primera "; 
				 break;
			 case 1: cout << "segunda "; 
				 break;
			 case 2: cout << "tercera "; 
				 break;
			 default: cout << desplazamiento+1 << "a ";
		 }
		 cout << "entrada. ¡Rechazada!\n";
	 }
 }
 
 int CatalogoPiezas::Existe(int NumeroPieza)
 {
	 int desplazamiento;
	 
	 laListaPiezas.Encontrar(desplazamiento,NumeroPieza);
	 return desplazamiento;
 }
 
 Pieza * CatalogoPiezas::Obtener(int NumeroPieza)
 {
	 int desplazamiento;
	 Pieza * laPieza = laListaPiezas.Encontrar(desplazamiento, NumeroPieza);
	 return laPieza;
 }
 
 
 int main()
 {
	 CatalogoPiezas cp;
	 Pieza * apPieza = NULL;
	 int NumeroPieza;
	 int valor;
	 int opcion;
	 
	 while (1)
	 {
		 cout << "(0)Salir (1)Auto (2)Avión: ";
		 cin >> opcion;
		 if (!opcion)
			 break;
		 cout << "¿Nuevo NumeroPieza?: ";
		 cin >> NumeroPieza;
		 if (opcion == 1)
		 {
			 cout << "¿Año del modelo?: ";
			 cin >> valor;
			 apPieza = new PiezaAuto(valor, NumeroPieza);
		 }
		 else
		 {
			 cout << "¿Número de motor?: ";
			 cin >> valor;
			 apPieza = new PiezaAeroPlano(valor, NumeroPieza);
		 }
		 cp.Insertar(apPieza);
	 }
	 cp.MostrarTodo();
	 return 0;
 }
