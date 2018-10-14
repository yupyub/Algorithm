#include <stdio.h>
int main() {
	int arr[501][2];
	int n, m, ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	scanf("%d", &m);
	int a;
	for (int j = 0; j < m; j++) {
		scanf("%d", &a);
		for (int i = 1; i <= n;i++){
			if (i == a)
				arr[i][0] = 0;
			else if (arr[i][0] == a || arr[i][1] == a)
				arr[i][0] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (arr[i][0] != 0 && arr[i][1] != 0)
			ans++;
	}
	printf("%d\n", ans);
}