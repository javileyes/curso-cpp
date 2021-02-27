// Este listado **NO** compilará
// Muestra los errores de compilación

#include <iostream.h> // para cout

class Gato
{
    public:
        Gato(int edadInicial);
        ~Gato();
        int ObtenerEdad() const; // función const de acceso
        void AsignarEdad (int edad);
        void Maullar();
    private:
        int suEdad;
};

// constructor de Gato,
Gato::Gato(int edadInicial)
{
    suEdad = edadInicial;
    cout << "Constructor de Gato\n";
}

Gato::~Gato() // destructor, no realiza ninguna acción
{
    cout << "Destructor de Gato\n";
}

// ObtenerEdad, función const
// ¡pero estamos violando el uso de const!
int Gato::ObtenerEdad() const
{
    return (suEdad++); // viola el uso de const!
}
 
// definición de AsignarEdad, método
// de acceso público 
void Gato::AsignarEdad(int edad)
{
    // asignar a la variable miembro suEdad el
    // valor pasado por el parámetro edad
    suEdad = edad; 
}

// definición del método Maullar
// regresa: void
// parámetros: Ninguno
// acción: Imprime "miau" en la pantalla
void Gato::Miau()
{
    cout << "Miau.\n";
}

// muestra diversas violaciones a la
// interfaz, así como los errores de compilación resultantes
int main()
{
    Gato Pelusa; // no concuerda con la declaración
    Pelusa.Maullar();
    Pelusa.Ladrar(); // No, tonto, los gatos no pueden ladrar.
    Pelusa.suEdad = 7; // suEdad es privada
    return 0;
}
