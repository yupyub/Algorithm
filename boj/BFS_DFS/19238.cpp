#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
#define INF 987654321
int N, M, F;
int arr[20][20];
int dist[20][20][20][20];
int dx[] = { 0,1,-1,0 };
int dy[] = { 1,0,0,-1 };
void bfs(int sx, int sy) {
	queue<tuple<int, int, int> >q;
	dist[sx][sy][sx][sy] = 0;
	q.push(make_tuple(sx, sy, 0));
	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int d = get<2>(q.front());
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= N || ny >= N || nx < 0 || ny < 0)
				continue;
			if (arr[nx][ny])
				continue;
			if (dist[sx][sy][nx][ny] > d + 1) {
				dist[sx][sy][nx][ny] = d + 1;
				q.push(make_tuple(nx, ny, d + 1));
			}
		}
	}
}
int main() {
	scanf("%d %d %d", &N, &M, &F);
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			scanf("%d", &arr[i][j]);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				for (int r = 0; r < N; r++)
					dist[i][j][k][r] = INF;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if(arr[i][j] == 0)
				bfs(i, j);

	int sx, sy;
	scanf("%d %d", &sx, &sy);
	sx--;
	sy--;
	vector<tuple<int, int, int, int,int> > quary;
	for (int i = 0; i < M; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		quary.push_back(make_tuple(a-1, b-1, c-1, d-1, 0));
	}
	sort(quary.begin(), quary.end());
	for (int i = 0; i < M; i++) {
		int idx = -1;
		int mind = INF;
		for (int j = 0; j < M;j++) {
			int nx = get<0>(quary[j]);
			int ny = get<1>(quary[j]);
			int visited = get<4>(quary[j]);
			if (visited)
				continue;
			if (mind > dist[sx][sy][nx][ny]) {
				mind = dist[sx][sy][nx][ny];
				idx = j;
			}
		}
		if (idx == -1) {
			F = -1;
			break;
		}
		int nx = get<0>(quary[idx]);
		int ny = get<1>(quary[idx]);
		int dx = get<2>(quary[idx]);
		int dy = get<3>(quary[idx]);
		F -= mind;
		if (dist[nx][ny][dx][dy] > F) {
			F = -1;
			break;
		}
		F += dist[nx][ny][dx][dy];
		quary[idx] = make_tuple(nx, ny, dx, dy, 1);
		sx = dx;
		sy = dy;
	}
	printf("%d\n", F);
}