 // Listado 10.12
 // Operadores de prefijo y posfijo
 
 #include <iostream.h>
 
 class Contador
 {
 public:
	 Contador();
	 ~Contador(){}
	 int ObtenerSuVal()const 
		 { return suVal; }
	 void AsignarSuVal(int x) 
		 { suVal = x; }
	 const Contador & operator++ (); // prefijo
	 const Contador operator++ (int); // posfijo
 private:
	 int suVal;
 };
 
 Contador::Contador():
	 suVal(0)
 {}
 
 const Contador & Contador::operator++()
 {
	 ++suVal;
	 return *this;
 }
 
 const Contador Contador::operator++(int x)
 {
	 Contador temp(*this);
	 ++suVal;
	 return temp;
 }
 
 int main()
 {
	 Contador i;
	 cout << "El valor de i es ";
	 cout << i.ObtenerSuVal() << endl;
	 i++;
	 cout << "El valor de i es ";
	 cout << i.ObtenerSuVal() << endl;
	 ++i;
	 cout << "El valor de i es ";
	 cout << i.ObtenerSuVal() << endl;
	 Contador a = ++i;
	 cout << "El valor de a: " << a.ObtenerSuVal();
	 cout << " y de i: " << i.ObtenerSuVal() << endl;
	 a = i++;
	 cout << "El valor de a: " << a.ObtenerSuVal();
	 cout << " y de i: " << i.ObtenerSuVal() << endl;
	 return 0;
 }
