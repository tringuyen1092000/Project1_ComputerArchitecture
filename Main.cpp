#include "Lib.h"

int main()
{
	int p1, p2, line = 1, sumLine;
	string inputStr, outputStr;
	inputStr = readFile("input.txt");
	sumLine = countLine(inputStr);
	cout << sumLine << endl;
	while (line < sumLine)
	{
		string input = readLine(line, inputStr);
		string opr = operation(input, p1, p2);
		outputStr += result(p1, p2, opr);
		line++;
	}
	writeFile("output.txt", outputStr);

	// string input = readLine(13, inputStr);
	// string opr = operation(input, p1, p2);
	// outputStr += result(p1, p2, opr);

	cout << outputStr << endl;
	return 0;
}
