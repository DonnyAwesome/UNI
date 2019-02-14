#include <iostream>
#include "Dozent.hpp"

using namespace std;

Dozent::Dozent(string name, int prfrNr) : Person{name, 0}, prfrNr{prfrNr}{
	cout << "Dozent erstellt" << endl;
}

void Dozent::print() const{
	cout << this->getName() << " PrfrNr: " << this->prfrNr << endl;
}
