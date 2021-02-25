#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
pair<int,int> arr[200001];
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int a;
		for (int i = 1; i <= n; i++) {
			arr[i].first = 0;
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &a);
			arr[a].first++;
			arr[a].second = i + 1;
		}
		int ans = -1;
		for (int i = 1; i <= n; i++) {
			if (arr[i].first == 1) {
				ans = arr[i].second;
				break;
			}
		}
		printf("%d\n", ans);
	}
}