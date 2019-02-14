#pragma once
#include "Point.hpp"
#include "OneDimObject.hpp"

using namespace std;

class Circle: public OneDimObject{
	Point centre;
	double radius;

public:
	//Circle();

	//Konstruktor
	Circle(const Point &);
	
	//Konvertierkonstruktor
	Circle(const string &);

	//Konstruktor
	Circle(const Point &, const double);

	//Destruktor
	~Circle();

	//Mittelpunkt zurückgeben
	Point getCentre() const;

	//Radius zurückgeben
	double getRadius() const;

	//Mittelpunkt setzen
	void setCentre(const Point);

	//Radius setzen
	void setRadius(const double);

	//Kreis verschieben
	void move(const double, const double);

	//Kraus ausgeben
	virtual void print (bool b = true) const;

	//Kreis als string zurückgeben
	string toString() const;

	//Kreis als outputstream zurückgeben
	friend ostream & operator<< (ostream &, Circle &);
};