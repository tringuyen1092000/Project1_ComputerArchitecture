#include "Lib.h"

int main() {
	string num = "-170146037158805728";
	QInt* a = toQInt(num, 10);
	cout << "Number: " << num << endl << "Base 2: " << a->toBase2() << endl << "Base 10: " << a->toBase10() << endl << "Base 16: " << a->toBase16() << endl;
	//string max = "170141183460469231731687303715884105727";
	//string min = "-170141183460469231731687303715884105728";
	delete[] a;
	bitset<8> b(-5);
	return 0;
}
