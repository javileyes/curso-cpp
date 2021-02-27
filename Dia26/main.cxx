int main( int argc, char** argv)
{
	MyQtClass Alice, Bob;
	connect( &Alice, SIGNAL(LetterChanged(char)),¬
	         &Bob, SLOT(SetLetter(char)));
	Bob.SetLetter('a');
	Alice.SetLetter('b');
	Bob.Letter();
	return 0;
}
