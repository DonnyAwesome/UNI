#pragma once
#include "DrawingObject.hpp"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Point: public DrawingObject{
	double x;
	double y;

public:
	//Standardkonstruktor
	Point();

	//Konvertierkonstruktor
	Point(const double, const double);

	//Konvertierkonstruktor
	Point(const string);
	Point(const char *);

	//Destruktor
	~Point();

	//x-Wert setzen
	void setX (double);

	//y-Wert setzen
	void setY (double);

	//x-Wert zurückgeben
	double getX () const;

	//y-Wert zurückgeben
	double getY() const;

	//Punkte verschieben
	void move (const double, const double);

	//Punkte ausgeben
	virtual void print (bool b = true) const;

	//Punkt als string zurückgeben
	string toString () const;

	//Von stringstream Punk einlesen
	friend Point & operator>> (istringstream &, Point &);

	//Punkt als outputstream zurückgeben
	friend ostream & operator<< (ostream &, const Point &);
	
	//Punkte addieren
	Point operator+ (const Point &);

	//Punkte subtrahieren
	Point operator- (const Point &);

	//Punkt negieren
	Point operator- ();

	//Punkt mit double Wert addieren
	friend Point operator+ (const double, const Point &);

	//Punkt mir double Wert addieren
	friend Point operator+ (const Point &, const double);

	//Punkt inkrementieren (Postfix)
	Point operator++ (int);

	//Punkt inkrementieren (Präfix)
	Point & operator++ ();

	//Zuweisungsoperator
	Point & operator= (const Point &);
};