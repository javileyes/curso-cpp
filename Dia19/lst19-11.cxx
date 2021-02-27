 // Listado 19.11: Un objeto de función

 #include <iostream.h>

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
	
	 for (int i = 0; i < 5; ++i)
		 HacerImpresion(i);
	 cout << endl;
	 return 0;
 }
