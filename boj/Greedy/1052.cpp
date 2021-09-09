#include <cstdio>
int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i <= N; i++) {
		int tmp = N+i;
		int cnt = 0;
		while (tmp > 0) {
			cnt += tmp % 2;
			tmp /= 2;
		}
		if (cnt <= K) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}