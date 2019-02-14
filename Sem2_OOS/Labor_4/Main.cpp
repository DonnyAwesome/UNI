#include <iostream>
#include <string>
using namespace std;

class A {
public:
	void f() {
		cout << "A::f()" << endl;
	}
	void g(double d) {
		cout << "A::g(double)" << endl;
	}
	void g(string s) {
		cout << "A::g(string)" << endl;
	}
	void h(char c) {
		cout << "A::h(char)" << endl;
	}
	void h(string s) {
		cout << "A::h(string)" << endl;
	}
};

class B : public A {
public:
	void g(int i) {
		cout << "B::g(int)" << endl;
	}
	void h(int i) {
		cout << "B::h(int)" << endl;
	}
	void h(string s) {
		cout << "B::h(string)" << endl;
	}
};

int main() {
	A a;
	B b;
	cout << "a.f() "; 
	a.f();    
	cout << "b.f() "; 
	b.f();     
	cout << "a.g(1.2) "; 
	a.g(1.2);  
	cout << "b.g(1.2) "; 	
	b.g(1.2);  				//Aufruf b.g (int) anstatt (double)
	cout << "a.g(1) "; 
	a.g(1);    
	cout << "b.g(1) "; 
	b.g(1);    
	cout << "\n\n\n\na.g('a') "; 
	a.g('a');  			//bei char ruft er Double auf
	cout << "b.g('a') "; 
	b.g('a');  			//hier ruft er int auf
	cout << "a.g(\"a\") "; 
	a.g("a");  			//hier erst die string
	//cout << "b.g(\"a\") "; 
	// b.g("a");  				invalid conversion from 'const char*' to 'int' [-fpermissive]		
	cout << "a.h(1) "; 
	a.h(1);    			//ruft char auf
	cout << "b.h(1) "; 
	b.h(1);   			//ruft int auf
	cout << "a.h('a') "; 
	a.h('a');  			
	cout << "b.h('a') "; 
	b.h('a'); 
	cout << "a.h(\"a\") "; 
	a.h("a");  
	cout << "b.h(\"a\") "; 
	b.h("a"); 
	return 0;
}

