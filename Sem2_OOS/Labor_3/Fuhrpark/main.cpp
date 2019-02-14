//bin main.cpp
#include <iostream>
#include <string.h>
#include <iomanip>
#include "Fuhrpark.hpp"

using namespace std;

int main(){
	Fahrzeug f1("ES - H 123");
	cout << f1 << endl;
	f1.fahren(101.5);
	cout << f1 << endl;
	Fahrzeug f2("ES - M 4711");
	f2.fahren(10.57);
	cout << f2 << endl;
	
	{
	
	Fahrzeug f3("ES - H 420!");
	cout << f3 << endl;
	f3.fahren(106.57);
	cout << "Die Km in Summe im Fuhrpark beträgt: " << f3.getSummekm() << endl;
	//f2.~Fahrzeug();
	cout << f3.getSummekm() << endl;
	//f1.~Fahrzeug();
	cout << f3.getSummekm() << endl;
}
cout << f1.getSummekm() << endl;
	return 0;
}
