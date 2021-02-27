// Este listado **NO** compilar�
// Muestra los errores de compilaci�n

#include <iostream.h> // para cout

class Gato
{
    public:
        Gato(int edadInicial);
        ~Gato();
        int ObtenerEdad() const; // funci�n const de acceso
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

Gato::~Gato() // destructor, no realiza ninguna acci�n
{
    cout << "Destructor de Gato\n";
}

// ObtenerEdad, funci�n const
// �pero estamos violando el uso de const!
int Gato::ObtenerEdad() const
{
    return (suEdad++); // viola el uso de const!
}
 
// definici�n de AsignarEdad, m�todo
// de acceso p�blico 
void Gato::AsignarEdad(int edad)
{
    // asignar a la variable miembro suEdad el
    // valor pasado por el par�metro edad
    suEdad = edad; 
}

// definici�n del m�todo Maullar
// regresa: void
// par�metros: Ninguno
// acci�n: Imprime "miau" en la pantalla
void Gato::Miau()
{
    cout << "Miau.\n";
}

// muestra diversas violaciones a la
// interfaz, as� como los errores de compilaci�n resultantes
int main()
{
    Gato Pelusa; // no concuerda con la declaraci�n
    Pelusa.Maullar();
    Pelusa.Ladrar(); // No, tonto, los gatos no pueden ladrar.
    Pelusa.suEdad = 7; // suEdad es privada
    return 0;
}
