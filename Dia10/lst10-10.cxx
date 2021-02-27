 // Listado 10.10
 // operator++ regresa un objeto temporal sin nombre
 
 #include <iostream.h>
 
 class Contador
 {
 public:
	 Contador();
	 Contador(int val);
	 ~Contador(){}
	 int ObtenerSuVal()const 
		 { return suVal; }
	 void AsignarSuVal(int x) 
		 { suVal = x; }
	 void Incremento() 
		 { ++suVal; }
	 Contador operator++ ();
 private:
	 int suVal;
 };
 
 Contador::Contador():
	 suVal(0)
 {}
 
 Contador::Contador(int val):
	 suVal(val)
 {}
 
 Contador Contador::operator++()
 {
	 ++suVal;
	 return Contador (suVal);
 }
 
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
	 Contador a = ++i;
	 cout << "El valor de a: " << a.ObtenerSuVal();
	 cout << " y de i: " << i.ObtenerSuVal() << endl;
	 return 0;
 }
