#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int d,n,a;
		scanf("%d%d",&d, &n);
		int maxi = 0, mini = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a);
			maxi = max(maxi, max(a, d - a));
			mini = max(mini, min(a, d - a));
		}
		printf("%d %d\n", mini, maxi);
	}
}