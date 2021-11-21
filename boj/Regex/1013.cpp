#include <cstdio>
#include <regex>
#include <string>
#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	regex re("((100+)(1+)|01)+");
	while (N--) {
		string str;
		cin >> str;
		if (regex_match(str, re))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}