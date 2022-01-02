#include <cstdio>
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		long long x, y;
		scanf("%lld %lld", &x, &y);
		long long dist = 0;
		long long ans = 0;
		for (long long day = 0; day < (1 << 17); day++) {
			dist = (day / 2) * (day / 2 + 1);
			if (day % 2) // odd
				dist += day / 2 + 1;
			if (dist >= y - x) {
				ans = day;
				break;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}