// Listado 26.7a Declaración de la clase KDEHelloWorld

#include <kapp.h>
#include <ktmainwindow.h>
#include <qpushbutton.h>

class KDEHelloWorld : public KTMainWindow
{
	Q_OBJECT
public:
	KDEHelloWorld();
	void closeEvent( QCloseEvent * );
public slots:
	void SlotGreet();
	void SlotQuit();
private:
	QPushButton * m_btnGreet;
	QPushButton * m_btnQuit;
};

