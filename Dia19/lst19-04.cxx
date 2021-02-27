  // Listado 19.4: uso del operador ostream

#include <iostream.h>

const int TamanioPredet = 10;


class Animal
{
public:
	Animal(int);
	Animal();
	~Animal() {}
	int ObtenerPeso() const 
	       { return suPeso; }
	void Desplegar() const 
	       { cout << suPeso; }
private:
	       int suPeso;
};

Animal::Animal(int peso):
	suPeso(peso)
{}

Animal::Animal():
	suPeso(0)
{}

// declarar la plantilla y el parámetro 
template < class T > 
// la clase que se va a parametrizar 
class Arreglo 
{
public:
	// constructores
	Arreglo(int suTamanio = TamanioPredet);
	Arreglo(const Arreglo & rhs);
	~Arreglo() 
		{ delete [] apTipo; }
	// operadores
	Arreglo & operator=(const Arreglo &);
	T & operator[](int desplazamiento) 
		{ return apTipo[ desplazamiento ]; }
	const T & operator[](int desplazamiento) const
		{ return apTipo[ desplazamiento ]; }
	// métodos de acceso
	int ObtenerTamanio() const 
		{ return suTamanio; }
	friend ostream & operator<< <> (ostream &, Arreglo< T > &);
private:
	T * apTipo;
	int suTamanio;
};

template < class T >
ostream & operator<< (ostream & salida, Arreglo< T > & elArreglo)
{
	for (int i = 0; i < elArreglo.ObtenerTamanio(); i++)
		salida << "[" << i << "] " << elArreglo[ i ] << endl; 
	return salida;
}

// las implementaciones están a continuación...
// implementar el Constructor
template < class T >
Arreglo< T >::Arreglo(int tamanio):
suTamanio(tamanio)
{
	apTipo = new T[ tamanio ];
	
	for (int i = 0; i < tamanio; i++)
		apTipo[ i ] = 0;
}

// constructor de copia 
template < class T >
Arreglo< T >::Arreglo(const Arreglo & rhs)
{
	suTamanio = rhs.ObtenerTamanio();
	apTipo = new T[ suTamanio ];
	
	for (int i = 0; i < suTamanio; i++) 
		apTipo[ i ] = rhs[ i ];
}

// operator=
template < class T >
Arreglo< T > & Arreglo< T >::operator=(const Arreglo & rhs)
{ 
	if (this == & rhs)
		return *this;
	delete [] apTipo;
	suTamanio = rhs.ObtenerTamanio();
	apTipo = new T[ suTamanio ];
	for (int i = 0; i < suTamanio; i++)
		apTipo[ i ] = rhs[ i ];
	return *this;
}

int main()
{
	// indicador para el ciclo 
	bool Detener = false;
	int desplazamiento, valor;
	Arreglo< int > elArreglo;
	
	while (!Detener)
	{
		cout << "Escriba un desplazamiento (0-9) ";
		cout << "y un valor. (-1 para detener): " ;
		cin >> desplazamiento >> valor;
		if (desplazamiento < 0)
			break;
		if (desplazamiento > 9)
		{
			cout << "***Utilice valores entre 0 y 9.***\n";
			continue;
		}
		elArreglo[ desplazamiento ] = valor;
	}
	cout << "\nHe aquí el arreglo completo:\n";
	cout << elArreglo << endl;
	return 0;
}
