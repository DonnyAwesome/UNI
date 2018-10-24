//setfill() line 19 is wrong

#include <string>
#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	double d = 1.234;
	cout << "Nr  Oct  Hex String  Fixed     Scientific " << endl;
	for (int k = 1; k < 11; k++) {
		
		char a = '*';
		size_t c = k % 5 + 1;

		cout << setw(3) << right << dec << k;
		cout << setw(4) << right << oct << k;
		cout << setw(4) << right << "0x" << hex << k << " ";
		//cout << setfill('+') << setw(7)  << left << string(c, a) << " ";
		cout << setw(7) << left << string(c, a) << " ";
		cout << setw(8) << right << setprecision(3) << fixed << d << " ";
		cout << setw(11) << right << scientific << d;
		d = d*-2;
		cout << endl;
	}
	//system("pause");
	return 0;
}
