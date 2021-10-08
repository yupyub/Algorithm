#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int map[1001][1001]; // Safe = 0, Danger = 1, Queen = 2, Knight = 3, Pawn = 4
int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	int num_Q, num_K, num_P;
	vector<pair<int, int> > Queen, King;
	int x, y;
	scanf("%d", &num_Q);
	for (int i = 0; i < num_Q; i++) {
		scanf("%d %d", &x, &y);
		map[x][y] = 2;
	}
	scanf("%d", &num_K);
	for (int i = 0; i < num_K; i++) {
		scanf("%d %d", &x, &y);
		map[x][y] = 3;
	}
	scanf("%d", &num_P);
	for (int i = 0; i < num_P; i++) {
		scanf("%d %d", &x, &y);
		map[x][y] = 4;
	}
	int qx[] = { -1,-1,1,1,0,1,0,-1 };
	int qy[] = { -1,1,-1,1,1,0,-1,0 };
	int kx[] = { -2,-2,-1,-1,1,1,2,2 };
	int ky[] = { -1,1,-2,2,-2,2,-1,1 };
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] == 2) {
				for (int dir = 0; dir < 8; dir++) {
					int d = 1;
					while (1) {
						int nx = i + qx[dir] * d;
						int ny = j + qy[dir] * d;
						if (nx<1 || ny<1 || nx>N || ny>M)
							break;
						if (map[nx][ny] >= 2)
							break;
						map[nx][ny] = 1;
						d++;
					}
				}
			}
			else if (map[i][j] == 3) {
				for (int dir = 0; dir < 8; dir++) {
					int nx = i + kx[dir];
					int ny = j + ky[dir];
					if (nx<1 || ny<1 || nx>N || ny>M)
						continue;
					if (map[nx][ny] >= 1)
						continue;
					map[nx][ny] = 1;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (map[i][j] == 0)
				ans++;
	printf("%d", ans);
	return 0;
}