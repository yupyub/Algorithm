#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;
int posL[26];
int posR[26];
int cnt[26];
int cache[27][50];
int simulate(int pos, int alp) {
	if (alp == 26)
		return 0;
	int& ret = cache[alp][pos];
	if (ret != -1)
		return ret;
	if (cnt[alp] != 0)
		ret = min(simulate(posL[alp], alp + 1) + abs(pos - posR[alp]), simulate(posR[alp], alp + 1) + abs(pos - posL[alp])) + cnt[alp] + posR[alp]-posL[alp];
	else
		ret = simulate(pos, alp + 1);
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	cin >> str;
	memset(posL, 64, sizeof(posL));
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < str.length(); i++) {
		int c = str[i] - 'a';
		posL[c] = min(posL[c], i);
		posR[c] = max(posR[c], i);
		cnt[c]++;
	}
	cout << simulate(0,0);
	return 0;
}