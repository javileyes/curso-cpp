 // Listado 16.9 - Uso de peek() y de putback()
 #include <iostream.h>
	 
 int main()
 {
 	char ch;
 	cout << "Escriba una frase: ";
 	while (cin.get(ch))
 	{
		 if (ch == '!')
			 cin.putback('$');
		 else
			 cout << ch;
		 while (cin.peek() == '#')
		 cin.ignore(1, '#');
	}
	 return 0;
 }
