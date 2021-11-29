#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <tuple>
#include <string>
#include <functional>
#include <queue>
#include <stack>
#include <climits>
#include <iostream>
using namespace std;
#define CINOUT ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF INT_MAX/2-1
typedef long long ll;

int main() {
	CINOUT;
	int N;
	cin >> N;
	map<char, string> match;
	string str;
	char c;
	for (int i = 0; i < N; i++) {
		cin >> str >> c;
		match[c] = str;
	}
	string comp;
	cin >> comp;
	int l, r;
	cin >> l >> r;
	string ans;
	for (int i = 0; i < comp.length(); i++) {
		ans.append(match[comp[i]]);
	}
	for(int i = l-1;i<r;i++)
		cout << ans[i];
	return 0;
}