// Listado 26.8b KDEHelloWorld

#include "lst26-08.moc"
#include <kmsgbox.h>

KDEHelloWorld::KDEHelloWorld() : KTMainWindow()
{
	m_btnGreet = new QPushButton( "Saludos", this );
	m_btnGreet->setGeometry( 45, 30, 50, 20);
	m_btnGreet->show();
	connect( m_btnGreet,
	         SIGNAL( clicked() ),
	         this,
	         SLOT( SlotGreet() ) );

	m_btnQuit = new QPushButton( "Salir", this );
	m_btnQuit->setGeometry( 105, 30, 50, 20 );
	m_btnQuit->show();
	connect( m_btnQuit,
	         SIGNAL( clicked() ),
	         this,
	         SLOT( SlotQuit() ) ); 

	m_MenuApp = new QPopupMenu();
	m_MenuApp->insertItem( "&Saludos",
	                       this,
	                       SLOT( SlotGreet() ) );
	m_MenuApp->insertItem( "Sa&lir",
	                       this,
	                       SLOT( SlotQuit() ) );
	m_Menu = new KMenuBar( this );
	m_Menu->insertItem( "&Aplicación", m_MenuApp );
}

void KDEHelloWorld::closeEvent( QCloseEvent * )
{
	kapp->quit();
}

void KDEHelloWorld::SlotGreet()
{
	KMsgBox::message( 0,"¡Hola, mundo! con KDE","¡Hola, mundo!" );
}

void KDEHelloWorld::SlotQuit()
{
	close();
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

