// Listado 26.1a Definición de la clase KDEHelloWorld

#include <kapp.h>
#include <ktmainwindow.h>

class KDEHelloWorld : public KTMainWindow
{
	Q_OBJECT;
public:
	void closeEvent( QCloseEvent * );
};
