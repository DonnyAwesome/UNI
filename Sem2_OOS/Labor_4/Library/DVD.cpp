#include <iostream>
#include "DVD.hpp"

using namespace std;

DVD::DVD(string t, string v, int j, int d) : Medium{t, v, j, "DVD"}, dauer{d}{
	cout << "DVD wird erstellt" << endl;
	//Medium::Medium(t, v ,j ,"DVD");
	//this->dauer = d;
}

void DVD::print() const{
	cout << "------------------------------" << endl << "DVD" << endl << "Titel:	" << this->getTitel() << endl << "Dauer:	" << this->dauer 
	<< endl << "Verlag:	" << this->getVerlag() << endl << "Jahr:	" << this->getJahr() << "Ausleiher:	" << "keiner" << endl << endl;
}

int DVD::getDauer() const{
	return this->dauer;
}
