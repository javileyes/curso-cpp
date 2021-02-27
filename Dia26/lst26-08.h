// Listado 26.8a Declaración de la clase KDEHelloWorld

#include <kapp.h>
#include <ktmainwindow.h>
#include <qpushbutton.h>
#include <kmenubar.h>
#include <qpopupmenu.h>

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
	KMenuBar * m_Menu;
	QPopupMenu * m_MenuApp;
};

