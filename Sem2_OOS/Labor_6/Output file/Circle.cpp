#pragma once
#include "Circle.hpp"

using namespace std;

Circle::Circle(const Point & c): centre(c), radius(0){ //Konstruktor
	if(debugConstructor)
	cout << "Kontruktor der Klasse <Circle>, Objekt: " << this->getId() << endl; 
}

//Konvertierkonstruktor
Circle::Circle(const string & str){
	if(debugConstructor)
	cout << "Konvertierkontruktor der Klasse <Circle>, Objekt: " << this->getId() << endl; 
	istringstream is;
	char c = 0;
	double x = 0, y = 0;
	string s;
	s = str.substr(str.find('('));
	is.str(s);
	is >> c >> x >> c >> y >> c >> c >> radius; 
	centre.setX(x);
	centre.setY(y);
}

//Konstruktor
Circle::Circle (const Point & p, const double r): centre(p), radius(r){
	if(debugConstructor)
	cout << "Kontruktor der Klasse <Circle>, Objekt: " << this->getId() << endl; 
}

//Destruktor
Circle::~Circle(){
	if(debugConstructor)
	cout << "Destruktor der Klasse <Circle>, Objekt: " << this->getId() << endl; 
}

Point Circle::getCentre() const{	//Mittelpunkt zurückgeben
	return centre;
}

double Circle::getRadius() const{	//Radius zurückgeben
	return radius;
}

void Circle::setCentre(const Point centre){	//Mittelpunkt setzen
	this->centre = centre;
}

void Circle::setRadius(const double radius){	//Radius setzen
	this->radius = radius;
}

void Circle::move(const double dx, const double dy){	//Kreis verschieben
	centre.move(dx,dy);
}

void Circle::print(bool b) const{	//Kreis ausgeben
	cout << "<(" << centre.getX() << ", " << centre.getY() << "), " << radius << ">";
	if(b == true){	
		cout << endl;	//falls b == true wir zusätzlich ein endl ausgegeben
	}
}

//Kreis als string zurückgeben
string Circle::toString() const{
	ostringstream ost;
	ost << "<(" << centre.getX() << ", " << centre.getY() << "), " << radius << ">";
	return ost.str();
}

//Kreis als outputstream zurückgeben
ostream & operator<< (ostream & ost, Circle & c){
	return ost << c.toString();
}
