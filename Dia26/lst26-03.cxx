// Listado 26.3 Otro ejemplo de GNOMEHelloWorld

#ifdef __GNUG__
// #pragma implementation
#endif

// Para compiladores que soporten la precompilación, 
#include "wx/wxprec.h"

#ifdef __BORLANDC__
  #pragma hdrstop
#endif

#ifndef WX_PRECOMP
  #include "wx/wx.h"
#endif


class MyApp: public wxApp
{
	virtual bool OnInit();
};

class MyFrame: public wxFrame
{
public:
	MyFrame(const wxString & title, 
	        const wxPoint & pos, 
	        const wxSize & size);
	void OnQuit( wxCommandEvent & event);
	void OnGreet( wxCommandEvent & event);
	DECLARE_EVENT_TABLE()
private:
	 wxPanel * m_panel;
	 wxButton * m_btnGreet;
	 wxButton * m_btnQuit;
};

enum { ID_Quit = 1, ID_Greet };

BEGIN_EVENT_TABLE( MyFrame, wxFrame )
EVT_BUTTON( ID_Greet, MyFrame::OnGreet )
EVT_BUTTON( ID_Quit, MyFrame::OnQuit )
END_EVENT_TABLE()

IMPLEMENT_APP( MyApp )

bool MyApp::OnInit()
{
	MyFrame * frame = new MyFrame( "¡Hola, mundo!", 
	                                wxPoint( 50,50 ), 
	                                wxSize( 200,100 ) );
	frame->Show( TRUE );
	SetTopWindow( frame );
	return TRUE;
} 

MyFrame::MyFrame(const wxString & title, 
                 const wxPoint & pos, 
                 const wxSize & size) : 
	wxFrame( (wxFrame *)NULL, -1, title, pos, size )
{
	wxSize panelSize = GetClientSize();
	m_panel = new wxPanel( this, -1, wxPoint( 0, 0 ), panelSize );
	int h = panelSize.GetHeight();
	int w = panelSize.GetWidth();

	m_btnGreet = new wxButton( m_panel, 
	                           ID_Greet,_T( "Saludos" ),
	                           wxPoint( w/2-70, h/2-10 ),
	                           wxSize( 50, 20 ) );
	m_btnQuit = new wxButton( m_panel, 
	                          ID_Quit,_T( "Salir" ),
	                          wxPoint( w/2+20, h/2-10 ),
	                          wxSize( 50, 20 ) );
}

void MyFrame::OnQuit( wxCommandEvent & WXUNUSED( event ) )
{
	Close( TRUE );
}

void MyFrame::OnGreet( wxCommandEvent & WXUNUSED( event ) )
{
	wxMessageBox( "Ejemplo de ¡Hola, mundo! con wxWindows",
	              "¡Hola, mundo!", 
	              wxOK | wxICON_INFORMATION, 
	              this );
}

