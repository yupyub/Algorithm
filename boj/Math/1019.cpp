#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int pre[10][2]; // (0) and (1~9) 
int appear[10];
void accum(string str, int flag) {
	if (str.length() == 0)
		return;
	int ten = 1;
	for (int i = 1; i < str.length(); i++)
		ten *= 10;
	for (int i = flag; i < str[0] - '0'; i++) {
		appear[i] += ten;
	}
	for (int i = 0; i < str[0] - '0'; i++) {
		if (flag && i == 0) appear[0] += pre[str.length() - 1][0];
		else appear[0] += pre[str.length() - 1][1];
		for (int i = 1; i < 10; i++) {
			appear[i] += pre[str.length() - 1][1];
		}
	}
	if (str.length() > 1) {
		string next_str = str.substr(1, str.length());
		accum(next_str, 0);
		appear[str[0] - '0'] += (stoi(next_str) + 1);
	}
	else
		appear[str[0] - '0']++;
}
int main() {
	string N;
	cin >> N;
	pre[1][0] = 0;
	pre[1][1] = 1;
	int ten = 10;
	for (int i = 2; i < 10; i++) {
		pre[i][0] = pre[i - 1][1] * 9 + pre[i - 1][0];
		pre[i][1] = pre[i - 1][1] * 10 + ten;
		ten *= 10;
	}
	accum(N, 1);
	for (int i = 0; i < 10; i++) {
		cout << appear[i] << " ";
	}
	return 0;
}