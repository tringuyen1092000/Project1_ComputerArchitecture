#pragma once
#include <iostream>
using namespace std;
#include <limits.h>
#include <bitset>
#include <string>

class QInt
{
private:
    long long arrBits[2];
public:
    void setBit(long long value, int pos);
	long long getBit(int pos);
	string toBase2();
	string toBase10();
	string toBase16();
public:
    QInt();
    ~QInt();
};

string divBy2(string number);
string base16Table(char c);
char base16Table(string s);
string strToBase2(string number, int oldBase);
QInt* toQInt(string number, int oldBase);
