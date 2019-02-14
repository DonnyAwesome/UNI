#pragma once
#include "DrawingObject.hpp"
#include <iostream>
using namespace std;


DrawingObject::DrawingObject(): ObjectCounter(){
	if(debugConstructor)
	cout << "Kontruktor der Klasse <DrawingObject>, Objekt: " << this->getId() << endl; 
}

DrawingObject::~DrawingObject(){
	if(debugConstructor)
	cout << "Destruktor der Klasse <DrawingObject>, Objekt: " << this->getId() << endl; 
}

void DrawingObject::check() const  {
	if(this->getId()>ObjectCounter::getMaxId())
		//throw GraphException(this->getId());
		throw IdTooHigh(this->getId());
}