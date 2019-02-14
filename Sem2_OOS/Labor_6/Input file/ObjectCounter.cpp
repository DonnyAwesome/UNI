#pragma once
#include "ObjectCounter.hpp"
#include <iostream>
using namespace std;

//Konstruktor
ObjectCounter::ObjectCounter() : id(++maxId){
	if(debugConstructor)
	cout << "Kontruktor der Klasse <ObjectCounter>, Objekt: " << this->id << endl; 
	number++;
	if(id>maxId)
		maxId = id;
}

//Destruktor
ObjectCounter::~ObjectCounter(){
	if(debugConstructor)
	cout << "Destruktor der Klasse <ObjectCounter>, Objekt: " << this->id << endl; 
	number--;
	if(id==maxId)
		maxId--;
}

//id zurüchgeben
unsigned int ObjectCounter::getId() const{
	return id;
}

//maxId zurückgeben
unsigned int ObjectCounter::getMaxId(){
	return maxId;
}

//number zurückgeben
unsigned int ObjectCounter::getNumber(){
	return number;
}