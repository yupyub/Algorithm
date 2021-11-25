#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	int accum[201][201] = { 0, };
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &accum[i][j]);
			accum[i][j] += accum[i - 1][j] + accum[i][j - 1] - accum[i - 1][j - 1];
		}
	}
	int ans = -400000001;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			for (int ii = 1; ii <= i; ii++)
				for (int jj = 1; jj <= j; jj++)
					ans = max(ans, accum[i][j] - accum[i][jj - 1] - accum[ii - 1][j] + accum[ii - 1][jj - 1]);
	printf("%d\n", ans);
	return 0;
}