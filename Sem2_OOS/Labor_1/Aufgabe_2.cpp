#include <string>
#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int anzahl = 0;
	
	cout << "Wie viele Zahlen sollen eingelesen werden?" << endl;
	cin >> anzahl;
	
	int* array = new int[anzahl]; 
	
	for (int k = 0; k < anzahl; k++) {
		cout << k+1 << "-te Zahl ist?" << endl;
		cin >> array[k];
	}
	system("pause");
	return 0;
}
