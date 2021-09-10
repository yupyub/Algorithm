#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
int main() {
	string str;
	cin >> str;
	str += "XXX";
	int ans = 0;
	int idx = 0;
	while(idx < str.length()-3) {
		if (str[idx] == 'p') {
			if (str[idx + 1] == 'i') {
				idx += 2;
				continue;
			}
		}
		else if (str[idx] == 'k') {
			if (str[idx + 1] == 'a') {
				idx += 2;
				continue;
			}
		}
		else if (str[idx] == 'c') {
			if (str[idx + 1] == 'h' && str[idx + 2] == 'u') {
				idx += 3;
				continue;
			}
		}
		ans = 1;
		break;
	}
	if (ans)
		printf("NO");
	else
		printf("YES");

	return 0;
}