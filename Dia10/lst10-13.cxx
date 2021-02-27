 // Listado 10.13
 // Función Sumar
 
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
	 Contador Sumar(const Contador &);
 private:
	 int suVal;
 };
 
 Contador::Contador(int valorInicial):
	 suVal(valorInicial)
 {}
 
 Contador::Contador():
	 suVal(0)
 {}
 
 Contador Contador::Sumar(const Contador & rhs)
 {
	 return Contador(suVal + rhs.ObtenerSuVal());
 }
 
 int main()
 {
	 Contador varUno(2), varDos(4), varTres;
	 
	 varTres = varUno.Sumar(varDos);
	 cout << "varUno: " << varUno.ObtenerSuVal()<< endl;
	 cout << "varDos: " << varDos.ObtenerSuVal() << endl;
	 cout << "varTres: " << varTres.ObtenerSuVal() << endl;
	 return 0;
 }
