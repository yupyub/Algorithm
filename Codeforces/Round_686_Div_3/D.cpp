#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
vector<pair<int,ll> > v;
void calc(ll num) {
	for (ll i = 2; i*i <= num; i++) {
		if (num % i == 0) {
			v.push_back(make_pair(1,i));
			num /= i;
		}
		while (num % i == 0) {
			v[v.size()-1].first++;
			num /= i;
		}
	}
	if (num != 1)
		v.push_back(make_pair(1,num));
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		ll n;
		scanf("%lld", &n);
		v.clear();
		calc(n);
		vector<ll> ans;
		int idx = 0;
		sort(v.begin(), v.end());
		for (int i = 0; i < v[v.size() - 1].first; i++) {
			ans.push_back(v[v.size() - 1].second);
		}
		int idx2 = ans.size()-1;
		for (int i = v.size() - 2; i >= 0; i--) {
			int num = v[i].second;
			for (int j = 0; j < v[i].first; j++) {
				ans[ans.size() - j - 1] *= num;
			}
		}
		printf("%d\n", ans.size());
		for (ll i : ans) {
			printf("%lld ", i);
		}
		printf("\n");
	}
}