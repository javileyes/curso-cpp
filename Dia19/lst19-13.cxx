 // Listado 19.13: Secuencia mutante 

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
	 vector< int > vInt(10);
	
	 fill(vInt.begin(), vInt.begin() + 5, 1);
	 fill(vInt.begin() + 5, vInt.end(), 2);
	 for_each(vInt.begin(), vInt.end(), HacerImpresion);
		 cout << "\n";
	 return 0;
 }
