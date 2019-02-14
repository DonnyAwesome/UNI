//bin Fuhrpark.hpp

#include <iostream>
#include <iomanip>
#include "MyString.hpp"

class Fahrzeug {
	// Private section
	
	public:
		// Public Declarations
	
	Fahrzeug();				//Konstruktor
	Fahrzeug(Fahrzeug &);	
	Fahrzeug(MyString &);
	Fahrzeug(char*);		
	~Fahrzeug();			//Destruktor
	
	
	double getSummekm();
	const char* getKennzeichen();
	double getVin();
	double getKm();
	fahren(double);
		
	protected:
	
	MyString Kennzeichen;
	int vin;
	double km;
	static int Autonum;				//Autonum ist einmalig
	static double summeKm;			//summeKm ist einmalig
};

ostream & operator << (ostream & out, Fahrzeug & f);



