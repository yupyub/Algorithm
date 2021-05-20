#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include <cstring>
using namespace std;

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	char arr[50][51];
	for (int i = 0; i < N; i++)
		scanf("%s", arr[i]);
	int K;
	scanf("%d", &K);
	map<string, int> m;
	for (int i = 0; i < N; i++) {
		string str(arr[i]);
		m[str]++;
	}
	int ans = 0;
	for (auto tmp: m) {
		string line = tmp.first;
		int num = tmp.second;
		int cnt = 0;
		for (char c : line) {
			if (c == '0')
				cnt++;
		}
		if (cnt > K)
			continue;
		if ((K - cnt) % 2 == 0)
			ans = max(ans, num);
	}
	printf("%d\n", ans);
}