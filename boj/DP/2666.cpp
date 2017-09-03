#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int cache[21][21][21];
int arr[21];
int m;
int go(int idx, int x, int y) {
	if (idx == m - 1)
		return min(abs(arr[idx] - x), abs(arr[idx] - y));
	if (cache[idx][x][y] != -1)
		return cache[idx][x][y];
	int &res = cache[idx][x][y];
	return res = min(abs(arr[idx] - x) + go(idx + 1, arr[idx], y), abs(arr[idx] - y) + go(idx + 1, x, arr[idx]));
}
int main() {
	int a, b, n;
	scanf("%d %d %d %d", &n, &a, &b, &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &arr[i]);
	memset(cache, -1, sizeof(cache));
	printf("%d\n", go(0, a, b));
}