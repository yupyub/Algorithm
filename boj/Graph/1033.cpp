#include <cstdio>
#include <vector>
#include <tuple>
using namespace std;
vector<tuple<int, long long, long long> >g[10];
long long cost[10];
long long gcd(long long a, long long b) {
	return b ? gcd(b, a % b) : a;
}
long long dfs1(int n, long long c, int p) {
	long long ret = c;
	for (auto nxt : g[n]) {
		if (get<0>(nxt) == p)
			continue;
		long long re = dfs1(get<0>(nxt), c * get<1>(nxt), n);
		long long d = gcd(ret, re);
		ret *= re / d;
	}
	return ret;
}
void dfs2(int n, long long c) {
	cost[n] = c;
	for (auto nxt : g[n]) {
		if (cost[get<0>(nxt)] != 0)
			continue;
		dfs2(get<0>(nxt), (c / get<1>(nxt)) * get<2>(nxt));
	}
}
int main() {
	int N, a, b;
	long long p, q;
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d %lld %lld", &a, &b, &p, &q);
		long long d = gcd(p, q);
		g[a].push_back(make_tuple(b, p / d, q / d));
		g[b].push_back(make_tuple(a, q / d, p / d));
	}
	long long c = dfs1(0, 1, -1);
	dfs2(0, c);
	c = cost[0];
	for (int i = 1; i < N; i++)
		c = gcd(c, cost[i]);
	/*
	GCD 로 한번 더 나누어주지 않는 경우, 아래와 같은 반례 발생
	3
	0 1 9 2
	1 2 2 1
	ans : 9 2 1
	wrong ans: 18 4 2
	*/
	for (int i = 0; i < N; i++)
		printf("%lld ", cost[i]/c);
	return 0;
}