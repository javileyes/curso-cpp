 // Listado 10.11
 // Cómo regresar el apuntador this desreferenciado
 
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
	 void Incremento() 
		 { ++suVal; }
	 const Contador & operator++ ();
 private:
	 int suVal;
 };
 
 Contador::Contador():
	 suVal(0)
 {};
 
 const Contador & Contador::operator++()
 {
	 ++suVal;
	 return *this;
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
