#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
	int N, M;
	int arr[10][10];
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			scanf("%1d", &arr[i][j]);
	int maxi = -1;
	int dx[] = { 1,-1,1,-1 };
	int dy[] = { -1,1,1,-1 };
	for (int ii = 0; ii <= N; ii++) {
		for (int jj = 0; jj <= M; jj++) {
			if (ii == 0 && jj == 0)
				continue;
			for (int si = 0; si < N; si++) {
				for (int sj = 0; sj < M; sj++) {
					for (int k = 0; k < 4; k++) {
						int i = si;
						int j = sj;
						int num = 0;
						while (i < N && j < M && i>=0 && j>=0) {
							num *= 10;
							num += arr[i][j];
							i += dx[k]*ii;
							j += dy[k]*jj;
							double sq = sqrt(num);
							if (num == ((int)sq) * ((int)sq))
								maxi = max(maxi, num);
						}
					}
				}
			}
		}
	}
	printf("%d\n", maxi);
	return 0;
}