 #include <iostream.h>

 float Convertir(float);
 int main()
 {
	 float TempFar;
	 float TempCen;

	 cout << "Escriba la temperatura en grados Fahrenheit: ";
	 cin >> TempFar;
	 TempCen = Convertir(TempFar);
	 cout << "\nAqu� est� la temperatura en grados cent�grados: ";
	 cout << TempCen << endl;
	 return 0;
 }

 float Convertir(float TempFar)
 {
	 float TempCen;

	 TempCen = ((TempFar - 32) * 5) / 9;
	 return TempCen;
 }
