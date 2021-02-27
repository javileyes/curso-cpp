 // Listado 10.18
 // Uso del operador de conversión
 
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
	 operator unsigned short();
 private:
	 int suVal;
 };
 
 Contador::Contador():
	 suVal(0)
 {}
 
 Contador::Contador(int val):
	 suVal(val)
 {}
 
 Contador::operator unsigned short ()
 {
	 return (int (suVal));
 }
 
 int main()
 {
	 Contador ctr(5);
	 int elShort = ctr;
	 
	 cout << "elShort: " << elShort << endl;
	 return 0;
 }
