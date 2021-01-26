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
ll comb[1001][1001];
int main() {
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			if (i == j || j == 0)
				comb[i][j] = 1;
			else
				comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j])%1000000007;
		}
	}
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d %d", &n, &k);
		int num[1001] = { 0, };
		int arr[1001];
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			num[arr[i]]++;
		}
		sort(arr, arr + n,greater<>());
		int pos = arr[0];
		int cnt = 0;
		ll ans = 1;
		k++;
		for (int i = 0; k; i++, k--) {
			if (arr[i] != pos || k == 1) {
				//printf(">> %d %d\n", pos, cnt);
				ans = (ans * comb[num[pos]][cnt])%1000000007;
				cnt = 0;
				pos = arr[i];
			}
			cnt++;
		}
		printf("%lld\n", ans);
	}
}