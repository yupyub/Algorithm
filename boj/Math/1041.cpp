#include <cstdio>
#include <algorithm>
using namespace std;
#define INF 987654321
int main() {
	int N;
	scanf("%d", &N);
	int num[6];
	int unmatched[6] = { 5,4,3,2,1,0 };
	for (int i = 0; i < 6; i++) 
		scanf("%d", &num[i]);
	int minpart[3] = { INF,INF,INF }; // 1¸é, 2¸é, 3¸é
	int maxipart = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = i+1; j < 6; j++) {
			if (unmatched[i] == j)
				continue;
			for (int k = j + 1; k < 6; k++) {
				if (unmatched[i] == k || unmatched[j] == k)
					continue;
				minpart[2] = min(minpart[2], num[i] + num[j] + num[k]);
			}
			minpart[1] = min(minpart[1], num[i] + num[j]);
		}
		minpart[0] = min(minpart[0], num[i]);
		maxipart = max(maxipart, num[i]);
	}
	if (N == 1)
		printf("%d", num[0] + num[1] + num[2] + num[3] + num[4] + num[5] - maxipart);
	else if (N == 2)
		printf("%d", minpart[2] * 4 + minpart[1] * 4);
	else
		printf("%lld", minpart[2] * 4 + minpart[1] * ((N - 2) * 8 + 4) + minpart[0] * (long long)(N - 2) * (long long)(N - 2) * 5 + minpart[0] * (N - 2) * 4);
}