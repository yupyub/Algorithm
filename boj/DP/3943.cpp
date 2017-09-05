#include <stdio.h>
#include <algorithm>
using namespace std;
int hail[100001];
int f(int n) {
	//printf("%d ", n);
	if (n == 1)
		return 1;
	if (n > 100000) {
		int maxi = n;
		while (n != 1) {
			if (n % 2) {
				n *= 3;
				n++;
				maxi = max(maxi, n);
			}
			else
				n /= 2;
		}
		return maxi;
	}
	if (hail[n] != 0)
		return hail[n];
	if (n % 2)
		return hail[n] = max(n * 3 + 1, f(n * 3 + 1));
	else
		return hail[n] = max(n, f(n / 2));
}
int main() {
	int n, a;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		printf("%d\n", f(a));
	}
}