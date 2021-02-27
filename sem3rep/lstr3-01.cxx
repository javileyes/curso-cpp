 // **************************************************
 //
 // Title: Repaso de la semana 3
 //
 // File: Semana3
 //
 // Descripci�n: Proporcionar un programa de �muestra de una lista: 
 // enlazada basada en plantillas con manejo de �excepciones
 //
 // Clases: PIEZA - guarda n�meros de piezas y �potencialmente otra
 // informaci�n sobre las piezas. �sta ser� la �clase de
 // ejemplo que la lista guardar� 
 // Observe el uso de operator<< para imprimir la 
 // informaci�n acerca de una pieza con base en su 
 // tipo en tiempo de ejecuci�n.
 //
 // Nodo - act�a como un nodo de la lista
 //
 // Lista - lista basada en plantilla que proporciona los 
 // mecanismos para una lista enlazada 
 //
 //
 // Autor: Jesse Liberty (jl)
 //
 // Desarrollado en: Pentium 200 Pro. 128MB RAM MVC 5.0
 //
 // Destino: Independiente de la plataforma
 //
 // 
 // 
 // **************************************************

 #include <iostream.h>

 // clases de excepciones
 class Excepcion {};
 class NoHayMemoria : public Excepcion{};
 class NodoNulo : public Excepcion{};
 class ListaVacia : public Excepcion {};
 class ErrorLimites : public Excepcion {};

 // **************** Pieza ************
 // Clase base abstracta de piezas
 class Pieza
 {
 public:
	 Pieza() : suNumeroObjeto(1) {}
	 Pieza(int NumeroObjeto) : 
	 suNumeroObjeto(NumeroObjeto) {}
	 virtual ~Pieza(){};
	 int ObtenerNumeroObjeto() const 
		 { return suNumeroObjeto; }
	 // se debe redefinir el siguiente m�todo 
	 virtual void Mostrar()const = 0; 
 private:
	 int suNumeroObjeto;
 };

 // implementaci�n de funci�n virtual pura para que 
 // las clases derivadas se puedan encadenar
 void Pieza::Mostrar() const
 {
	 cout << "\nN�mero de pieza: "
	      << suNumeroObjeto << endl;
 }

 // este operator<< ser� llamado para todos los objetos Pieza.
 // No necesita ser amigo ni tener acceso a los datos privados
 // Llama a Mostrar(), el cual utiliza el polimorfismo requerido
 // Nos gustar�a poder redefinirlo con base en el tipo real 
 // de la Pieza, pero C++ no soporta la contravarianza 
 ostream & operator<< (ostream & elFlujo, Pieza & laPieza)
 {
	 // �contravarianza virtual!
	 laPieza.Mostrar(); 
	 return elFlujo;
 }

 // **************** Pieza de Auto ************
 class PiezaAuto : public Pieza
 {
 public:
	 PiezaAuto() : SuAnioModelo(94) {}
	 PiezaAuto(int anio, int numeroPieza);
	 int ObtenerAnioModelo() const 
		 { return SuAnioModelo; }
	 virtual void Mostrar() const;
 private:
	 int SuAnioModelo;
 };

 PiezaAuto::PiezaAuto(int anio, int numeroPieza):
	 SuAnioModelo(anio),
	 Pieza(numeroPieza)
 {}

 void PiezaAuto::Mostrar() const
 {
	 Pieza::Mostrar();
	 cout << "A�o del modelo: " 
	      << SuAnioModelo << endl;
 }

 // **************** Pieza de AeroPlano ************
 class PiezaAeroPlano : public Pieza
 {
 public:
	 PiezaAeroPlano() : suNumeroMotor(1) {};
	 PiezaAeroPlano(int NumeroMotor, 
	 int NumeroPieza);
	 virtual void Mostrar() const;
	 int ObtenerNumeroMotor()const 
		 { return suNumeroMotor; }
 private:
	 int suNumeroMotor;
 };

 PiezaAeroPlano::PiezaAeroPlano(int NumeroMotor, 
	                        int NumeroPieza):
	 suNumeroMotor(NumeroMotor),
	 Pieza(NumeroPieza)
 {}

 void PiezaAeroPlano::Mostrar() const
 {
	 Pieza::Mostrar();
	 cout << "N�mero de motor: " 
	      << suNumeroMotor << endl;
 }

 // adelantar declaraci�n de la clase Lista
 template < class T >
 class Lista;

 // **************** Nodo ************
 // Nodo gen�rico, se puede agregar a una lista
 // ************************************

 template < class T >
 class Nodo
 {
 public:
	 friend class Lista< T >;
	 Nodo (T *);
	 ~Nodo();
	 void AsignarSiguiente(Nodo * node) 
		 { suSiguiente = node; }
	 Nodo * ObtenerSiguiente() const;
	 T * ObtenerObjeto() const;
 private:
	 T * suObjeto;
	 Nodo * suSiguiente;
 };

 // Implementaciones de Nodo...

 template < class T >
 Nodo< T >::Nodo(T * apObjeto):
	 suObjeto(apObjeto),
	 suSiguiente(0)
 {}

 template < class T >
 Nodo<T>::~Nodo()
 {
	 delete suObjeto;
	 suObjeto = 0;
	 delete suSiguiente;
	 suSiguiente = 0;
 }

 // Regresa NULL si no hay Nodo siguiente
 template < class T >
 Nodo< T > * Nodo< T >::ObtenerSiguiente() const
 {
	 return suSiguiente;
 }

 template < class T >
 T * Nodo< T >::ObtenerObjeto() const
 {
	 if (suObjeto)
		 return suObjeto;
	 else
		 throw NodoNulo();
 }

 // **************** Lista ************
 // Plantilla de lista gen�rica 
 // Funciona con cualquier objeto numerado
 // ***********************************
 template < class T >
 class Lista
 {
 public:
	 Lista();
	 ~Lista();
	 T * Buscar(int & posicion, 
	 int NumeroObjeto) const;
	 T * ObtenerPrimero() const;
	 void Insertar(T *);
	 T * operator[] (int) const;
	 int ObtenerCuenta() const 
		 { return suCuenta; }
 private:
	 Nodo< T > * apCabeza;
	 int suCuenta;
 };

 // Implementaciones para las Listas...
 template < class T >
 Lista< T >::Lista():
	 apCabeza(0),
	 suCuenta(0)
 {}

 template < class T >
 Lista< T >::~Lista()
 {	
	 delete apCabeza;
 }

 template < class T >
 T * Lista< T >::ObtenerPrimero() const
 {
	 if (apCabeza)
		 return apCabeza->suObjeto;
	 else
		 throw ListaVacia();
 }

 template < class T >
 T * Lista< T >::operator[] (int offSet) const
 {
	 Nodo< T > * apNodo = apCabeza;

	 if (!apCabeza)
		 throw ListaVacia();
	 if (offSet > suCuenta)
		 throw ErrorLimites();
	 for (int i = 0; i < offSet; i++)
		 apNodo = apNodo->suSiguiente;
	 return apNodo->suObjeto;
 }

 // Buscar un objeto dado en una lista con base en su n�mero �nico (id)
 template < class T >
 T * Lista< T >::Buscar(int & posicion, 
 int NumeroObjeto) const
 {
	 Nodo< T > * apNodo = NULL;
	 for (apNodo = apCabeza, posicion = 0;
	      apNodo!=NULL;
	      apNodo = apNodo->suSiguiente, posicion++)
	 {
		 if (apNodo->suObjeto->ObtenerNumeroObjeto() == NumeroObjeto)
			 break;
	 }
	 if (apNodo == NULL)
		 return NULL;
	 else
		 return apNodo->suObjeto;
 }

 // insertar si el n�mero del objeto es �nico
 template < class T >
 void Lista< T >::Insertar(T * apObjeto)
 {
	 Nodo< T > * apNodo = new Nodo< T >(apObjeto);
	 Nodo< T > * apActual = apCabeza;
	 Nodo< T > * apSiguiente = NULL;

	 int Nuevo = apObjeto->ObtenerNumeroObjeto();
	 int Siguiente = 0;
	 suCuenta++;

	 if (!apCabeza)
	 {
		 apCabeza = apNodo;
		 return;
	 }

	 // si �ste es m�s peque�o que el nodo cabeza
	 // entonces se convierte en el nuevo nodo cabeza
	 if (apCabeza->suObjeto->ObtenerNumeroObjeto() > Nuevo)
	 {
		 apNodo->suSiguiente = apCabeza;
		 apCabeza = apNodo;
		 return;
	 }

	 for (;;)
	 {
		 // si no hay siguiente, agregar �ste 
		 if (!apActual->suSiguiente)
		 {
			 apActual->suSiguiente = apNodo;
			 return;
		 }

		 // si va despu�s de �ste y antes del siguiente
		 // entonces insertarlo aqu�, de no ser as�
		 // obtener el siguiente
		 apSiguiente = apActual->suSiguiente;
		 Siguiente = apSiguiente->suObjeto->
		 ObtenerNumeroObjeto();
		 if (Siguiente > Nuevo)
		 {
			 apActual->suSiguiente = apNodo;
			 apNodo->suSiguiente = apSiguiente;
			 return;
		 }
		 apActual = apSiguiente;
	 }
 }


 int main()
 {
	 Lista< Pieza > laPieza;
	 int opcion;
	 int NumeroObjeto;
	 int valor;
	 Pieza * apPieza;

	 while (1)
	 {
		 cout << "(0)Salir (1)Auto (2)Avi�n: ";
		 cin >> opcion;

		 if (!opcion)
			 break;
		 cout << "�Nuevo NumeroPieza?: ";
		 cin >> NumeroObjeto;

		 if (opcion == 1)
		 {
			 cout << "�A�o del modelo?: ";
			 cin >> valor;
			 try
			 {
				 apPieza = new PiezaAuto(valor, 
				 NumeroObjeto);
			 }
			 catch (NoHayMemoria)
			 {
				 cout << "No hay suficiente memoria."
				      << " Saliendo..." << endl;
				 return 1;
			 }
		 }
		 else
		 {
			 cout << "N�mero de motor?: ";
			 cin >> valor;
			 try
			 {
				 apPieza = new PiezaAeroPlano(valor, 
				 NumeroObjeto);
			 }
			 catch (NoHayMemoria)
			 {
				 cout << "No hay suficiente memoria."
				      << " Saliendo..." << endl;
				 return 1;
			 }
		 }
		 try
		 {
			 laPieza.Insertar(apPieza);
		 }
		 catch (NodoNulo)
		 {
			 cout << "�La lista est� dividida,"
			      << " y el nodo es nulo!" << endl;
			 return 1;
		 }
		 catch (ListaVacia)
		 {
			 cout << "�La lista est� vac�a!" << endl;
			 return 1;
		 }
	 }
	 try
	 {
		 for (int i = 0; i < laPieza.ObtenerCuenta(); i++)
			 cout << *(laPieza[ i ]);
	 }
	 catch (NodoNulo)
	 {
		 cout << "�La lista est� dividida,"
		      << " y el nodo es nulo!" << endl;
		 return 1;
	 }
	 catch (ListaVacia)
	 {
		 cout << "�La lista est� vac�a!" << endl;
		 return 1;
	 }
	 catch (ErrorLimites)
	 {
		 cout << "�Trat� de leer m�s all� "
		      << "del final de la lista!" << endl;
		 return 1;
	 }
	 return 0;
 }
