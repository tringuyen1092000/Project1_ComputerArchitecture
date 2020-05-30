#pragma once
#include <iostream>
#include <limits.h>
#include <bitset>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#define MAX 100

using namespace std;

static string minBase2 = "10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
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
	friend QInt operator&(const QInt& q1, const QInt& q2);
	friend QInt operator|(const QInt& q1, const QInt& q2);
	friend QInt operator^(const QInt& q1, const QInt& q2);
	friend QInt operator~(const QInt& q);
	void operator=(const QInt& q);
	friend QInt operator+(const QInt& q1, const QInt& q2);
	friend QInt operator-(const QInt& q1, const QInt& q2);
	friend QInt operator*(const QInt& q1, const QInt& q2);
	friend QInt operator/(const QInt& q1, const QInt& q2);
	friend QInt operator<<(QInt q, int x);
	friend QInt operator>>(QInt q, int x);
};

bool isSmaller(string str1, string str2);
string largeSubtract(string str1, string str2);
string largeSum(string str1, string str2);
int multiply(int x, int res[], int res_size);
string power(int x, int n);
string divBy2(string number);
string base16Table(char c);
char base16Table(string s);
string strToBase2(string number, int oldBase);
QInt* toQInt(string number, int oldBase);

QInt ROR(QInt q, int n);
QInt ROL(QInt q, int n);

string readFile(const char* name);
string readLine(int num, string inputStr);
bool isNum(string str, int pos);
int strToNum(string str, int &pos);
string toStr(QInt q, int base);
int countSpace(string str, int pos);
string operation(string inputStr, int& p1, int& p2);
string result(int p1, int p2, string opr);
void writeFile(const char* name, string outputStr);
int countLine(string inputStr);