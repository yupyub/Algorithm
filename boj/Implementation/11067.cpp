#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
pair<int, int> ans[100001];
pair<int, int> arr[100001];
vector<pair<int, int> > v;
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, a, b, m;
		scanf("%d", &n);
		for (int k = 0; k < n; k++) {
			scanf("%d %d", &a, &b);
			arr[k] = make_pair(a, b);
		}
		sort(arr, arr + n);
		int x = -1, y = 0, i = 0, j = 0;
		v.clear();
		while (i<n) {
			if (arr[i].first != x) {
				if (!v.empty()) {
					if (y == v[0].second) {
						for (int k = 0; k < v.size(); k++) {
							ans[j++] = v[k];
						}
						y = v[v.size() - 1].second;
					}
					else {
						for (int k = v.size() - 1; k >= 0; k--) {
							ans[j++] = v[k];
						}
						y = v[0].second;
					}
					v.clear();
				}
				v.push_back(arr[i]);
				x = arr[i].first;
			}
			else {
				v.push_back(arr[i]);
			}
			i++;
		}
		if (!v.empty()) {
			if (y == v[0].second) {
				for (int k = 0; k < v.size(); k++) {
					ans[j++] = v[k];
				}
			}
			else {
				for (int k = v.size() - 1; k >= 0; k--) {
					ans[j++] = v[k];
				}
			}
			v.clear();
		}
		scanf("%d", &m);
		for (int k = 0; k < m; k++) {
			scanf("%d", &a);
			printf("%d %d\n", ans[a - 1].first, ans[a - 1].second);
		}
	}
}