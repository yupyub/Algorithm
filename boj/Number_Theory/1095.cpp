#include <stdio.h>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
int arr[100001];
int cnt[100001];
long long maxi = 0;
long long xx = 0;
void factorization(int n) {
	int sq = (int)sqrt(n);
	maxi = sq;
	for (int i = 2; i <= sq; i++) {
		while (n%i == 0) {
			arr[i]++;
			n /= i;
		}
	}
	if (n > 1) {
		arr[n]++;
		xx = n;
	}
}
int main() {
	long long s, f, m;
	scanf("%lld %lld %lld", &s, &f, &m);
	int cch = 0;
	long long i;
	while (1) {
		xx = 0;
		factorization((int)m);
		i = xx;
		int ch = 0;
		if (xx != 0) {
			long long j = xx;
			while ((s + f) / (j) != 0) {
				cnt[i] -= (s + f) / (j);
				j *= i;
			}
			j = i;
			while ((s) / (j) != 0) {
				cnt[i] += (s) / (j);
				j *= i;
			}
			j = i;
			while ((f) / (j) != 0) {
				cnt[i] += (f) / (j);
				j *= i;
			}
			if (arr[xx] + cnt[xx] > 0) {
				ch = 1;
			}
		}
		if (ch == 0) {
			for (i = 2; i <= maxi; i++) {
				if (arr[i] == 0)
					continue;
				long long j = i;
				while ((s + f) / (j) != 0) {
					cnt[i] -= (s + f) / (j);
					j *= i;
				}
				j = i;
				while ((s) / (j) != 0) {
					cnt[i] += (s) / (j);
					j *= i;
				}
				j = i;
				while ((f) / (j) != 0) {
					cnt[i] += (f) / (j);
					j *= i;
				}
			}
			for (int i = 2; i <= maxi; i++) {
				if (arr[i] + cnt[i] > 0) {
					ch = 1;
					break;
				}
			}
		}
		if (ch == 0) {
			cch = 1;
			printf("%lld\n", m);
			break;
		}
		for (int i = 2; i <= maxi; i++) {
			arr[i] = 0;
			cnt[i] = 0;
		}
		m--;
	}
}