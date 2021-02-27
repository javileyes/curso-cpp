 // Listado 21.8: Uso de campos de bits

 #include <iostream.h>
 #include <string.h>

 enum ESTADO { TiempoCompleto, TiempoParcial };
 enum NIVELGRAD { NoGrad, Grad };
 enum ALOJAMIENTO { Dorm, FueraDelCampus };
 enum PLANALIMENT { UnaComida, TodasLasComidas, FinesDeSemana, SinComidas };


 class estudiante
 {
 public:
	 estudiante():
	 miEstado(TiempoCompleto),
	 miNivelGrad(NoGrad),
	 miAlojamiento(Dorm),
	 miPlanAliment(SinComidas) 
	 {}
	 ~estudiante() {}
	 ESTADO ObtenerEstado();
	 void AsignarEstado(ESTADO);
	 unsigned ObtenerPlan() 
		 { return miPlanAliment; }
 private:
	 unsigned miEstado : 1;
	 unsigned miNivelGrad : 1;
	 unsigned miAlojamiento : 1;
	 unsigned miPlanAliment : 2;
 };

 ESTADO estudiante::ObtenerEstado()
 {
	 if (miEstado)
		 return TiempoCompleto;
	 else
		 return TiempoParcial;
 }
 
 void estudiante::AsignarEstado(ESTADO elEstado)
 {
	 miEstado = elEstado;
 }

 int main()
 {
	 estudiante Jim;
	
	 if (Jim.ObtenerEstado() == TiempoParcial)
		 cout << "Jim estudia tiempo parcial" << endl;
	 else
		 cout << "Jim estudia tiempo completo" << endl;
	 Jim.AsignarEstado(TiempoParcial);
	 if (Jim.ObtenerEstado())
		 cout << "Jim estudia tiempo parcial" << endl;
	 else
		 cout << "Jim estudia tiempo completo" << endl;
	 cout << "Jim tiene el plan " ;
	
	 char Plan[ 80 ];
	 switch (Jim.ObtenerPlan())
	 {
		 case UnaComida : 
				 strcpy(Plan, "Una comida"); 
				 break;
		 case TodasLasComidas : 
				 strcpy(Plan, "Todas las comidas"); 
				 break;
		 case FinesDeSemana : 
				 strcpy(Plan,"Comidas en fin de semana"); 
				 break;
		 case SinComidas : 
				 strcpy(Plan,"Sin comidas");
				 break;
		 default : 
				 cout << "¡Algo salió mal!\n";
				 break;
	 }
	 cout << Plan << " de alimentación." << endl;
	 return 0;
 }
