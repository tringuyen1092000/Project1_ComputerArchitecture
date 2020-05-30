#include "Lib.h"

int main()
{
	int p1, p2, line = 1, sumLine;
	string inputStr, outputStr;
	inputStr = readFile("input.txt");
	/*sumLine = countLine(inputStr);
	cout << sumLine << endl;
	while (line < sumLine)
	{
		string input = readLine(line, inputStr);
		string opr = operation(input, p1, p2);
		outputStr += result(p1, p2, opr);
		line++;
	}
	writeFile("output.txt", outputStr);*/

	string input = readLine(61, inputStr); // Doc dong 61
	string opr = operation(input, p1, p2); // Chuan hoa str va dua vao QInt
	int i = 0; //
	int temp = strToNum(opr, i); //
	opr = opr.substr(i + 1); //
	opr.pop_back(); //
	QInt *q = toQInt(opr, 10); // 
	opr = q->toBase10(); 
	cout << opr << endl;
	QInt p = ROL(*q, 10);
	string str = p.toBase10();
	cout << str << endl;
	//outputStr += result(p1, p2, opr);

	cout << outputStr << endl;
	return 0;
}
