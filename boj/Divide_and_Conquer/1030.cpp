#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

void fractal(int N, int K, int R, int C1, int C2, int c1, int c2) {
	if (c1 > C2 || c2 < C1)
		return;
	if (c1==c2) {
		printf("0");
		return;
	}
	int p = (c2 - c1 + 1) / N;
	int P = (N - K) / 2;
	if (R >= P * p && R < (K + P) * p) {
		for (int i = 0; i < P; i++)
			fractal(N, K, R % p, C1, C2, c1 + p * i, c1 + p * (i + 1) - 1);
		
		for (int i = max(c1 + P * p, C1); i <= min(c1 + (K + P) * p - 1, C2); i++)
			printf("1");

		for (int i = 0; i < P; i++)
			fractal(N, K, R % p, C1, C2, c1 + (P + K) * p + p * i, c1 + (P + K) * p + p * (i + 1) - 1);
	}
	else {
		for (int i = 0; i < P; i++)
			fractal(N, K, R % p, C1, C2, c1 + p * i, c1 + p * (i + 1) - 1);
		
		for (int i = 0; i < K; i++)
			fractal(N, K, R % p, C1, C2, c1 + P * p + p * i, c1 + P * p + p * (i + 1) - 1);
		
		for (int i = 0; i < (N - K) / 2; i++)
			fractal(N, K, R % p, C1, C2, c1 + (P + K) * p + p * i, c1 + (P + K) * p + p * (i + 1) - 1);
	}
}
int main() {
	int S, N, K, R1, R2, C1, C2;
	scanf("%d %d %d %d %d %d %d", &S, &N, &K, &R1, &R2, &C1, &C2);
	for (int r = R1; r <= R2; r++) {
		fractal(N, K, r, C1, C2, 0, pow(N, S) - 1);
		printf("\n");
	}
	return 0;
}