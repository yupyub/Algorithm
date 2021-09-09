#include <cstdio>
#include <algorithm>
using namespace std;
#define INF 2000000001
pair<int, int> cost[500000];
int min_back[500000];
int main() {
	int N, a, b;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		cost[i] = make_pair(b, a);
	}
	sort(cost, cost+N);
	min_back[N - 1] = cost[N-1].second;
	for (int i = N - 2; i >= 0; i--)
		min_back[i] = min(min_back[i+1], cost[i].second);
	long long tot = 0, ans;
	int num1=INF, diff1 = INF, num2=INF, diff2 = INF;
	for (int i = 0; i < N; i++) {
		tot += (long long)cost[i].first;
		if (diff1 > cost[i].second - cost[i].first)
			diff1 = cost[i].second - cost[i].first;
		diff2 = min_back[i] - cost[i].first;
		ans = tot + (long long)min(diff1, diff2);
		printf("%lld\n", ans);
	}
	return 0;
}