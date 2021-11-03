#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define INF 987654321
int cache[50][50];
int solve(string str, int l, int r) {
	if (l >= r)
		return 0;
	if (cache[l][r] != INF)
		return cache[l][r];
	int& ret = cache[l][r];
	if (str[l] == str[r])
		ret = solve(str, l + 1, r - 1);
	ret = min(ret, solve(str, l + 1, r) + 1);
	ret = min(ret, solve(str, l, r-1) + 1);
	ret = min(ret, solve(str, l + 1, r-1) + 1);
	return ret;
}

int main() {
	string str;
	cin >> str;
	int len = str.length();
	for (int ii = 0; ii < len; ii++)
		for (int jj = 0; jj < len; jj++)
			cache[ii][jj] = INF;
	int ans = solve(str, 0, len-1);
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			if (str[i] == str[j])
				continue;
			for (int ii = 0; ii < len; ii++)
				for (int jj = 0; jj < len; jj++)
					cache[ii][jj] = INF;
			swap(str[i], str[j]);
			ans = min(ans, solve(str, 0, len - 1) + 1);
			swap(str[i], str[j]);
		}
	}
	cout << ans << endl;
	return 0;
}