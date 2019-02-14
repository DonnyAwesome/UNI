#pragma once
#include "OneDimObject.hpp"
#include <iostream>
using namespace std;

//Konstruktor
OneDimObject::OneDimObject(): DrawingObject(){
	if(debugConstructor)
	cout << "Kontruktor der Klasse <OneDimObject>, Objekt: " << this->getId() << endl; 
}

//Destruktor
OneDimObject::~OneDimObject(){
	if(debugConstructor)
	cout << "Destruktor der Klasse <OneDimObject>, Objekt: " << this->getId() << endl;
}