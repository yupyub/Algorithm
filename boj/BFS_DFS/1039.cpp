#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>
using namespace std;
map<pair<string, int>, int> cache;
int dfs(string num, int len, int K) {
	if (K == 0) {
		int ret = 0;
		for (int i = 0; i < len; i++) {
			ret *= 10;
			ret += num[i] - '0';
		}
		return ret;
	}
	int ret = -1;
	for (int i = 0; i < len; i++) {
		for (int j = i+1; j < len; j++) {
			if (i == 0 && num[j] == '0')
				continue;
			swap(num[i],num[j]);
			if (cache[make_pair(num, K)] == 0) {
				cache[make_pair(num, K)] = 1;
				ret = max(ret, dfs(num, len, K - 1));
			}
			swap(num[i], num[j]);
		}
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string num;
	int K;
	cin >> num >> K;
	cout << dfs(num, num.length(), K);
	return 0;
}