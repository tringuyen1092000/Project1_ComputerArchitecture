#include "Lib.h"

int main()
{
	string num = "1166B";
	QInt* a = toQInt(num, 16);
	cout << a->toBase2() << " " << a->toBase10() << " " << a->toBase16()<< endl;
	//string test = "340282366920938463463374607431768211456";
	cout << "Test" << endl;
	delete[] a;
	return 0;
}