// Listado 26.1 Un programa básico de Gnome: (botones.cxx)


#include <gnome.h>

class Callback 
{
public:
	static void clicked( GtkWidget * button, 
	                     gpointer data );
	static gint quit( GtkWidget * widget, 
	                  GdkEvent * event, 
	                  gpointer data );
};

void Callback::clicked( GtkWidget * button, 
                        gpointer data )
{
	char * string = ( char * )data;
	g_print( string );
	g_print( "Uso de Callback de C++\n" );
}

gint Callback::quit( GtkWidget * widget, 
                     GdkEvent * event, 
                     gpointer data )
{
	gtk_main_quit();
	return FALSE;
}

int main( int argc, char *argv[] )
{
	GtkWidget * app;
	GtkWidget * button;
	GtkWidget * hbox;

	// Inicializar GNOME, esto es muy similar a gtk_init 
	gnome_init( "botones-ejemplo-básico", "0.1", argc, argv ); 
	app = gnome_app_new( "botones-ejemplo-básico", "Botones" );
	hbox = gtk_hbox_new( FALSE, 5 );
	gnome_app_set_contents( GNOME_APP ( app ), hbox );

	// enlazar "quit_event con gtk_main_quit 
	gtk_signal_connect ( GTK_OBJECT ( app ), 
	                     "quit_event",
	                     GTK_SIGNAL_FUNC (Callback::quit), 
	                     NULL );

	button = gtk_button_new_with_label( "Botón 1" );
	gtk_box_pack_start( GTK_BOX( hbox ), 
	                    button, 
	                    FALSE, 
	                    FALSE, 
	                    0);
	gtk_signal_connect( GTK_OBJECT( button ), 
	                    "clicked",
	                    GTK_SIGNAL_FUNC( Callback::clicked ),
	                    "Button 1\n");

	button = gtk_button_new_with_label( "Botón 2" );
	gtk_box_pack_start (GTK_BOX( hbox ), 
	                    button, 
	                    FALSE, 
	                    FALSE, 
	                    0);
	gtk_signal_connect (GTK_OBJECT( button ), 
	                    "clicked",
	                    GTK_SIGNAL_FUNC( Callback::clicked ),
	                    "Button 2\n");

	gtk_widget_show_all( app );
	gtk_main ();
	return 0;
}
