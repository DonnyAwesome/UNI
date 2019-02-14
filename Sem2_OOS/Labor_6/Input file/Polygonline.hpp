#pragma once
#include "PlgElement.hpp"
#include "OneDimObject.hpp"

using namespace std;

class Polygonline: virtual public OneDimObject{
	PlgElement * start;
	PlgElement * end;
	PlgElement * davor;

public:

	class LoopInLine: public GraphException {
	public:
		LoopInLine(const unsigned int);
		const unsigned int getId() const;
	};

	//Standardkonstruktor
	Polygonline();

	//Konstruktor
	Polygonline(const Point &);

	//Konvertierkonstruktor
	Polygonline(const string &);

	//Destruktor
	~Polygonline();

	//Punkt zu Polygonline hinzufügen
	Polygonline & addPoint(const Point);

	//Alle Punkte ausgeben
	virtual void print(bool=false) const;

	//Eine Polygonline anfügen
	void appendPolygonline(const Polygonline &);

	//gibt den Wert von Start zurück
	PlgElement * getStart() const;

	//Werte der Punkte erhöhen bzw verniedrigen
	void move(const double, const double);

	//Polygonline als string zurückgeben
	string toString() const;

	//Polygonline als outputstream zurückgeben
	friend ostream & operator<< (ostream &,const Polygonline &);
	
	//Punkt an Polygonline hinzufügen
	Polygonline & operator+ (const Point);

	//Polygonline an Polygonline anfügen
	Polygonline & operator+ (const Polygonline &);

};