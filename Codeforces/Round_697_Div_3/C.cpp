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
int boy[200001];
int girl[200001];
pair<int, int> v[200001];
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b, k;
		scanf("%d%d%d", &a, &b, &k);
		int o;
		for (int i = 0; i < a; i++) 
			boy[i + 1] = 0;
		for (int j = 0; j < b; j++)
			girl[j + 1] = 0;
		for (int i = 0; i < k; i++) {
			scanf("%d", &v[i].first);
			boy[v[i].first]++;
		}
		for (int i = 0; i < k; i++) {
			scanf("%d", &v[i].second);
			girl[v[i].second]++;
		}
		ll ans = 0;
		for (int i = 0; i < k; i++) {
			ans += k - (boy[v[i].first] + girl[v[i].second]) + 1;
		}
		printf("%lld\n", ans/2);
	}
}