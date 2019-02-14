#include <iostream>
#include <vector>
#include "Polygonline.hpp"

using namespace std;

Polygonline::Polygonline(){
}

Polygonline::Polygonline(Point p){
	addPoint(p);
}

Polygonline::Polygonline(int* points){

}

Polygonline& Polygonline::addPoint(Point p){
	Points.push_back(p);							//Vektor erweitert um ein Objekt Point
	return *this;
}

void Polygonline::appendPolygonline(Polygonline plg){			//füge Objekt Plg2 an Plg1 an
	
	Point p;	
	for(int i=0; i<plg.getSize(); i++){
		p = plg.getPoint(i);		//entnehme Punkt aus Objekt plg an der Stelle i und speicher es in p
		addPoint(p);				//füge den Punkt p hinzu
	}
}

void Polygonline::move(double m_x, double m_y){
	
	Point p;	
	for(int i=0; i<Points.size(); i++){
		p = Points[i];			//Punkt im Vektor Points an Stelle i wird in Point p gespeichert zum berarbeiten
		p.move(m_x, m_y);		//veränder Koordinaten des aktuellen Objektes
		Points[i] = p;			//Speicher verändertes Objekt Point zurück in Vektor Points
	}	
}

void Polygonline::print(){
//cout << Points.size() << endl;
	Point p;	
	cout << "|";
	for(int i=0; i<Points.size(); i++){
		if(i > 0){
			cout << " - ";	
		}
		p = Points[i];
		p.print(false);
	}
	cout << "|" << endl;
}

Point Polygonline::getPoint(int tmp){
	return Points[tmp];
}

int Polygonline::getSize(){
	return Points.size();
}
