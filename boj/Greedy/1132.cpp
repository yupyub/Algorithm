#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
void dfs(long long num[], int first_num[], int used[], int idx, long long sum, long long& ans) {
	if (idx == 10) {
		ans = max(ans, sum);
		return;
	}
	if (first_num[idx] == 0 && used[0] == 0) {
		used[0] = 1;
		dfs(num, first_num, used, idx + 1, sum, ans);
		used[0] = 0;
	}
	for (int i = 1; i < 10; i++) {
		if (used[i] == 0) {
			used[i] = 1;
			dfs(num, first_num, used, idx + 1, sum + num[idx] * i, ans);
			used[i] = 0;
		}
	}
}
int main() {
	int N;
	scanf("%d", &N);
	long long num[10] = { 0, };
	int first_num[10] = { 0, };
	char str[13];
	for (int i = 0; i < N; i++) {
		scanf("%s", str);
		long long digit = 1;
		for (int i = strlen(str) - 1; i >= 0; i--) {
			num[str[i] - 'A'] += digit;
			digit *= 10;
			if (i == 0)
				first_num[str[i] - 'A'] = 1;
		}
	}
	long long ans = 0;
	int used[10] = { 0, };
	dfs(num, first_num, used, 0, 0, ans);
	printf("%lld\n", ans);
	return 0;
}