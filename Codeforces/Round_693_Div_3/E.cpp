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
vector<tuple<int, int, int> > v;
int ans[200001];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		v.clear();
		int a, b;
		for (int i = 1; i <= n; i++) {
			scanf("%d %d", &a, &b);
			if (a > b)
				v.push_back(make_tuple(b, a, i));
			else
				v.push_back(make_tuple(a, b,i));
		}
		sort(v.begin(), v.end());
		int na, nb, nn, pa, pb, pn, ppb,ppn;
		ppb = 1987654321;
		ppn = -1;
		pb = get<1>(v[0]);
		pn = get<2>(v[0]);
		ans[pn] = -1;
		for (int i = 1; i < n;i++) {
			pa = get<0>(v[i-1]);
			na = get<0>(v[i]);
			nb = get<1>(v[i]);
			nn = get<2>(v[i]);
			if(pa<na){
				if(ppb>pb){
					ppb = pb;
					ppn = pn;
				}
				if(ppb<nb)
					ans[nn] = ppn;
				else
					ans[nn] = -1;
				pb = nb;
				pn = nn;
			}
			else{ // pa == na && pb <= nb
				if(ppb<nb)
					ans[nn] = ppn;
				else
					ans[nn] = -1;
			}
		}
		for (int i = 1; i <= n; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
}