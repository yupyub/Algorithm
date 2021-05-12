#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <cstring>
#include <string>
#include <functional>
#include <tuple>
#include <set>
#include <map>
using namespace std;
typedef long long ll;

int main() {
	int N, C;
	scanf("%d %d", &N, &C);
	int M;
	scanf("%d", &M);
	vector<tuple<int, int, int> > v;
	while (M--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v.push_back(make_tuple(b,a,c));
	}
	sort(v.begin(), v.end());
	int box[2001] = { 0, };
	int ans = 0;
	for (auto oo : v) {
		int a = get<1>(oo);
		int b = get<0>(oo);
		int c = get<2>(oo);
		int cost = 0;
		int maxi = 0;
		for (int i = a; i < b; i++)
			maxi = max(maxi, box[i]);
		if (maxi + c <= C)
			cost = c;
		else if (maxi < C)
			cost = C - maxi;
		ans += cost;
		for (int i = a; i < b; i++)
			box[i] += cost;
	}
	printf("%d\n", ans);
}



