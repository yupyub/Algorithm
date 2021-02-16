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
ll num[200010];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, a;
		scanf("%d", &n);
		for (int i = 1; i <= n + 2; i++)
			num[i] = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a);
			num[a]++;
		}
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += num[i] * (num[i] - 1) * (num[i] - 2) / 6;
			ans += num[i] * (num[i] - 1) * (num[i + 1]) / 2;
			ans += num[i] * (num[i] - 1) * (num[i + 2]) / 2;
			ans += num[i] * (num[i + 1]) * (num[i + 1] - 1) / 2;
			ans += num[i] * (num[i + 1]) * (num[i + 2]);
			ans += num[i] * (num[i + 2]) * (num[i + 2] - 1) / 2;
		}
		printf("%lld\n", ans);
	}
}