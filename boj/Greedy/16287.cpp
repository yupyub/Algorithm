#include <cstdio>
#include <algorithm>
using namespace std;
int paired[4000001];
int main() {
	int W, N;
	scanf("%d %d", &W, &N);
	int num[50000];
	for (int i = 0; i < N; i++) 
		scanf("%d", &num[i]);
	for (int i = 0; i < 4000001; i++)
		paired[i] = 50001;
	for (int i = 0; i < N; i++)
		for (int j = i+1; j < N; j++)
			paired[num[i] + num[j]] = min(paired[num[i] + num[j]], j);
	int ans = 0;
	for (int i = 3; i < N; i++) {
		for (int j = 2; j < i; j++) {
			if (W - (num[i] + num[j]) < 2)
				continue;
			if (paired[W - (num[i] + num[j])] < j) {
				ans++;
				break;
			}
		}
		if (ans)
			break;
	}
	if (ans)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}