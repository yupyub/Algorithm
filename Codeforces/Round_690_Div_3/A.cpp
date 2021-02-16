#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int arr[300];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) 
			scanf("%d", &arr[i]);
		int s = 0;
		int e = n - 1;
		int flag = 0;
		while (s <= e) {
			if (flag) {
				printf("%d ", arr[e--]);
				flag = 0;
			}
			else {
				printf("%d ", arr[s++]);
				flag = 1;
			}
		}
		printf("\n");
	}
}