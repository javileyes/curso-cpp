 // Listado 12.13 Muestra un método orientado a objetos para
 // listas enlazadas. La lista delega responsabilidad al nodo.

 #include <iostream.h>

 enum { kEsMasChico, kEsMasGrande, kEsIgual};

 // Clase de datos que se va a colocar en la lista enlazada
 // Cualquier clase de esta lista enlazada debe soportar dos métodos:
 // Mostrar (despliega el valor) y Comparar (regresa la posición relativa)
 class Datos
 {
 public:
	 Datos(int val ) : miValor(val ){}
	 ~Datos(){}
	 int Comparar(const Datos & );
	 void Mostrar() 
		 { cout << miValor << endl; }
 private:
	 int miValor;
 };

 // Comparar se utiliza para decidir a qué lugar de la lista
 // pertenece un objeto específico.
 int Datos::Comparar(const Datos & losOtrosDatos )
 {
	 if (miValor < losOtrosDatos.miValor )
		 return kEsMasChico;
	 else if (miValor > losOtrosDatos.miValor )
		 return kEsMasGrande;
	 else
		 return kEsIgual;
 }

 // ADT que representa al objeto nodo de la lista
 // Cada clase derivada debe redefinir a Insertar y a Mostrar
 class Nodo
 {
 public:
	 Nodo(){}
	 virtual ~Nodo(){}
	 virtual Nodo * Insertar(Datos * losDatos ) = 0;
	 virtual void Mostrar() = 0;
 };

 // Éste es el nodo que guarda el objeto actual
 // En este caso el objeto es de tipo Datos
 // Veremos como generalizar más esto cuando
 // hablemos sobre las plantillas
 class NodoInterno: public Nodo
 {
 public:
	 NodoInterno(Datos * losDatos, Nodo * siguiente );
	 ~NodoInterno()
		 { delete miSiguiente; delete misDatos; }
	 virtual Nodo * Insertar(Datos * losDatos );
	 virtual void Mostrar() 
	 { 
		 // ¡delegar!
		 misDatos->Mostrar(); 
		 miSiguiente->Mostrar(); 
	 }
	
 private:
	 // los datos en sí
	 Datos * misDatos; 
	 // apunta al siguiente nodo de la lista enlazada
	 Nodo * miSiguiente; 
 };

 // Todo lo que hace el constructor es inicializar
 NodoInterno::NodoInterno(Datos * losDatos, Nodo * siguiente ):
	 misDatos(losDatos ),
	 miSiguiente(siguiente )
 {}

 // la parte principal de la lista
 // Cuando se coloca un nuevo objeto en la lista
 // éste se pasa al nodo que averigua
 // en dónde debe ir y lo inserta en la lista
 Nodo * NodoInterno::Insertar(Datos * losDatos )
 {
	 // ¿es el nuevo objeto más grande o más pequeño que yo?
	 int resultado = misDatos->Comparar(*losDatos );
	 switch(resultado )
	 {
		 // por convención si es igual que yo debe ir primero 
		 case kEsIgual: 
		 // avanzar al siguiente case sin hacer nada
		 case kEsMasGrande: 
		 // los datos nuevos van antes de mí
		 {
			 NodoInterno * nodoDatos = new NodoInterno
			 (losDatos, this );
			 return nodoDatos;
		 }
		 // es mayor que yo así que lo paso al siguiente
		 // nodo para que se encargue de él.
		 case kEsMasChico:
			 miSiguiente = miSiguiente->Insertar(losDatos );
			 return this;
	 }
	 return this; // apaciguar al compilador
 }


 // El nodo cola sólo es un centinela
 class NodoCola : public Nodo
 {
 public:
	 NodoCola(){}
	 ~NodoCola(){}
	 virtual Nodo * Insertar(Datos * losDatos );
	 virtual void Mostrar() {}
 };

 // Si los datos llegan a mí, se deben insertar antes de mí
 // ya que soy la cola y no hay NADA después de mí
 Nodo * NodoCola::Insertar(Datos * losDatos )
 {
	 NodoInterno * nodoDatos = new NodoInterno(losDatos, this );
	 return nodoDatos;
 }

 // El nodo cabeza no tiene datos, sólo apunta
 // al inicio de la lista
 class NodoCabeza : public Nodo
 {
 public:
	 NodoCabeza();
	 ~NodoCabeza() 
		 { delete miSiguiente; }
	 virtual Nodo * Insertar(Datos * losDatos );
	 virtual void Mostrar() 
		 { miSiguiente->Mostrar(); }
 private:
	 Nodo * miSiguiente;
 };

 // Tan pronto como se crea la cabeza
 // se crea la cola
 NodoCabeza::NodoCabeza()
 {
	 miSiguiente = new NodoCola;
 }

 // No hay nada antes de la cabeza así que sólo
 // se pasan los datos al siguiente nodo
 Nodo * NodoCabeza::Insertar(Datos * losDatos )
 {
	 miSiguiente = miSiguiente->Insertar(losDatos );
	 return this;
 }

 // Yo obtengo todos los méritos y no hago nada del trabajo
 class ListaEnlazada
 {
 public:
	 ListaEnlazada();
	 ~ListaEnlazada() 
		 { delete miCabeza; }
	 void Insertar(Datos * losDatos );
	 void MostrarTodo() 
		 { miCabeza->Mostrar(); }
 private:
	 NodoCabeza * miCabeza;
 };

 // Al nacer, se crea el nodo cabeza
 // Éste crea el nodo cola
 // Así que una lista vacía apunta a la cabeza que
 // apunta a la cola y no tiene nada en medio
 ListaEnlazada::ListaEnlazada()
 {
	 miCabeza = new NodoCabeza;
 }

 // Delegar, delegar, delegar
 void ListaEnlazada::Insertar(Datos * apDatos )
 {
	 miCabeza->Insertar(apDatos );
 }

 // programa controlador de prueba
 int main()
 {
	 Datos * apDatos;
	 int val;
	 ListaEnlazada le;
	
	 // pedir al usuario que produzca algunos valores
	 // colocarlos en la lista
	 for (;;)
	 {
		 cout << "¿Cuál valor? (0 para detener): ";
		 cin >> val;
		 if (!val )
			 break;
		 apDatos = new Datos(val );
		 le.Insertar(apDatos );
	 }
	 // ahora avanzar por la lista y mostrar los datos
	 le.MostrarTodo();
	 return 0; // ¡le queda fuera de alcance y se destruye!
 }
