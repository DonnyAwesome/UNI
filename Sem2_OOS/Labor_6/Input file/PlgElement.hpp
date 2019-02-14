#pragma once
#include "Point.hpp"

class PlgElement{
	Point point;
	PlgElement * next;
	//static PlgElement * ptr;

public:
	//Standardkonstruktor
	PlgElement();

	//Konstruktor
	PlgElement(const Point &);

	//Wert von ptr setzen
	//static void setPtr(PlgElement *);

	//Ausgabe des Elements
	void print(bool) const;

	//Wert von next zurückgeben
	PlgElement * getNext() const;

	//Wert von next setzen
	void setNext(PlgElement *);

	//Wert von Variable point zurückgeben
	Point getPoint() const;

	//Wert von Variable point setzen
	void setPoint(const Point);
};