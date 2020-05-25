#include "Lib.h"

int main() {

	string max = "170141183460469231731687303715884105727";
	string min = "-170141183460469231731687303715884105728";
	string num0 = "788323282258381939236275890776";
	string num1 = "-27388934683056007097503944712";
	QInt* a = toQInt(num0, 10);
	cout << "Number: " << num0 << endl << "Base 2: " << a->toBase2() << endl << "Base 10: " << a->toBase10() << endl << "Base 16: " << a->toBase16() << endl << endl;
	QInt* b = toQInt(num1, 10);
	cout << "Number: " << num1 << endl << "Base 2: " << b->toBase2() << endl << "Base 10: " << b->toBase10() << endl << "Base 16: " << b->toBase16() << endl << endl;
	QInt c = *a & *b;
	cout << "c = : " << num0 << " & " << num1 << endl << "Base 2: " << c.toBase2() << endl << "Base 10: " << c.toBase10() << endl << "Base 16: " << c.toBase16() << endl << endl;
	QInt d = *a | *b;
	cout << "d = : " << num0 << " | " << num1 << endl << "Base 2: " << d.toBase2() << endl << "Base 10: " << d.toBase10() << endl << "Base 16: " << d.toBase16() << endl << endl;
	QInt e = *a ^ *b;
	cout << "e = : " << num0 << " ^ " << num1 << endl << "Base 2: " << e.toBase2() << endl << "Base 10: " << e.toBase10() << endl << "Base 16: " << e.toBase16() << endl << endl;
	QInt f = ~*a;
	cout << "f = : " << " ~" << num0 << endl << "Base 2: " << f.toBase2() << endl << "Base 10: " << f.toBase10() << endl << "Base 16: " << f.toBase16() << endl << endl;
	QInt g = *a + *b;
	cout << "g = : " << num0 << " + " << num1 << endl << "Base 2: " << g.toBase2() << endl << "Base 10: " << g.toBase10() << endl << "Base 16: " << g.toBase16() << endl << endl;
	QInt h = *a - *b;
	cout << "h = : " << num0 << " - " << num1 << endl << "Base 2: " << h.toBase2() << endl << "Base 10: " << h.toBase10() << endl << "Base 16: " << h.toBase16() << endl << endl;
	QInt i = *a * *b;
	cout << "i = : " << num0 << " * " << num1 << endl << "Base 2: " << i.toBase2() << endl << "Base 10: " << i.toBase10() << endl << "Base 16: " << i.toBase16() << endl << endl;
	QInt j = *a / *b;
	cout << "j = : " << num0 << " / " << num1 << endl << "Base 2: " << j.toBase2() << endl << "Base 10: " << j.toBase10() << endl << "Base 16: " << j.toBase16() << endl << endl;
	delete a;
	delete b;
	return 0;
}
