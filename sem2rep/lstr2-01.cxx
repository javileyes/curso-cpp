 // **************************************************
 //
 // Título:	Revisión de la semana 2
 //
 // Archivo:	Semana2
 // 
 // Descripción: Proporcionar un programa de demostración de listas enlazadas
 // 
 // Clases:	Pieza - guarda números de pieza y potencialmente cualquier otra 
 //
 // información relacionada con las piezas
 //
 // NodoPieza - actúa como nodo en una ListaPiezas
 //
 // ListaPiezas - provee los mecanismos para una lista Âenlazada
 //
 //
 // **************************************************
 
 #include <iostream.h>
 
 
 
 // **************** Pieza ************
 // Clase base abstracta de piezas
 class Pieza
 {
 public:
 	Pieza() : suNumeroPieza(1) {}
	 Pieza(int NumeroPieza) : suNumeroPieza(NumeroPieza) {}
	 virtual ~Pieza() {};
	 int ObtenerNumeroPieza() const 
		{ return suNumeroPieza; }
	 virtual void Desplegar() const = 0; // debe redefinirse
 private:
	 int suNumeroPieza;
 };
 
 // implementación de la función virtual pura para que
 // las clases derivadas puedan encadenarse
 void Pieza::Desplegar() const
 {
	 cout << "\nNúmero de pieza: " << suNumeroPieza << endl;
 }
 
 // **************** Pieza de Auto ************
 class PiezaAuto : public Pieza
 {
 public:
	 PiezaAuto() : suAnioModelo(94) {}
	 PiezaAuto(int anio, int numeroPieza);
	 virtual void Desplegar() const
	 {
		 Pieza::Desplegar(); cout << "Año del modelo: ";
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
	 PiezaAeroPlano() : suNumeroMotor(1) {};
	 PiezaAeroPlano(int NumeroMotor, int NumeroPieza);
	 virtual void Desplegar() const
	 {
		 Pieza::Desplegar(); cout << "Motor número.: ";
		 cout << suNumeroMotor << endl;
	 }
 private:
	 int suNumeroMotor;
 };
 
 PiezaAeroPlano::PiezaAeroPlano(int NumeroMotor, int NumeroPieza):
	 suNumeroMotor(NumeroMotor),
	 Pieza(NumeroPieza)
 {}
 
 // **************** Nodo de Pieza ************
 class NodoPieza
 {
 public:
	 NodoPieza(Pieza *);
	 ~NodoPieza();
	 void AsignarSiguiente(NodoPieza * nodo) { suSiguiente = nodo; }
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
	 suPieza = 0;
	 delete suSiguiente;
	 suSiguiente = 0;
 }
 
 // Regresa NULL si no hay siguiente NodoPieza
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
	 Pieza * Encontrar(int & posicion, int NumeroPieza) const;
	 int ObtenerCuenta() const { return suCuenta; }
	 Pieza * ObtenerPrimero() const;
	 static ListaPiezas & ObtenerListaPiezasGlobal()
	 {
		 return ListaPiezasGlobal;
	 }
	 void Insertar(Pieza *);
	 void Iterar(void (Pieza::*f)() const) const;
	 Pieza * operator[](int) const;
 private:
	 NodoPieza * apCabeza;
	 int suCuenta;
	 static ListaPiezas ListaPiezasGlobal;
 };
 
 ListaPiezas ListaPiezas::ListaPiezasGlobal;
 
 // Implementaciones para listas...
 
 ListaPiezas::ListaPiezas():
	 apCabeza(0),
	 suCuenta(0)
 {}
 
 ListaPiezas::~ListaPiezas()
 {
	 delete apCabeza;
 }
 
 Pieza * ListaPiezas::ObtenerPrimero() const
 {
	 if (apCabeza)
		 return apCabeza->ObtenerPieza();
	 else
		 return NULL; // atrapar error aquí
 }
 
 Pieza * ListaPiezas::operator[](int desFase) const
 {
	 NodoPieza* apNodo = apCabeza;
 
	 if (!apCabeza)
		 return NULL; // atrapar error aquí
	 if (desFase > suCuenta)
		 return NULL; // error
	 for (int i = 0; i < desFase; i++)
		 apNodo = apNodo->ObtenerSiguiente();
	 return apNodo->ObtenerPieza();
 }
 
 Pieza * ListaPiezas::Encontrar(int & posicion, int NumeroPieza) const
 {
	 NodoPieza * apNodo =NULL;
 
	 for (apNodo = apCabeza, posicion = 0;
	      apNodo != NULL;
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
	 // si éste es más pequeño que el nodo cabeza,
	 // se convierte en el nuevo nodo cabeza
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
		 // entonces insertarlo aquí, de no ser así, obtener el siguiente
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
 
 int main()
 {
	 ListaPiezas & lp = ListaPiezas::ObtenerListaPiezasGlobal();
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
			 apPieza = new PiezaAuto(valor,NumeroPieza);
		 }
		 else
		 {
			 cout << "¿Número de motor?: ";
			 cin >> valor;
			 apPieza = new PiezaAeroPlano(valor, NumeroPieza);
		 }
		 lp.Insertar(apPieza);
	 }
	 void (Pieza::*apFunc)()const = &Pieza::Desplegar;
	 lp.Iterar(apFunc);
	 return 0;
 }
