#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
int main() {
	string s1, s2;
	cin >> s1 >> s2;
	vector<int> num1;
	vector<int> num2;
	int idx1 = s1.length() - 1;
	int idx2 = s2.length() - 1;
	for (int i = 0; i <= idx1; i++)
		num1.push_back(s1[i] == '0' ? 0 : 1);
	for (int i = 0; i <= idx2; i++)
		num2.push_back(s2[i] == '0' ? 0 : 1);
	int carry = 0;
	vector<int> ans;
	while (idx1 >= 0 || idx2 >= 0) {
		if (idx1 < 0) {
			ans.push_back((num2[idx2] + carry)%2);
			carry = (num2[idx2] + carry) / 2;
		}
		else if (idx2 < 0) {
			ans.push_back((num1[idx1] + carry) % 2);
			carry = (num1[idx1] + carry) / 2;
		}
		else {
			ans.push_back((num1[idx1] + num2[idx2] + carry) % 2);
			carry = (num1[idx1] + num2[idx2] + carry) / 2;
		}
		idx1--;
		idx2--;
	}
	if (carry)
		ans.push_back(1);
	int flag = 1;
	for (int i = ans.size() - 1; i >= 0; i--) {
		if (flag && ans[i] == 0)
			continue;
		flag = 0;
		printf("%d", ans[i]);
	}
	if (flag == 1)
		printf("0");
	return 0;
}