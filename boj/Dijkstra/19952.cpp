#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <queue>
#include <tuple>
#include <functional>
using namespace std;
int map[100][100];
int dist[100][100];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int N, M;
int O, F, sx, sy, ex, ey;
int dijk() {
	priority_queue<tuple<int, int, int> >pq;
	pq.push(make_tuple(F, sx, sy));
	while (!pq.empty()) {
		int f = get<0>(pq.top());
		int x = get<1>(pq.top());
		int y = get<2>(pq.top());
		pq.pop();
		//printf("%d %d %d\n", x, y, f);
		if (x == ex && y == ey)
			return f;
		if (f == 0)
			continue;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (map[nx][ny] - map[x][y] > f)
				continue;
			if (dist[nx][ny] < f - 1) {
				dist[nx][ny] = f - 1;
				pq.push(make_tuple(f - 1, nx, ny));
			}
		}
	}
	return -1;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				map[i][j] = 0;
		scanf("%d %d %d %d %d %d", &O, &F, &sx, &sy, &ex, &ey);
		sx -= 1;
		sy -= 1;
		ex -= 1;
		ey -= 1;
		for (int i = 0; i < O; i++) {
			int x, y, h;
			scanf("%d %d %d", &x, &y, &h);
			map[x-1][y-1] = h;
		}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				dist[i][j] = -1;
		int d = dijk();
		if (d == -1)
			printf("인성 문제있어??\n");
		else
			printf("잘했어!!\n");
	}
}