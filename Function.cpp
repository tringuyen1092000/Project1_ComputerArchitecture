#include "Lib.h"

bool isSmaller(string str1, string str2){
	int n1 = str1.length(), n2 = str2.length();
	if (n1 < n2)
		return true;
	if (n1 > n2)
		return false;
	for (int i = 0; i < n1; i++){
		if (str1[i] < str2[i])
			return true;
		else if (str1[i] > str2[i])
			return false;
	}
	return false;
}

string largeSubtract(string str1, string str2) {
	if (isSmaller(str1, str2))
		swap(str1, str2);
	string str = "";
	int n1 = str1.length(), n2 = str2.length();
	int diff = n1 - n2;
	int carry = 0;
	for (int i = n2 - 1; i >= 0; i--) {
		int sub = ((str1[i + diff] - '0') - (str2[i] - '0') - carry);
		if (sub < 0) {
			sub += 10;
			carry = 1;
		}
		else
			carry = 0;
		str.insert(str.begin(), sub + '0');
	}
	
	for (int i = n1 - n2 - 1; i >= 0; i--) {
		if (str1[i] == '0' && carry) {
			str.insert(str.begin(), '9');
			continue;
		}
		int sub = (str1[i] - '0') - carry;
		if (i > 0 || sub > 0)
			str.insert(str.begin(), sub + '0');
		carry = 0;
	}
	while (str[0] == '0') {
		str.erase(str.begin() + 0);
	}
	return str;
}

string largeSum(string str1, string str2){
	if (str1.length() > str2.length())
		swap(str1, str2);
	string str = "";
	int n1 = str1.length(), n2 = str2.length();
	int diff = n2 - n1;
	int carry = 0;
	for (int i = n1 - 1; i >= 0; i--){
		int sum = ((str1[i] - 48) + (str2[i + diff] - 48) + carry);
		str.push_back(sum % 10 + 48);
		carry = sum / 10;
	}
	for (int i = n2 - n1 - 1; i >= 0; i--){
		int sum = ((str2[i] - 48) + carry);
		str.push_back(sum % 10 + 48);
		carry = sum / 10;
	}
	if (carry)
		str.push_back(carry + 48);
	reverse(str.begin(), str.end());
	return str;
}

int multiply(int x, int res[], int res_size) {
	int carry = 0;
	for (int i = 0; i < res_size; i++) {
		int prod = res[i] * x + carry;
		res[i] = prod % 10;
		carry = prod / 10;
	}
	while (carry) {
		res[res_size] = carry % 10;
		carry = carry / 10;
		res_size++;
	}
	return res_size;
}

string power(int x, int n){
	if (n == 0) {
		return "1";
	}
	int* res = new int[MAX];
	int res_size = 0;
	int temp = x;
	while (temp != 0) {
		res[res_size++] = temp % 10;
		temp = temp / 10;
	}
	for (int i = 2; i <= n; i++)
		res_size = multiply(x, res, res_size);
	string result = "";
	for (int i = res_size - 1; i >= 0; i--)
		result += res[i] + 48;
	delete[] res;
	return result;
}

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
	case '0': return "0000";
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
	if (s == "0000") return '0';
	if (s == "0001") return '1';
	if (s == "0010") return '2';
	if (s == "0011") return '3';
	if (s == "0100") return '4';
	if (s == "0101") return '5';
	if (s == "0110") return '6';
	if (s == "0111") return '7';
	if (s == "1000") return '8';
	if (s == "1001") return '9';
	if (s == "1010") return 'A';
	if (s == "1011") return 'B';
	if (s == "1100") return 'C';
	if (s == "1101") return 'D';
	if (s == "1110") return 'E';
	if (s == "1111") return 'F';
	return NULL;
}

string strToBase2(string number, int oldBase) {
	if (oldBase == 2) {
		return number;
	}
	else if (oldBase == 10) {
		if (number == "0") return number;
		bool sign = false;
		if (number[0] != '-') {
			sign = false;
		}
		else {
			sign = true;
			number.erase(number.begin() + 0);
		}
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
		if (sign == false)
			return result;
		bitset<128> tmp(result);
		tmp.flip();
		result = tmp.to_string();
		for (int i = 127; i >= 0; i--) {
			if (result[i] == '0') {
				result[i] = '1';
				break;
			}
			else {
				result[i] = '0';
			}
		}
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

QInt::QInt() {
	arrBit[0] = arrBit[1] = 0;
}

void QInt::setBit(unsigned long long value, int pos) {
	arrBit[pos] = value;
}

unsigned long long QInt::getBit(int pos) {
	return arrBit[pos];
}

string QInt::toBase2() {
	if (arrBit[0] == 0) {
		string tmp1 = to_string(arrBit[1]);
		return strToBase2(tmp1, 10);
	}
	string tmp0 = to_string(arrBit[0]);
	bitset<64> tmp1(arrBit[1]);
	return strToBase2(tmp0, 10) + tmp1.to_string();
}

string QInt::toBase10() {
	if (arrBit[0] == 0) {
		string tmp1 = to_string(arrBit[1]);
		return tmp1;
	}
	string bitString = this->toBase2();
	int l = bitString.length();
	string result = "";
	if (l < 128) {
		for (int i = 0; i < l; i++) {
			if (bitString[i] == '1')
				result = largeSum(result, power(2, l - i - 1));
		}
	}
	else {
		for (int i = 1; i < l; i++) {
			if (bitString[i] == '1')
				result = largeSum(result, power(2, l - i - 1));
		}
		string pow64 = "170141183460469231731687303715884105728";
		result = largeSubtract(pow64, result);
		result.insert(result.begin(), '-');
	}
	return result;
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
		newQInt->setBit(a.to_ullong(), 0);
		newQInt->setBit(b.to_ullong(), 1);
	}
	else {
		bitset<64> b(tmp);
		newQInt->setBit(b.to_ullong(), 1);
	}
	return newQInt;
}

QInt operator&(const QInt& q1, const QInt& q2){
	QInt result;
	bitset<64> a(q1.arrBit[0]);
	bitset<64> b(q1.arrBit[1]);
	bitset<64> c(q2.arrBit[0]);
	bitset<64> d(q2.arrBit[1]);
	bitset<128> e(a.to_string() + b.to_string());
	bitset<128> f(c.to_string() + d.to_string());
	bitset<128> bitArr = e & f;
	result = *toQInt(bitArr.to_string(), 2);
	return result;
}

QInt operator|(const QInt& q1, const QInt& q2){
	QInt result;
	bitset<64> a(q1.arrBit[0]);
	bitset<64> b(q1.arrBit[1]);
	bitset<64> c(q2.arrBit[0]);
	bitset<64> d(q2.arrBit[1]);
	bitset<128> e(a.to_string() + b.to_string());
	bitset<128> f(c.to_string() + d.to_string());
	bitset<128> bitArr = e | f;
	result = *toQInt(bitArr.to_string(), 2);
	return result;
}

QInt operator^(const QInt& q1, const QInt& q2){
	QInt result;
	bitset<64> a(q1.arrBit[0]);
	bitset<64> b(q1.arrBit[1]);
	bitset<64> c(q2.arrBit[0]);
	bitset<64> d(q2.arrBit[1]);
	bitset<128> e(a.to_string() + b.to_string());
	bitset<128> f(c.to_string() + d.to_string());
	bitset<128> bitArr = e ^ f;
	result = *toQInt(bitArr.to_string(), 2);
	return result;
}

QInt operator~(const QInt& q){
	QInt result;
	bitset<64> a(q.arrBit[0]);
	bitset<64> b(q.arrBit[1]);
	bitset<128> c(a.to_string() + b.to_string());
	c = c.flip();
	string tmp1 = c.to_string().substr(0, 64);
	string tmp2 = c.to_string().substr(64, 64);
	result = *toQInt(tmp1 + tmp2, 2);
	return result;
}

void QInt::operator=(const QInt& q) {
	this->arrBit[0] = q.arrBit[0];
	this->arrBit[1] = q.arrBit[1];
}

QInt operator+(const QInt& q1, const QInt& q2) {
	QInt result;
	bitset<64> a(q1.arrBit[0]);
	bitset<64> b(q1.arrBit[1]);
	bitset<64> c(q2.arrBit[0]);
	bitset<64> d(q2.arrBit[1]);
	bitset<128> e(a.to_string() + b.to_string());
	bitset<128> f(c.to_string() + d.to_string());	
	bitset<128> bitArr;
	bitset<1> carry(0);
	for (int i = 0; i < 128; i++) {
		int count = 0;
		bitArr[i] = e[i] ^ f[i] ^ carry[0];
		if (e[i] == 1) count++;
		if (f[i] == 1) count++;
		if (carry[0] == 1) count++;
		if (count > 1) carry[0] = 1;
		else carry[0] = 0;
	}
	if (e[127] == f[127]) {
		if (e[127] == 0 && bitArr[127] == 1) return result;
		if (e[127] == 1 && bitArr[127] == 0) return result;
	}
	result = *toQInt(bitArr.to_string(), 2);
	return result;
}

QInt operator-(const QInt& q1, const QInt& q2) {
	QInt tmp = q2;
	string base10 = tmp.toBase10();
	if (base10[0] == '-') base10.erase(base10.begin());
	else base10.insert(base10.begin(), '-');
	tmp = *toQInt(base10, 10);
	return q1 + tmp;
}

QInt operator*(const QInt& q1, const QInt& q2) {
	QInt tmp1 = q1, tmp2 = q2;
	string a = tmp1.toBase2(), b = tmp2.toBase2();
	int count = 0;
	bool sign = false;
	if (a.length() == 128) {
		count++;
		int l1 = a.length();
		for (int i = l1 - 1; i >= 0; i--) {
			if (a[i] == '1') {
				a[i] = '0';
				break;
			}
			else {
				a[i] = '1';
			}
		}
		for (int i = 0; i < l1; i++) {
			a[i] = !(a[i] - 48) + 48;
		}
		while (a[0] == '0') a.erase(a.begin());
	}
	if (b.length() == 128) {
		count++;
		int l2 = b.length();
		for (int i = l2 - 1; i >= 0; i--) {
			if (b[i] == '1') {
				b[i] = '0';
				break;
			}
			else {
				b[i] = '1';
			}
		}
		for (int i = 0; i < l2; i++) {
			b[i] = !(b[i] - 48) + 48;
		}
		while (b[0] == '0') b.erase(b.begin());
	}
	if (count == 1) sign = true;
	if (a.length() < b.length())
		swap(a, b);
	int l1 = a.length(), l2 = b.length();
	string bitArr = "";
	for (int i = l2 - 1; i >= 0; i--) {
		string tmpMult = "";
		if (b[i] == '1') tmpMult = a;
		else tmpMult.append(l1, '0');
		tmpMult.append(l2 - i - 1, '0');
		bitArr.insert(bitArr.begin(), tmpMult.length() - bitArr.length(), '0');
		int carry = 0;
		string tmpString = "";
		for (int j = bitArr.length() - 1; j >= 0; j--) {
			int count = 0;
			int c = (bitArr[j]-48) ^ (tmpMult[j]-48) ^ (carry);
			if (bitArr[j] == '1') count++;
			if (tmpMult[j] == '1') count++;
			if (carry == 1) count++;
			if (count > 1) carry = 1;
			else carry = 0;
			bitArr[j] = c + 48;
		}
		if (carry == 1) {
			bitArr.insert(bitArr.begin(), '1');
		}
	}
	QInt result;
	if (sign == true) {
		if (isSmaller(bitArr, minBase2) == false && bitArr != minBase2) return result;
		bitArr.insert(0, 128 - bitArr.length(), '0');
		for (int i = 0; i < bitArr.length(); i++) {
			bitArr[i] = !(bitArr[i] - 48) + 48;
		}
		for (int i = bitArr.length() - 1; i >= 0; i--) {
			if (bitArr[i] == '0') {
				bitArr[i] = '1';
				break;
			}
			else {
				bitArr[i] = '0';
			}
		}
	}
	else {
		if (bitArr.length() > 127) return result;
	}
	result = *toQInt(bitArr, 2);
	return result;
}

QInt operator/(const QInt& q1, const QInt& q2) {
	QInt tmp1 = q1, tmp2 = q2;
	string a = tmp1.toBase2();
	string b = tmp2.toBase2();
	int count = 0;
	bool sign = false;	
	if (a.length() == 128) {
		count++;
		int l1 = a.length();
		for (int i = l1 - 1; i >= 0; i--) {
			if (a[i] == '1') {
				a[i] = '0';
				break;
			}
			else {
				a[i] = '1';
			}
		}
		for (int i = 0; i < l1; i++) {
			a[i] = !(a[i] - 48) + 48;
		}
		while (a[0] == '0') a.erase(a.begin());
	}
	if (b.length() == 128) {
		count++;
		int l2 = b.length();
		for (int i = l2 - 1; i >= 0; i--) {
			if (b[i] == '1') {
				b[i] = '0';
				break;
			}
			else {
				b[i] = '1';
			}
		}
		for (int i = 0; i < l2; i++) {
			b[i] = !(b[i] - 48) + 48;
		}
		while (b[0] == '0') b.erase(b.begin());
	}
	if (count == 1) sign = true;
	int pos = 0;
	string dividend = "", quotient = "";
	dividend += a[pos];
	int l = a.length();
	while (pos < l) {
		if (isSmaller(dividend, b)) {
			pos++;
			dividend += a[pos];
		}
		else {
			break;
		}
	}
	while (pos < l) {
		if (isSmaller(dividend, b) == false) {
			quotient += '1';
			int carry = 0;
			int dl = dividend.length();
			string tmpDivisor = b;
			tmpDivisor.insert(0, dl - tmpDivisor.length(), '0');
			for (int i = dl - 1; i >= 0; i--) {
				int count = 0;
				dividend[i] = ((dividend[i] - 48) ^ (tmpDivisor[i] - 48) ^ carry) + 48;
				if (dividend[i] == '1') count++;
				if (tmpDivisor[i] == '1') count++;
				if (carry == 1) count++;
				if (count > 1) carry = 1;
				else carry = 0;
			}
		}
		else {
			quotient += '0';
		}
		pos++; 
		while (dividend[0] == '0') dividend.erase(dividend.begin());
		dividend += a[pos];
	}
	bitset<128> tmp(quotient);
	quotient = tmp.to_string();
	QInt result;
	if (sign == true) {
		for (int i = 127; i >= 0; i--) {
			quotient[i] = !(quotient[i] - 48) + 48;
		}
		for (int i = 127; i >= 0; i--) {
			if (quotient[i] == '0') {
				quotient[i] = '1';
				break;
			}
			else {
				quotient[i] = '0';
			}
		}
	}
	else {
		if (tmp[127] == 1) return result;
	}
	result = *toQInt(quotient, 2);
	return result;
}

string readFile(const char* input)
{
	fstream inp(input);
	if (!inp)
	{
		cerr << "Unable to open file input.txt";
		exit(1);   // call system to stop
	}
	string line;
	while (!inp.eof())
	{
		string temp;
		getline(inp, temp);
		line = line + temp + '\n';
	}
	inp.close();
	return line;
}

string readLine(int num, string inputStr) //Read the num line in file
{
	int count = 1, i = 0;
	string str;
	for (i; count != num; i++)
		if (inputStr[i] == '\n') count++;
	while (inputStr[i] != '\n')
	{
		str += inputStr[i];
		i++;
	}
	str += '\n';
	return str;
}

bool isNum(string str, int pos)
{
	for(pos; str[pos] != ' ' && str[pos] != '\n'; pos++)
		if(str[pos] < '0' || str[pos] > '9') return 0;
	return 1;
}

int strToNum(string str, int &pos)
{
	int value = 0;
	for(pos; str[pos] != ' '; pos++)
	{
		value *= 10;
		value += str[pos] - 48;
	}
	return value;
}

int countSpace(string str, int pos)
{
	int count = 0;
	while(str[pos] != '\n')
	{
		if (str[pos] == ' ') count++;
		pos++;
	}
	return count;
}

string operation(string str, int& p1, int& p2)
{
	string opr;
	int i = 0, size = 0;
	p1 = strToNum(str, i);
	i++;
	//Check if p2 exist in input line
	if (countSpace(str, i) < 2 && isNum(str, i))
	{
		p2 = strToNum(str, i);
		opr = str.substr(i + 1);
	}
	else opr = str.substr(i);
	return opr;
}
