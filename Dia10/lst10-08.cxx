 // Listado 10.8
 // La clase Contador
 
 #include <iostream.h>
 
 class Contador
 {
 public:
	 Contador();
	 ~Contador(){}
	 int ObtenerSuVal()const 
		 { return suVal; }
	 void AsignarSuVal(int x) 
		 {suVal = x; }
	 void Incremento() 
		 { ++suVal; }
	 void operator++ () 
		 { ++suVal; }
 private:
	 int suVal;
 };
 
 Contador::Contador():
	 suVal(0)
 {}
 
 int main()
 {
	 Contador i;
	 cout << "El valor de i es ";
	 cout << i.ObtenerSuVal() << endl;
	 i.Incremento();
	 cout << "El valor de i es ";
	 cout << i.ObtenerSuVal() << endl;
	 ++i;
	 cout << "El valor de i es ";
	 cout << i.ObtenerSuVal() << endl;
	 return 0;
 }
