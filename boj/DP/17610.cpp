#include <cstdio>
#include <cmath>
int K;
int weight[14];
bool cache[30 * 200000 + 1][14];
void solve(int total, int count) {
	if (count > K)
		return;
	if (cache[total][count])
		return;
	cache[total][count] = true;
	solve(total + weight[count], count + 1);
	solve(total, count + 1);
	solve(abs(total - weight[count]), count + 1);
}
int main() {
	scanf("%d", &K);
	int S = 0;
	for (int i = 0; i < K; i++) {
		scanf("%d", &weight[i]);
		S += weight[i];
	}
	solve(0, 0);
	int ans = 0;
	for (int i = 1; i <= S; i++) {
		int flag = 0;
		for (int j = 0; j <= K; j++)
			if (cache[i][j]) {
				flag = 1;
				break;
			}
		if (!flag) 
			ans++;
	}
	printf("%d", ans);
	return 0;
}