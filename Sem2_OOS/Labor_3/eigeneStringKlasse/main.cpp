//Labor 03 , Aufgabe 02
#include <iostream>
#include "MyString.hpp"

using namespace std;

int main(){
	const MyString cs("Ein konstanter String");				//Aufruf Konstruktor mit CString
	MyString s(cs);										//Aufruf Konstruktor mit Objekt MyString
	s.assign(cs);										//String s ersetzen durch cs
	s.append(cs);										//String s erweitern durch cs
	cout << cs.c_str() << endl;
	cout << cs.size() << endl;
	cout << cs.capacity() << endl;
	cout << boolalpha << cs.empty() << endl;			//Ausgabe false weil Objekt cs ist nicht empty
	s = cs + cs;
	cout << (cs==cs) << endl;							//Ausgabe true weil Objekt cs gleich Objekt cs ist
	s = cs;
	cout << cs << endl;
	s.at(1) = 'X';
	s[2] = 'Y';
	cout << s << endl;

	return 0;
}

