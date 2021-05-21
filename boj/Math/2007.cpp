#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
map<int, int> m;
void map_init(int* B,int M) {
	m.clear();
	for (int i = 0; i < M; i++) {
		if (m[B[i]] == 0)
			m[B[i]] = 1;
		else
			m[B[i]]++;
	}
}
int map_erase(int x) {
	if (m[x] == 0)
		return 0;
	m[x]--;
	if (m[x] == 0)
		m.erase(m.find(x));
	return 1;
}
int main() {
	int N;
	scanf("%d", &N);
	int M = N * (N - 1) / 2;
	int B[5000];
	for (int i = 0; i < M; i++)
		scanf("%d", &B[i]);
	sort(B, B + M);
	if (N == 2) {
		if(B[0]<0)
			printf("%d %d\n", B[0], 0);
		else
			printf("%d %d\n", 0, B[0]);
		return 0;
	}
	int A[100];
	int ans = 0;
	for (int i = 2; i < N; i++) {
		A[0] = -(B[i] - B[1] - B[0])/2;
		map_init(B,M);
		int flag = 1;
		int idx = 1;
		while (idx < N) {
			A[idx] = m.begin()->first-A[0];
			for (int j = 0; j < idx; j++) {
				if (!map_erase(A[j] + A[idx])) {
					flag = 0;
					break;
				}
			}
			if (!flag)
				break;
			idx++;
		}
		if (flag) {
			ans = 1;
			break;
		}
	}
	if (ans) {
		for (int i = 0; i < N; i++)
			printf("%d ", A[i]);
		printf("\n");
	}
	else
		printf("Impossible\n");
	return 0;
}