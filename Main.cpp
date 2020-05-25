#include "Lib.h"

int main()
{
	string num = "1166B";
	QInt* a = toQInt(num, 16);
	cout << a->toBase2() << " " << a->toBase10() << " " << a->toBase16()<< endl;
	//string test = "340282366920938463463374607431768211456";
	cout << "Test" << endl;
	delete[] a;
	string inputStr = readFile("input.txt");
	int p1 = 0, p2 = 0;
	string str = readLine(27, inputStr);
	string opr = operation(str, p1, p2);
	cout << p1 << endl << p2 << endl;
	cout << opr;
	system("pause");
	return 0;
}