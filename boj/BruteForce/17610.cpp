#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
int leftw[1 << 14];
int rightw[1 << 14];
bool checked[13 * 200000+1];
int main() {
	int K, S = 0;
	int weight[13];
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d", &weight[i]);
		S += weight[i];
	}
	for (int bit = 0; bit < (1 << K); bit++) {
		for (int i = 0; i < K; i++) {
			if ((1 << i) & bit) {
				leftw[bit] += weight[i];
				rightw[bit] += weight[i];
			}
		}
	}
	for (int bit1 = 0; bit1 < (1<<K); bit1++) {
		for (int bit2 = 0; bit2 < (1<<K); bit2++) {
			checked[abs(leftw[bit1] - rightw[bit2])] = true;
		}
	}
	int ans = 0;
	for (int i = 1; i <= S; i++) {
		if (checked[i] == false)
			ans++;
	}
	printf("%d", ans);
	return 0;
}