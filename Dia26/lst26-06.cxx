// Listado 26.6 KDEHelloWorld

#include "lst26-06.moc"

void KDEHelloWorld::closeEvent( QCloseEvent * )
{
	kapp->quit();
}

int main( int argc, char ** argv )
{
	KApplication MyApp( argc, argv, "¡Hola, mundo!" );
	KDEHelloWorld * MyWindow = new KDEHelloWorld();

	MyWindow ->setGeometry( 50, 100, 200, 100);
	MyApp.setMainWidget( MyWindow );
	MyWindow ->show();
	return MyApp.exec();
}

