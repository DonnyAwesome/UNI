#include <string>
#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	double d = 1.234;
	cout << "Nr  Oct  Hex String  Fixed     Scientific " << endl;
	for (int k = 1; k < 11; k++) {
		
		char a = '*';
		char b = '+';
		size_t c_1 = k % 5 + 1;
		size_t c_2 = 6 - (k % 5 + 1);

		cout << setw(3) << right << dec << k;
		cout << setw(4) << right << oct << k;
		cout << setw(4) << right << "0x" << hex << k << " ";
		cout << setw(7) << left << string(c_1, a) + string(c_2, b) << " ";
		cout << setw(8) << right << setprecision(3) << fixed << d << " ";
		cout << setw(11) << right << scientific << d;
		d = d*-2;
		cout << endl;
	}
	system("pause");
	return 0;
}
