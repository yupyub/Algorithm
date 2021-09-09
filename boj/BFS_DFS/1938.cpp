#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int dirx[2][3] = { {0, 0, 0}, { -1, 0, 1 } };
int diry[2][3] = { { -1, 0, 1 },{ 0, 0, 0 } };
int there_exist(char map[][51], int N, int x, int y, int dir, char C) {
	int count = 0;
	for (int i = 0; i < 3; i++) {
		int nx = x + dirx[dir][i];
		int ny = y + diry[dir][i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N)
			return -1;
		if (map[nx][ny] == C)
			count++;
	}
	return count;
}
int dfs(char map[][51], int N, int sx, int sy, int sdir, int ex, int ey, int edir) {
	int visit[50][51][2] = { 0, };
	queue<tuple<int, int, int, int> > q; // x, y, dir, dist
	q.push(make_tuple(sx, sy, sdir, 0));
	visit[sx][sy][sdir] = 1;
	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int dir = get<2>(q.front());
		int dist = get<3>(q.front());
		q.pop();
		if (x == ex && y == ey && dir == edir)
			return dist;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (there_exist(map, N, nx, ny, dir, '0') == 3){
				if (visit[nx][ny][dir] == 0) {
					visit[nx][ny][dir] = 1;
					q.push(make_tuple(nx, ny, dir, dist + 1));
				}
			}
		}
		if (there_exist(map, N, x-1, y, 0, '0') == 3 && there_exist(map, N, x, y, 0, '0') == 3 && there_exist(map, N, x+1, y, 0, '0') == 3) {
			if (visit[x][y][(dir + 1) % 2] == 0) {
				visit[x][y][(dir + 1) % 2] = 1;
				q.push(make_tuple(x, y, (dir + 1) % 2, dist + 1));
			}
		}
	}
	return 0;
}


int main() {
	int N;
	scanf("%d", &N);
	char map[50][51];
	for (int i = 0; i < N; i++)
		scanf("%s", map[i]);
	int sx, sy, sdir;
	int ex, ey, edir;
	for(int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (there_exist(map, N, i, j, 0, 'B') == 3)
				sx = i, sy = j, sdir = 0;
			else if(there_exist(map, N, i, j, 1, 'B') == 3)
				sx = i, sy = j, sdir = 1;
			else if (there_exist(map, N, i, j, 0, 'E') == 3)
				ex = i, ey = j, edir = 0;
			else if (there_exist(map, N, i, j, 1, 'E') == 3)
				ex = i, ey = j, edir = 1;
		}
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (map[i][j] == 'B' || map[i][j] == 'E')
				map[i][j] = '0';
	printf("%d\n", dfs(map, N, sx, sy, sdir, ex, ey, edir));
	return 0;
}