//bin Fuhrpark.cpp
#include <iostream>
#include "Fuhrpark.hpp"
#include "MyString.hpp"

int Fahrzeug::Autonum = 1111;
double Fahrzeug::summeKm = 0; 

Fahrzeug::Fahrzeug():vin(Autonum++){						//Konstruktor 1
	this->km = 0;
}

Fahrzeug::Fahrzeug(Fahrzeug &f):vin(Autonum++){			//Konstruktor 2
	this->km = 0;
}

Fahrzeug::Fahrzeug(char *str):vin(Autonum++){				//Konstruktor 3
	this->km = 0;
	this->Kennzeichen.assign(str);									
}

Fahrzeug::~Fahrzeug(){						//Destruktor
	cout << this->vin << endl;
	cout << "Fahrzeug verlaesst Fuhrpark" << endl;
	Autonum--;
	summeKm -= this->km;
	//delete [];
	

}

double Fahrzeug::getSummekm(){
	return summeKm;
}

Fahrzeug::fahren(double addkm){
	this->km += addkm;
	summeKm += addkm;
}

//-----------------------------------------------------------------------------------


const char* Fahrzeug::getKennzeichen(){
	return this->Kennzeichen.c_str();
}

double Fahrzeug::getVin(){
	return this->vin;
}

double Fahrzeug::getKm(){
	return this->km;
}

ostream& operator << (ostream &s, Fahrzeug &f){
	return s << "Kennzeichen = " << f.getKennzeichen() << " VIN = " << f.getVin() << " km = " << f.getKm();
}






