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
int arr[200010];
ll MOD = 1000000007;
ll comb[200001][101];

int main() {
	for (int i = 0; i < 200001; i++) {
		for (int j = 0; j < 101 && j<=i; j++) {
			if (i == j || j == 0)
				comb[i][j] = 1;
			else
				comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j])%MOD;
		}
	}
	int T;
	scanf("%d", &T);
	while (T--) {
		int n,m,k;
		scanf("%d %d %d", &n,&m,&k);
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		sort(arr, arr + n);
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			int u = upper_bound(arr, arr + n, arr[i] + k) - arr;
			if (u - i >= m)
				ans = (ans + comb[u - i - 1][m-1]) % MOD;
		}
		printf("%lld\n", ans);
	}
}