#include <iostream>
#include "ilgas_skaicius.h"

using namespace std;

int main() {
	skaicius num1;
	try {
		num1 = (string)"0";
	}
	catch (const invalid_argument &err) {
		return 0;
	}
	skaicius num2 = (string)"999";
	skaicius num3 = (string)"999912345896423148745312374896412315896745123436";
	skaicius num4 = (string)"8999123458964231487453123748964123158967451234365";
	skaicius num5 = skaicius((string)"1") - num4;
	cout << (num2 != num1) << endl;
	try {
		num2 = num4 % num1;
	}
	catch (const logic_error &err) {
		cout << err.what() << endl;
	}
	//num2.daugyba(23);
	cout << endl;
	cout << num1 << endl << num2 << endl << num3 << endl << num4 << endl << num5 << endl;
	return 0;
}
