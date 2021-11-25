#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> prev_work[10000];
int work_time[10000];
int cache[10000];
int working(int n) {
	int& ret = cache[n];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int nxt : prev_work[n]) {
		ret = max(ret, working(nxt));
	}
	ret += work_time[n];
	return ret;
}
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int m, p;
		scanf("%d %d", &work_time[i], &m);
		for (int j = 0; j < m; j++) {
			scanf("%d", &p);
			prev_work[i].push_back(p-1);
		}
	}
	memset(cache, -1, sizeof(cache));
	for (int i = N - 1; i >= 0; i--)
		working(i);
	int ans = 0;
	for (int i = 0; i < N; i++)
		ans = max(ans, cache[i]);
	printf("%d", ans);
	return 0;
}