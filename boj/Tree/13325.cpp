#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[2097152];
int n, nn = 1;
int ans = 0;
int dfs(int s) {
	if (nn / 2 <= s)
		return arr[s];
	int a = dfs(s * 2);
	int b = dfs(s * 2 + 1);
	int diff = abs(a - b);
	//printf("%d %d %d\n",s, a,b);
	ans += arr[s * 2] + arr[s * 2 + 1] + diff;
	return min(a, b) + diff + arr[s];
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n + 1; i++)
		nn *= 2;
	for (int i = 2; i < nn; i++)
		scanf("%d", &arr[i]);
	int sum = dfs(1);
	printf("%d\n", ans);
}