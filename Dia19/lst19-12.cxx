 // Listado 19.12: Uso de for_each

 #include <iostream>
 #include <vector>
 #include <algorithm>

 using namespace std;


 template< class T >
 class Imprimir
 {
 public:
	 void operator()(const T & t)
		 { cout << t << " "; }
 };

 int main()
 {
	 Imprimir< int > HacerImpresion;
	 vector< int > vInt(5);
	
	 for (int i = 0; i < 5; ++i)
		 vInt[ i ] = i * 3;
	 cout << "for_each()\n";
	 for_each(vInt.begin(), vInt.end(), HacerImpresion);
		 cout << "\n";
	 return 0;
 }
