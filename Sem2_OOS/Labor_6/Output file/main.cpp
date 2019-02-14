#pragma once
#include "Circle.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool debugConstructor = false;
unsigned int ObjectCounter::maxId=0;
unsigned int ObjectCounter::number=0;

int main(void){
	Point p;
	int  k = 0;
	Circle ** kreis;
	Circle * ptr;
	//ifstream datei("kreis.dat",ios::app); //Datei binär zum lesen öffnen
	string line;
	int i = 0;
	ifstream datei;
	char lastChar = '0';
	string kreis_string = "";
	datei.open("kreis.dat");

	if(!datei)
		cerr << "Datei konnte nicht geoeffnet werden!" << endl;

	kreis = new Circle *[100]; //Dynamisches Array mit der entsprechenden größe erstellen
	while (datei >> line) {

		lastChar = line.back();
		if (lastChar == '>') {
			kreis_string.append(line);
			//cout << kreis_string << endl;
			ptr = new Circle(p); //Speicherplatz von heap anfordern
			kreis[i] = new Circle(kreis_string);
			kreis[i]->print();
			i++;
			
			kreis_string = "";
		}else {
			kreis_string.append(line);
			//cout << kreis_string << endl;
		}
	}
	//datei.close();

	//datei.read(reinterpret_cast<char*>(&k), sizeof(int)); //Anzahl der objekte aus der datei lesen
	//kreis = new Circle * [k]; //Dynamisches Array mit der entsprechenden größe erstellen

	//for(int i = 0;i<k;i++){
	//	ptr = new Circle(p);	//Speicherplatz von heap anfordern
		//datei.read(reinterpret_cast<char*>(ptr),sizeof(Circle)); //Kreis-Objekt aus der Datei lesen
	//	datei
	//	kreis[i] = new Circle(ptr->toString());
	//	kreis[i]->print();
	//}

	datei.close(); //Datei schließen
	delete [] kreis;
	return 0;
}
