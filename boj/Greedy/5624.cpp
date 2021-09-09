#include <cstdio>
#include <algorithm>
using namespace std;
int paired[400002];
int main() {
	int N;
	scanf("%d", &N);
	int num[5000];
	for (int i = 0; i < N; i++) 
		scanf("%d", &num[i]);
	for (int i = 0; i < 400002; i++) 
		paired[i] = 5001;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			paired[num[i] + num[j] + 200000] = min(paired[num[i] + num[j] + 200000], max(i,j));
	int ans = 0;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (paired[num[i] - num[j] + 200000] <= j) {
				ans++;
				break;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}