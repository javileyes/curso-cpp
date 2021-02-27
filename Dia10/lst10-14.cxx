 // Listado 10.14
 //Sobrecargar el operador de suma (+)
 
 #include <iostream.h>
 
 class Contador
 {
 public:
	 Contador();
	 Contador(int valorInicial);
	 ~Contador(){}
	 int ObtenerSuVal()const 
		 { return suVal; }
	 void AsignarSuVal(int x) 
		 { suVal = x; }
	 Contador operator+ (const Contador &);
 private:
	 int suVal;
 };
 
 Contador::Contador(int valorInicial):
	 suVal(valorInicial)
 {}
 
 Contador::Contador():
	 suVal(0)
 {}
 
 Contador Contador::operator+ (const Contador & rhs)
 {
	 return Contador(suVal + rhs.ObtenerSuVal());
 }
 
 int main()
 {
	 Contador varUno(2), varDos(4), varTres;
	 
	 varTres = varUno + varDos;
	 cout << "varUno: " << varUno.ObtenerSuVal()<< endl;
	 cout << "varDos: " << varDos.ObtenerSuVal() << endl;
	 cout << "varTres: " << varTres.ObtenerSuVal() << endl;
	 return 0;
 }
