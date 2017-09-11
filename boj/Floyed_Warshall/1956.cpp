#include<stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int V, E;
int g[401][401];
int INF = 987654321;
void floyed() {
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			for (int k = 1; k <= V; k++) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
}
int main() {
	scanf("%d %d", &V, &E);
	int a, b, c;
	for (int i = 1; i <= V; i++)
		for (int j = 1; j <= V; j++)
			g[i][j] = INF;
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (g[a][b] > c)
			g[a][b] = c;
	}
	floyed();
	int ans = INF;
	for (int i = 1; i <= V; i++)
		ans = min(g[i][i], ans);
	if (ans == INF)
		printf("-1\n");
	else
		printf("%d\n", ans);
}