#include <stdio.h>
#include <algorithm>
using namespace std;

int prime[10001];
void find_prime() {
	prime[1] = 1;
	for (int i = 2; i < 5001; i++) {
		if (prime[i] == 0) {
			int j = 2;
			while (i*j<10000)
				prime[i*j] = 1, j++;
		}
	}
}
int main() {
	int t;
	scanf("%d", &t);
	find_prime();
	while (t--) {
		int n, a, b, diff = 987654321, cnt = 0;
		scanf("%d", &n);
		for (int i = n / 2 + 2; i >1; i--) {
			if (prime[i] == 0 && prime[n - i] == 0) {
				if (diff > abs(n - i - i)) {
					a = i;
					b = n - i;
					diff = abs(n - i - i);
					cnt++;
				}
				if (cnt > 3)
					break;
			}
		}
		printf("%d %d\n", min(a, b), max(a, b));
	}
}