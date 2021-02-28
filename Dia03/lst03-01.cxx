#include <iostream>
using namespace std;

int main()
{
    cout << "El tama�o de un entero es:\t\t" << sizeof(int) << " bytes.\n";
    cout << "El tama�o de un entero corto es:\t" << sizeof(short) << " bytes.\n";
    cout << "El tama�o de un entero largo es:\t" << sizeof(long) << " bytes.\n";
    cout << "El tama�o de un car�cter es:\t\t" << sizeof(char) << " bytes.\n";
    cout << "El tama�o de un punto flotante es:\t\t" << sizeof(float) << " bytes.\n";
    cout << "El tama�o de un doble es:\t" << sizeof(double) << " bytes.\n";
    cout << "El tama�o de un booleano es:\t" << sizeof(bool) << " bytes.\n";

    return 0;
}
