 // Muestra de la declaraci�n de una clase y
 // de la declaraci�n de un objeto de esa clase,

#include <iostream.h> // para cout

class Gato // declarar el objeto clase
{
    public: // los siguientes miembros son p�blicos
        int suEdad;
        int suPeso;
};


int main()
{
    Gato Pelusa;
    Pelusa.suEdad = 5; // asignar a la variable miembro
    cout << "Pelusa es un gato que tiene ";
    cout << Pelusa.suEdad << " a�os de edad.\n";
    return 0;
}
