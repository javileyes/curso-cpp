#include <iostream.h>

int Suma (int x, int y)
{
    cout << "En Suma(), se recibieron " << x << " y " << y << "\n";
    return (x+y);
}

int main()
{
    cout << "�Estoy en main()!\n";
    int a, b, c;
    cout << "Escriba dos n�meros: ";
    cin >> a;
    cin >> b;
    cout << "\nLlamando a Suma()\n";
    c=Suma(a,b);
    cout << "\nDe regreso en main().\n";
    cout << "c contiene el n�mero " << c;
    cout << "\nSaliendo...\n\n";
    return 0;
}
