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
vector<pair<int, int> >line;
ll INF = 987654321987654321;
ll dist[50001][2];
priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int> >, greater< tuple<ll, int, int> > > pq;
int main() {
	int N, S;
	int a, b;
	scanf("%d %d", &N, &S);
	line.resize(N + 1);
	line[0] = make_pair(-100001, 100001);
	for (int i = N; i > 0; i--) {
		scanf("%d %d", &a, &b);
		if(a>b)
			line[i] = make_pair(b, a);
		else
			line[i] = make_pair(a, b);
	}
	for (int i = 0; i <= N; i++)
		dist[i][0] = dist[i][1] = INF;
	pq.push(make_tuple(0, N + 1, S));
	ll ans = INF;
	while (!pq.empty()) {
		ll d = get<0>(pq.top());
		int h = get<1>(pq.top());
		int x = get<2>(pq.top());
		//printf("%lld %d %d\n", d, h, x);
		pq.pop();
		if (d > ans)
			break;
		if (h == 0) {
			ans = min(ans, d + abs(x));
		}
		for (int i = h - 1; i >= 0; i--) {
			int a = line[i].first;
			int b = line[i].second;
			if (a <= x && x <= b) {
				if (i == 0) {
					if (dist[i][0] > d + abs(x)) {
						dist[i][0] > d + abs(x);
						pq.push(make_tuple(d + abs(x), i, 0));
					}
				}
				else {
					if (dist[i][0] > d + (ll)x - a) {
						dist[i][0] = d + (ll)x - a;
						pq.push(make_tuple(d + (ll)x - a, i, a));
					}
					if (dist[i][1] > d + (ll)b - x) {
						dist[i][1] = d + (ll)b - x;
						pq.push(make_tuple(d + (ll)b - x, i, b));
					}
				}
				break;
			}
		}
	}
	printf("%lld\n", ans);
}