#include "Circle.hpp"
#include <iostream>
#include <fstream>
using namespace std;

bool debugConstructor = false;
unsigned int ObjectCounter::maxId=0;
unsigned int ObjectCounter::number=0;


int main(void){
	string str;
	Circle * kreis;
	int i = 0;
	ofstream datei{ "kreis.dat",ios::app }; //datei binär zum schreiben öffnen
	if(!datei)
		cerr << "Datei konnte nicht geoeffnet werden!" << endl;
	datei.seekp(sizeof(int)); //Schreibposition um 4 vom datei-anfang verschieben 

	while(1){
		fflush(stdin);
		cout << "Bitte einen Kreis eingeben: ";
		getline(cin,str);
		if(str=="end"){
			break;
		}
		if(str[0]=='<'){
			kreis = new Circle(str);
			//datei.write(reinterpret_cast<char*>(kreis),sizeof(Circle)); //kreis binär in datei schreiben
			datei << str << endl;
			delete kreis;
			i++;
		}
		else{
			cout << endl << "Fehler! Es wurde kein Kreis eingegeben!" << endl;
		}
	}
	datei.seekp(ios::beg); //Schreibposition auf anfang der datei setzen
	datei.write(reinterpret_cast<char*>(&i),sizeof(int)); //Anzahl der Objekte an den anfang der datei schreiben
	datei.close(); //Datei schließen

	return 0;
}
