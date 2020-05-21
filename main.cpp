#include<iostream>
using namespace std;
#include<limits.h>
#include<bitset>
#include <string>

string divBy2(string number) {
	string result;
	size_t pos = 0;
	int tmp = number[pos] - 48;
	if (tmp < 2) {
		pos++;
		tmp = tmp * 10 + (number[pos] - 48);
	}
	while (number.length() > pos) {
		result += (tmp / 2) + 48;
		pos++;
		tmp = (tmp % 2) * 10 + (number[pos] - 48);
	}
	if (result.length() == 0)
		return "0";
	return result;
}

string base16Table(char c) {
	switch (c) {
	case '1': return "0001";
	case '2': return "0010";
	case '3': return "0011";
	case '4': return "0100";
	case '5': return "0101";
	case '6': return "0110";
	case '7': return "0111";
	case '8': return "1000";
	case '9': return "1001";
	case 'A': return "1010";
	case 'B': return "1011";
	case 'C': return "1100";
	case 'D': return "1101";
	case 'E': return "1110";
	case 'F': return "1111";
	}
	return NULL;
}

char base16Table(string s) {
	if(s == "0001") return '1';
	if(s == "0010") return '2';
	if(s == "0011") return '3';
	if(s == "0100") return '4';
	if(s == "0101") return '5';
	if(s == "0110") return '6';
	if(s == "0111") return '7';
	if(s == "1000") return '8';
	if(s == "1001") return '9';
	if(s == "1010") return 'A';
	if(s == "1011") return 'B';
	if(s == "1100") return 'C';
	if(s == "1101") return 'D';
	if(s == "1110") return 'E';
	if(s == "1111") return 'F';
	return NULL;
}

string strToBase2(string number, int oldBase) {
	if (oldBase == 2) {
		return number;
	}
	else if (oldBase == 10) {
		string result = "";
		while (number != "0") {
			if ((number[number.length() - 1] - 48) % 2 == 1) {
				result += '1';
			}
			else {
				result += '0';
			}
			number = divBy2(number);
		}
		reverse(result.begin(), result.end());
		return result;
	}
	else if (oldBase == 16) {
		string result = "";
		for (size_t i = 0; i < number.length(); i++) {
			result += base16Table(number[i]);
		}
		return result;
	}
	return "";
}

class QInt {
	private:
		long long arrBit[2];
	public:
		QInt();
		void setBit(long long value, int pos);
		long long getBit(int pos);
		string toBase2();
		string toBase10();
		string toBase16();
};
QInt::QInt() {
	arrBit[0] = arrBit[1] = 0;
}
void QInt::setBit(long long value, int pos) {
	arrBit[pos] = value;
}

long long QInt::getBit(int pos) {
	return arrBit[pos];
}

string QInt::toBase2() {
	string tmp1 = to_string(arrBit[0]);
	string tmp2 = to_string(arrBit[1]);
	return strToBase2(tmp1, 10) + strToBase2(tmp2, 10);
}

string QInt::toBase10() {
	string tmp1 = to_string(arrBit[0]);
	string tmp2 = to_string(arrBit[1]);
	return tmp1 + tmp2;
}

string QInt::toBase16() {
	string result = "";
	string tmp = this->toBase2();
	int n = tmp.length() % 4;
	if (n != 0) {
		string addZero = "";
		for (int i = 0; i < 4 - n; i++) {
			addZero += "0";
		}
		tmp.insert(0, addZero);
	}
	n = tmp.length();
	for (int i = 0; i < n; i += 4) {
		result += base16Table(tmp.substr(i, 4));
	}
	return result;
}

QInt* toQInt(string number, int oldBase) {
	QInt* newQInt = new QInt;
	string tmp = strToBase2(number, oldBase);
	int l = tmp.length();
	if (l > 64) {
		bitset<64> a(tmp.substr(0, l - 64));
		bitset<64> b(tmp.substr(l - 64, 64));
		string str1 = a.to_string();
		string str2 = b.to_string();
		long long tmp1 = 0, tmp2 = 0;
		for (int i = 0; i < 64; i++) {
			long long s = (long long)str1[i] - 48;
			tmp1 |= s << (63 - i);
			s = (long long)str1[i] - 48;
			tmp2 |= s << (63 - i);
		}
		newQInt->setBit(tmp1, 0);
		newQInt->setBit(tmp2, 1);
		
	}
	else {
		bitset<64> b(tmp.substr(0, l));
		string str2 = b.to_string();
		long long tmp2 = 0;
		for (int i = 0; i < 64; i++) {
			long long s = (long long)str2[i] - 48;
			tmp2 |= s << (63 - i);
			newQInt->setBit(tmp2, 1);
		}
	}
	return newQInt;
}

int main() {
	string num = "1166B";
	QInt* a = toQInt(num, 16);
	cout << a->toBase2() << " " << a->toBase10() << " " << a->toBase16()<< endl;
	//string test = "340282366920938463463374607431768211456";	
	delete[] a;
	return 0;
}