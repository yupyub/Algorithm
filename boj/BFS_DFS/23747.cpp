#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <tuple>
#include <string>
#include <functional>
#include <queue>
#include <stack>
#include <climits>
#include <iostream>
using namespace std;
#define CINOUT ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF INT_MAX/2-1
typedef long long ll;
char arr[1000][1000];
int check[1000][1000];
int visit[1000010];
int cnt = 1;
int R, C;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
void mapping(int x, int y, char c) {
	if (arr[x][y] != c)
		return;
	if (check[x][y] != 0)
		return;
	check[x][y] = cnt;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= R || ny >= C || nx < 0 || ny < 0)
			continue;
		mapping(nx, ny, c);
	}
}
int main() {
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) {
		scanf("%s", arr[i]);
	}
	int x, y;
	scanf("%d %d", &x, &y);
	x--;
	y--;
	char moving[200001];
	scanf("%s", moving);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			mapping(i, j, arr[i][j]);
			cnt++;
		}
	}
	int len = strlen(moving);
	
	for (int i = 0; i < len; i++) {
		if (moving[i] == 'W') {
			visit[check[x][y]] = 1;
			continue;
		}
		int dir = 0;
		if (moving[i] == 'U')
			dir = 2;
		else if (moving[i] == 'D')
			dir = 3;
		else if (moving[i] == 'L')
			dir = 1;
		x = x + dx[dir];
		y = y + dy[dir];
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			int near = 0;
			if (i == x && j == y)
				near = 1;
			for (int k = 0; k < 4; k++) {
				int ii = i + dx[k];
				int jj = j + dy[k];
				if (ii >= R || jj >= C || ii < 0 || jj < 0)
					continue;
				if (ii == x && jj == y)
					near = 1;
			}
			if (!visit[check[i][j]] && !near)
				printf("#");
			else
				printf(".");
		}
		printf("\n");
	}
	return 0;
}