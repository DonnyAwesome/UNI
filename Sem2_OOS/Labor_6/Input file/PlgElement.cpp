#pragma once
#include "PlgElement.hpp"


//PlgElement * PlgElement::ptr = nullptr; //initialisiert ptr mit standardwert (null)

PlgElement::PlgElement(){	//Standardkonstruktor
	//PlgElement::setPtr(this);
	//ptr->next = this;	//ptr->next (Vorelement) auf die Adresse von diesem Element setzen
	next = nullptr;		//next auf null setzen
	//ptr = nullptr;
}

PlgElement::PlgElement(const Point & p){	//Konstruktor
	//if(ptr != nullptr)
	//	ptr->next = this;	//Vorelement auf die Adresse von diesem Element setzen
	point = p;
	next = nullptr;	//next auf null setzen
	//ptr = nullptr;
}

//void PlgElement::setPtr(PlgElement * e){	//ptr auf Objekt des übergebenen Pointers setzen
//	ptr = e;
//}

void PlgElement::print(bool b) const{	//Ausgabe des Elements
	point.print(false);
}

PlgElement * PlgElement::getNext() const{	//Gibt next zurück
	return next;
}

void PlgElement::setNext(PlgElement *  ptr){	//Wert von next setzen
	next = ptr;
}

Point PlgElement::getPoint() const{	//Gibt den Wert von point zurück
	return point;
}

void PlgElement::setPoint(const Point p){	//Setzt den Wert von point
	point = p;
}

