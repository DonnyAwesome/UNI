#include <iostream>
#include "Student.hpp"

using namespace std;

Student::Student(string name, int matNr) : Person{name, 0}, matNr{matNr}{
	cout << "Student Erstellt" << endl;
}

void Student::print() const{
	cout << this->getName() << " MatNr: " << this->matNr << endl;
}
