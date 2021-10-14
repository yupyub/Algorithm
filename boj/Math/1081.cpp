#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
long long accum(string str) {
	if (str.length() == 0)
		return 0;
	long long ten = 1;
	for (int i = 1; i < str.length(); i++)
		ten *= 10;
	long long nine = 45 * (ten / 10) * (str.length() - 1);
	long long ret = 0;
	for (int i = 0; i < str[0] - '0'; i++) {
		ret += i * ten + nine;
	}
	if (str.length() > 1) {
		string next_str = str.substr(1, str.length());
		ret += (str[0] - '0') * (stoi(next_str) + 1) + accum(next_str);
	}
	else
		ret += str[0] - '0';
	return ret;
}
int main() {
	int L;
	string U;
	cin >> L >> U;
	if (L == 0)
		cout << accum(U);
	else
		cout << accum(U) - accum(to_string(L - 1));
	return 0;
}