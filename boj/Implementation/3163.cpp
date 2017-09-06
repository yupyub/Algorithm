#include <stdio.h>
#include <algorithm>
using namespace std;
pair<int, int>arr[100000];
int arr1[100000];
int arr2[100000];
int ans[100000];
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, l, k,a,p,c = 0,d = 0;
		scanf("%d %d %d", &n, &l, &k);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &p, &a);
			if (a > 0) {
				ans[i] = a;
				arr2[d++] = abs(l - p);
			}
			else {
				ans[i] = a;
				arr1[c++] = p;
			}
		}
		for (int i = 0; i < c; i++) {
			arr[i] = make_pair(arr1[i], ans[i]);
		}
		for (int j = c; j < c + d; j++) {
			arr[j] = make_pair(arr2[j - c], ans[j]);
		}
		sort(arr, arr + n);
		printf("%d\n", arr[k-1].second);
	}
}