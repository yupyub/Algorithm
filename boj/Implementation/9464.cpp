#include <cstdio>
#include <vector>
#include <algorithm>
#include <string.h>
#include <set>
using namespace std;
typedef long long ll;
set<pair<ll,pair<ll,ll> > > s;
void swap(ll *a, ll *b) {
	ll tmp = *a;
	*a = *b;
	*b = tmp;
}
ll gcd(ll a, ll b) {
	while (b != 0) {
		ll temp = a%b;
		a = b;
		b = temp;
	}
	return abs(a);
}
void pita() {
	ll w, h, gw, gh, g;
	int num = 0;
	for (int i = 3;num<5000; i++) {
		for (int j = 1; j < i/2+2; j++) {
			ll ii = (ll)(i - j);
			ll jj = (ll)j;
			if (ii <= jj)
				continue;
			w = 2 * ii*jj;
			h = ii*ii - jj*jj;
			if (h < w)
				swap(&h, &w);
			g = gcd(h, w);
			gw = w / g;
			gh = h / g;
			s.insert(make_pair(2*(gw+gh),make_pair(gw, gh)));
			num++;
		}
	}
}
int sol(ll len) {
	int ans = 0;
	for (set<pair<ll,pair<ll, ll> > >::iterator a = s.begin(); a != s.end();a++) {
		len -= (*a).first;
		if (len >= 0)
			ans++;
		else return ans;
	}
}
int main() {
	int t;
	scanf("%d", &t);
	pita();
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", sol((ll)n));
	}
}