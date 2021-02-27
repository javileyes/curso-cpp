#include <iostream.h>

int main()
{
    cout << "El tamaño de un entero es:\t\t" << sizeof(int) << " bytes.\n";
    cout << "El tamaño de un entero corto es:\t" << sizeof(short) << " bytes.\n";
    cout << "El tamaño de un entero largo es:\t" << sizeof(long) << " bytes.\n";
    cout << "El tamaño de un carácter es:\t\t" << sizeof(char) << " bytes.\n";
    cout << "El tamaño de un punto flotante es:\t\t" << sizeof(float) << " bytes.\n";
    cout << "El tamaño de un doble es:\t" << sizeof(double) << " bytes.\n";
    cout << "El tamaño de un booleano es:\t" << sizeof(bool) << " bytes.\n";

    return 0;
}
