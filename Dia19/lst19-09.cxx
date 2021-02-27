
 #include <iostream.h>
 #include <list.h>

 using namespace std;

 typedef list< int > ListaEnteros;


 int main()
 {
	 ListaEnteros listaInt;
	
	 for (int i = 1; i <= 10; ++i)
		 listaInt.push_back(i * 2);
	 for (ListaEnteros::const_iterator ci = listaInt.begin(); 
		 ci != listaInt.end(); ++ci)
	 cout << *ci << " ";
	 cout << endl;
	 return 0;
 }
