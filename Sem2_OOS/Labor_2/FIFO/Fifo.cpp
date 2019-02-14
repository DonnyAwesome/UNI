//bin Aufgabe_2.cpp
#include "Fifo.hpp"							//Codes auskommentieren mit Steuerung punkt
#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;


FIFO::FIFO(int Size = 20){										//Konstruktor
	this->maxSize = Size;
	this->number = 0;
	this->wPos = 0;
	this->rPos = 0;
	this->ptr = new char[Size];
	cout << "KonstruktorAufruf" << endl;
}

FIFO::~FIFO(){										//Dekonstruktor
	delete []ptr;
	cout << "DestruktorAufruf" << endl;
}

int FIFO::getRPos(){
	return this->rPos;  							  		//aktuelle Position des Lesens
}

int FIFO::getWPos(){
	return this->wPos ;									//aktuelle Position de Schreibens
}

bool FIFO::isEmpty(){								//checkt ob array leer ist
	if(number){
		return false;
	}
	return true;
}

bool FIFO::isFull(){								//checkt ob array voll ist
	if(number == (maxSize-1)){
		return true;
	}
	return false;
}

int FIFO::push(char c){								//Schreibt weiteres Element in array rein an Ende der chain
cout << "PushAufruf" << endl;
cout << wPos << endl;
	if(isFull() == true){
		cout << "Array ist Voll" << endl;
		return -1;
	}

ptr[wPos] = c;					
number++;
wPos++;

return 0;	
}

char FIFO::pop(){									//Liest und loescht Element in Array am Anfang der chain
cout << "PopAufruf" << endl;

char extra = ptr[rPos];


	if(isEmpty() == true){
		cout << "Liste ist leer!" << endl;
		return NULL;
	}
	
	char value = ptr[rPos];
	number--;
	rPos++;
	return extra;
}




int main(){
	
	FIFO F;
	F.push('a');
	F.push('b');
	F.push('z');
	cout << F.pop() << endl;
	cout << F.pop() << endl;
	cout << F.pop() << endl;


	
	return 0;
}

