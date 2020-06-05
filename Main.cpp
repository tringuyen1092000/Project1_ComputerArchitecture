#include "Lib.h"

int main()
{
	int p1, p2, line = 1, sumLine;
	string inputStr, outputStr;
	inputStr = readFile("input.txt");
	sumLine = countLine(inputStr);
	while (line < sumLine)
	{
		string input = readLine(line, inputStr);
		string opr = operation(input, p1, p2);
		outputStr += result(p1, p2, opr);
		line++;
	}
	writeFile("output.txt", outputStr);
	return 0;
}
