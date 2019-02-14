#pragma once
#include "Polygonline.hpp"

using namespace std;

Polygonline::Polygonline(){	//Standardkonstruktor
	if(debugConstructor)
	cout << "Kontruktor der Klasse <Polygonline>, Objekt: " << this->getId() << endl;
	start = nullptr;
	end = nullptr;
	davor = nullptr;
}

Polygonline::Polygonline(const Point & p){	//Konstruktor
	if(debugConstructor)
	cout << "Kontruktor der Klasse <Polygonline>, Objekt: " << this->getId() << endl;
	start = new PlgElement(p);	//startelement erzeugen
	//start->setPtr(start);
	davor = start;
	end = start;						//end auf start setzen
}

//Konvertierkonstruktor
Polygonline::Polygonline(const string & str){
	if(debugConstructor)
	cout << "Konvertierkontruktor der Klasse <Polygonline>, Objekt: " << this->getId() << endl;
	start = nullptr;
	end = nullptr;
	double x = 0, y = 0;
	Point p;
	int k = 0;
	char c = 0;
	istringstream is;
	string s = str.substr(str.find('('),str.rfind(')'));  //(.. - .... - ...) in s speichern
	for(string::size_type i = 0;str[i]!='\0';i++){	//Anzahl der Punkte bestimmen
		if(str[i]=='-')
			k++;
	}
	k++;
	while(k>0){
		is.str(s.substr(s.find('('), s.find('-')));	//(xx,yy) - in is schreiben
		is >> c >> x >> c >> y;	//Werte in x und y schreiben
		p.setX(x);
		p.setY(y);
		Polygonline::addPoint(p);
		s.erase(0,s.find('-')+1); //Punkt aus string s löschen
		k--;
	}
	
}

Polygonline & Polygonline::addPoint(const Point p){	//Punkt hinzufügen
				
	if(end == nullptr){					
		end = new PlgElement(p); //neues Element mit dem Punkt p erzeugen
		start = end;	
		davor = end;
	}
	else{
		//PlgElement::setPtr(end);		//ptr von der Klasse PlgElement auf den Wert von end setzen (für Verkettung wichtig)
		davor = end;
		end = new PlgElement(p);		//neues Element mit dem Punkt p erzeugen
		davor->setNext(end);
	}
	return *this;
}

void Polygonline::print(bool b) const{	//Ausgabe des Polygonline
	int i = 0;
	PlgElement * ptr2 = start;
	cout << "|";
	for(PlgElement * ptr = start;ptr;ptr = ptr->getNext()){
		ptr->print(b);

		if(i>=2){
			if(ptr2 == ptr){
				cout << endl;
				throw LoopInLine(this->getId());
			}
			ptr2 = ptr2->getNext();
		}

		if((ptr->getNext())!=nullptr){
			cout << " - ";
		}
		i++;
		
	}
	cout << "|" << endl;
}

PlgElement * Polygonline::getStart() const{	//Start zurückgeben
	return start;
}


void Polygonline::appendPolygonline(const Polygonline & line){	//Ein Polygonline hinzufügen
	for(PlgElement * ptr = line.start;ptr;ptr = ptr->getNext()){
		this->addPoint(ptr->getPoint());		
	}

}

void Polygonline::move(const double dx, const double dy){	//Werte der Punkte verschieben
	Point p;									//Hilfsvariable
	for(PlgElement * ptr = start;ptr;ptr = ptr->getNext()){
		p = ptr->getPoint();	//p auf den Wert von dem Punkt von ptr setzen
		p.move(dx,dy);			//move von Klasse Point aufrufen
		ptr->setPoint(p);		//Punkt p wieder zurück in ptr schreiben
	}
}

//Destruktor
Polygonline::~Polygonline(){
	if(debugConstructor)
	cout << "Destruktor der Klasse <Polygonline>, Objekt: " << this->getId() << endl;
	PlgElement * ptr1 = start;
	PlgElement * ptr2 = start->getNext();
	while(ptr1!=end){
		delete ptr1;
		ptr1 = ptr2;
		ptr2 = ptr2->getNext();
	}
	delete ptr1;

}

//Polygonline als string zurückgeben
string Polygonline::toString() const {
	ostringstream ost;
	ost << "|";
	for (PlgElement * ptr = start; ptr; ptr = ptr->getNext()){
		ost << ptr->getPoint().toString();
		if ((ptr->getNext()) != nullptr){
			ost << " - ";
		}
	}
	ost << "|";
	return ost.str();
}

//Polygonline als outputstream zurückgeben
ostream & operator<< (ostream & ost, const Polygonline & pl){
	if(pl.getStart()==nullptr){
		return ost << " ";
	}
	return ost << pl.toString();
}

//Punkt an Polygonline hinzufügen
Polygonline & Polygonline::operator+ (const Point p){
	this->addPoint(p);
	return *this;
}

//Polygonline an Polygonline anfügen
Polygonline & Polygonline::operator+ (const Polygonline & line){
	for(PlgElement * ptr = line.start;ptr;ptr = ptr->getNext()){
		this->addPoint(ptr->getPoint());		
	}
	return *this;
}