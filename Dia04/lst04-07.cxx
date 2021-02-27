// Listado 4.7 - una instrucción if
// compleja
 
#include <iostream.h>
int main()
{
    // Pedir dos números
    // Asignar los números a primerNumero y segundoNumero
    // Si primerNumero es mayor que segundoNumero,
    // ver si primerNumero es un múltiplo de segundoNumero
    // Si esto sucede, ver si son el mismo número

    int primerNumero, segundoNumero;
    cout << "Escriba dos números.\nPrimero: ";
    cin >> primerNumero;
    cout << "\nSegundo: ";
    cin >> segundoNumero;
    cout << "\n\n";

    if (primerNumero >= segundoNumero) 
    { 
        if ((primerNumero % segundoNumero) == 0)
        // ¿es primerNumero múltiplo de segundoNumero?
        {
            if (primerNumero == segundoNumero)
                cout << "¡Son iguales!\n";
            else
               cout << "¡El primer número es múltiplo del segundo!\n";
        }
        else
            cout << "¡El primer número no es múltiplo del segundo!\n";
    }
    else
        cout << "¡Hey! ¡El segundo es más grande!\n";
    return 0;
}
