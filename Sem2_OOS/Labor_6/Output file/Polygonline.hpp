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

	//Punkt zu Polygonline hinzuf�gen
	Polygonline & addPoint(const Point);

	//Alle Punkte ausgeben
	virtual void print(bool=false) const;

	//Eine Polygonline anf�gen
	void appendPolygonline(const Polygonline &);

	//gibt den Wert von Start zur�ck
	PlgElement * getStart() const;

	//Werte der Punkte erh�hen bzw verniedrigen
	void move(const double, const double);

	//Polygonline als string zur�ckgeben
	string toString() const;

	//Polygonline als outputstream zur�ckgeben
	friend ostream & operator<< (ostream &,const Polygonline &);
	
	//Punkt an Polygonline hinzuf�gen
	Polygonline & operator+ (const Point);

	//Polygonline an Polygonline anf�gen
	Polygonline & operator+ (const Polygonline &);

};