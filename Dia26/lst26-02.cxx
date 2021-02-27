// Listado 26.2  La aplicación GNOMEHelloWorld

#ifdef __GNUG__
// #pragma implementation
#endif

// Para los compiladores que soportan la precompilación, 
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
};

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
	MyFrame * frame = new MyFrame( "¡Hola, mundo!", 
	                               wxPoint( 50, 50 ), 
	                               wxSize( 200, 100 ) );
	frame->Show( TRUE );
	SetTopWindow( frame );
	return TRUE;
} 

MyFrame::MyFrame( const wxString & title, 
                  const wxPoint & pos, 
                  const wxSize & size) : 
	wxFrame( (wxFrame *)NULL, -1, title, pos, size )
{}
