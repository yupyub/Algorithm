#include <stdio.h>
int parent[1000001];
int find(int a) {
	if (parent[a] == a)
		return a;
	return parent[a] = find(parent[a]);
}
void uni(int a, int b) {
	parent[find(a)] = find(b);
}

int main() {
	int n, m, a, b, c;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		parent[i] = i;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (a) {
			if (find(b) == find(c))
				printf("YES\n");
			else
				printf("NO\n");
		}
		else {
			if (find(b) != find(c))
				uni(b, c);
		}
	}
}