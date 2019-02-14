#pragma once
#include "Point.hpp"

using namespace std;

Point::Point(){	//Standardkonstruktor
	if(debugConstructor)
	cout << "Kontruktor der Klasse <Point>, Objekt: " << this->getId() << endl; 
	x = 0;
	y = 0;
}

Point::Point(double x, double y){	//Konvertierkonstruktor
	if(debugConstructor)
	cout << "Konvertierkontruktor der Klasse <Point>, Objekt: " << this->getId() << endl;
	this->x = x;
	this->y = y;
}

//Konvertierkonstruktor
Point::Point(const char * c){
	string str = c;
	*this = str;
}

//Konvertierkonstruktor
Point::Point(const string str){
	if(debugConstructor)
	cout << "Konvertierkontruktor der Klasse <Point>, Objekt: " << this->getId() << endl;
	char c = 0;
	istringstream is;
	is.str(str.substr(str.find('('),str.rfind(')')));
	is >> c >> x >> c >> y;
}

//Destruktor
Point::~Point(){
	if(debugConstructor)
	cout << "Destruktor der Klasse <Point>, Objekt: " << this->getId() << endl;
}

double Point::getX() const {		//x-Wert zurückgeben
	return x;
}

double Point::getY() const{		//y-Wert zurückgeben
	return y;
}

void Point::setX(const double x){	//x-Wert setzen
	this->x = x;
}

void Point::setY(const double y){	//y-Wert setzen
	this->y = y;
}

void Point::move(const double dx, const double dy){	//Punkt verschieben	
	x += dx;
	y += dy;
}

void Point::print(bool b) const{		//Punkt ausgbeben
	cout << "(" << x << ", " << y << ")";
	if(b==true){		//Falls b == true wird ein endl zusätzlich ausgegeben
		cout << endl;
	}

}

//Punkt als string zurückgeben
string Point::toString() const{
	ostringstream ost;
	ost << "(" << x << ", " << y << ")";
	return ost.str();
}

//Von stringstream Punk einlesen
Point & operator>> (istringstream & s, Point & p){
	char c = 0;
	istringstream hStream;
	hStream.str(s.str().substr(s.str().find('('), s.str().find(')')));
	hStream >> c >> p.x >> c >> p.y;
	return p;
}

//Punkt als outputstream zurückgeben
ostream & operator<< (ostream & ost, const Point & p) {
	return ost << p.toString();
}

//Punkte addieren
Point Point::operator+ (const Point & p){
	Point p1;
	p1.x = x + p.x;
	p1.y = y + p.y;
	return p1;
}

//Punkte subtrahieren
Point Point::operator- (const Point & p){
	Point p1;
	p1.x = x - p.x;
	p1.y = y -p.y;
	return p1;
}

//Punkt negieren
Point Point::operator-(){
	Point p;
	p.x = -x;
	p.y = -y;
	return p;
}

//Punkt mit double Wert addieren
Point operator+ (const double d, const Point & p){
	Point p1;
	p1.x = p.x + d;
	p1.y = p.y + d;
	return p1;
}

//Punkt mit double Wert addieren
Point operator+ (const Point & p, const double d){
	Point p1;
	p1.x = p.x + d;
	p1.y = p.y + d;
	return p1;
}

//Punkt inkrementieren (Postfix)
Point Point::operator++ (int){
	Point p = *this;
	x++;
	y++;
	return p;
}

//Punkt inkrementieren (Präfix)
Point & Point::operator++(){
	++x;
	++y;
	return *this;
}

//Zuweisungsoperator
Point & Point::operator=(const Point & p){
	this->x = p.x;
	this->y = p.y;
	return *this;
}