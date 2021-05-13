#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <cstring>
#include <string>
#include <functional>
#include <tuple>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
ll INF = 987654321987654321;
ll dist[500][500];
int arr[500][500];
int ans[500];
int N, M;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
void dijk() {
	priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int> >, greater< tuple<int, int, int, int> > >pq;
	for (int i = 0; i < N; i++) {
		pq.push(make_tuple(arr[i][M - 1], i, M - 1, i));
		dist[i][M - 1] = arr[i][M - 1];
	}
	while (!pq.empty()) {
		int d = get<0>(pq.top());
		int x = get<1>(pq.top());
		int y = get<2>(pq.top());
		int id = get<3>(pq.top());
		pq.pop();
		if (y == 0 && d == dist[x][y])
			ans[id]++;
		if (d > dist[x][y])
			continue;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue;
			if (dist[nx][ny] > d + arr[nx][ny]) {
				dist[nx][ny] = d + arr[nx][ny];
				pq.push(make_tuple(dist[nx][ny], nx, ny, id));
			}
		}
	}
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
			dist[i][j] = INF;
		}
	}
	dijk();
	for (int i = 0; i < N; i++)
		printf("%d\n", ans[i]);
}