// Listado 26.5 Ejemplo simple de KDEHelloWorld

#include <kapp.h>
#include <ktmainwindow.h>

int main( int argc, char ** argv )
{
	KApplication MyApp( argc, argv );
	KTMainWindow * MyWindow = new KTMainWindow();

	MyWindow->setGeometry( 50, 50, 200, 100 );
	MyApp.setMainWidget( MyWindow );
	MyWindow->show();
	return MyApp.exec();
}
