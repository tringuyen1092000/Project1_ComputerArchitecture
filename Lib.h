#pragma once
#include <iostream>
using namespace std;
#include <limits.h>
#include <bitset>
#include <string>
#define MAX 100

class QInt {
private:
	unsigned long long arrBit[2];
public:
	QInt();
	void setBit(unsigned long long value, int pos);
	unsigned long long getBit(int pos);
	string toBase2();
	string toBase10();
	string toBase16();
};

QInt* toQInt(string number, int oldBase);
bool isSmaller(string str1, string str2);
string largeSubtract(string str1, string str2);
string largeSum(string str1, string str2);
int multiply(int x, int res[], int res_size);
string power(int x, int n);
string divBy2(string number);
string base16Table(char c);
char base16Table(string s);
string strToBase2(string number, int oldBase);
