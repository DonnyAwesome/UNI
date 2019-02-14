#include <iostream>
#include "Buch.hpp"

using namespace std;

Buch::Buch(string t, string a, string v, int jahr) : Medium{t, v, jahr, "Buch"}, autor{a}{
	cout << "Buch wird erstellt" << endl;
}

void Buch::print() const{
	cout << "------------------------------" << endl << "Buch" << endl << "Titel:	" << this->getTitel() << endl << "Author:	" << this->autor 
	<< endl << "Verlag:	" << this->getVerlag() << endl << "Jahr:	" << this->getJahr() << endl << "Ausleiher:	" << "keiner" << endl << endl;
}

string Buch::getAutor() const{
	return this->autor;
}
