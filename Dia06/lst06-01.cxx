 // Muestra de la declaración de una clase y
 // de la declaración de un objeto de esa clase,

#include <iostream.h> // para cout

class Gato // declarar el objeto clase
{
    public: // los siguientes miembros son públicos
        int suEdad;
        int suPeso;
};


int main()
{
    Gato Pelusa;
    Pelusa.suEdad = 5; // asignar a la variable miembro
    cout << "Pelusa es un gato que tiene ";
    cout << Pelusa.suEdad << " años de edad.\n";
    return 0;
}
