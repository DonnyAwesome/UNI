#include "MyString.hpp"

#include <stdio.h>
#include <stdlib.h>

// For ops on char*
#include "string.h"

#include <iostream>
using namespace std;

char eos = '\0';

int cStrGetLen(char * str) {
	if (str == nullptr)
		return 0;

	int n = 0;
	char * buf = str;
	while (*buf != '\0') {
		n++;
		buf++;
	}
	return n;
}

void cStrCopy(char * ziel, char * quelle, int n) {
	for (int i = 0; i < n; i++)
		ziel[i] = quelle[i];
}



MyString::MyString(void) {			// Konstruktor für leeren String
	this->strSize = 0;
	this->strCapacity = 0;
	this->strPtr = new char;
	this->strPtr[0] = '\0';
}


MyString::MyString(const char *cStr) {	// Konstruktor der einen CString umwandelt
	int i = cStrGetLen((char *)cStr);

	this->strPtr = new char[i + 1];
	this->strSize = i;
	this->strCapacity = 0;

	cStrCopy(this->strPtr, (char *)cStr, i + 1);
}

MyString::MyString(const MyString &mStr) {		// Kopierkonstruktor
	this->strSize = mStr.strSize;
	this->strCapacity = mStr.strCapacity;
	this->strPtr = new char[this->strSize + this->strCapacity + 1];

	cStrCopy(this->strPtr, mStr.strPtr, this->strSize + 1);
}

MyString::~MyString() {			// Destruktor
	delete[] this->strPtr;
}


void MyString::reserve(unsigned int c) {			// Speicherplatz vergrößern
	if (c > (this->strCapacity)) {
		char *buffer = new char[this->strSize + 1];
		cStrCopy(buffer, this->strPtr, this->strSize + 1);

		delete[] this->strPtr;
		this->strPtr = new char[this->strSize + 1 + c];

		cStrCopy(this->strPtr, buffer, this->strSize + 1);

		delete[] buffer;

		this->strCapacity = c;
	}
}


MyString &MyString::append(MyString &str) {			// String anhängen
	this->reserve(str.strSize);

	cStrCopy(this->strPtr + this->strSize, str.strPtr, str.strSize + 1);

	this->strSize += str.strSize;
	this->strCapacity -= str.strSize;

	return *this;
}


MyString &MyString::assign(MyString str) {		// String ersetzen
	this->reserve(str.strSize - this->strSize);

	int totalLength = this->strSize + this->strCapacity + 1;

	cStrCopy(this->strPtr, str.strPtr, str.strSize + 1);

	this->strSize = str.strSize;
	this->strCapacity = totalLength - this->strSize - 1;

	return *this;
}

const char *MyString::c_str(void) {			// String als CString zurück geben
	return this->strPtr;
}

int MyString::size(void) {		//Größe des Strings zurück geben
	return this->strSize;
}

int MyString::capacity(void) {		// Anzahl der noch freien Zeichen zurück geben
	return this->strCapacity;
}

void MyString::clear(void) {		// String leeren
	this->strPtr[0] = '\0';
	this->strCapacity = this->strSize;
	this->strSize = 0;
}

bool MyString::empty(void) {		// Prüfen ob String leer ist
	if (this->strPtr[0] == '\0')
		return true;
	else
		return false;
}

char &MyString::at(int i) {			// Auf ein einzelnes Zeichen des Strings verweisen
	if (i <= 0 || i > this->strSize)
		return this->strPtr[this->strSize + this->strCapacity];
	else return this->strPtr[i];
}

MyString MyString::operator= (const MyString& str){
	this->reserve(str.strSize - this->strSize);

	int totalLength = this->strSize + this->strCapacity + 1;

	cStrCopy(this->strPtr, str.strPtr, str.strSize + 1);

	this->strSize = str.strSize;
	this->strCapacity = totalLength - this->strSize - 1;
	return *this;
}

MyString operator+ (const MyString& s1, const MyString& s2){
	MyString res;
	
	res.strSize = s1.strSize + s2.strSize;
	res.strPtr = new char[res.strSize + 1];
	
	cStrCopy(res.strPtr, s1.strPtr, s1.strSize);
	cStrCopy(res.strPtr + s1.strSize, s2.strPtr, s2.strSize);
	
	return res;
	
}

bool MyString::operator== (MyString & s){
	//cout << this->strSize << " - " << s.strSize << endl;
	return (strcmp(this->c_str(), s.c_str()) == 0);
}

bool MyString::operator!= (MyString & s){
	return strcmp(this->strPtr, s.strPtr);
}

char& MyString::operator[](int pos){
	if (pos >= this->strSize){
		cout << "Invalid position!"	;
	}
	return strPtr[pos];
}

ostream& operator<< (ostream & s, MyString& s1){
	return s << s1.c_str();
}
