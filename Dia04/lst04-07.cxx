// Listado 4.7 - una instrucci�n if
// compleja
 
#include <iostream.h>
int main()
{
    // Pedir dos n�meros
    // Asignar los n�meros a primerNumero y segundoNumero
    // Si primerNumero es mayor que segundoNumero,
    // ver si primerNumero es un m�ltiplo de segundoNumero
    // Si esto sucede, ver si son el mismo n�mero

    int primerNumero, segundoNumero;
    cout << "Escriba dos n�meros.\nPrimero: ";
    cin >> primerNumero;
    cout << "\nSegundo: ";
    cin >> segundoNumero;
    cout << "\n\n";

    if (primerNumero >= segundoNumero) 
    { 
        if ((primerNumero % segundoNumero) == 0)
        // �es primerNumero m�ltiplo de segundoNumero?
        {
            if (primerNumero == segundoNumero)
                cout << "�Son iguales!\n";
            else
               cout << "�El primer n�mero es m�ltiplo del segundo!\n";
        }
        else
            cout << "�El primer n�mero no es m�ltiplo del segundo!\n";
    }
    else
        cout << "�Hey! �El segundo es m�s grande!\n";
    return 0;
}
