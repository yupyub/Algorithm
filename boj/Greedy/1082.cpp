#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	int cost[10];
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> cost[i];
	cin >> M;
	int min_cost = 100;
	int num;
	int have[10] = { 0, };
	for (int i = N - 1; i >= 0; i--) {
		if (cost[i] < min_cost) {
			min_cost = cost[i];
			num = i;
		}
	}
	have[num] = M / min_cost;
	M %= min_cost;
	if (num == 0) {
		int flag = 1;
		while (flag && have[num]) {
			M += min_cost;
			have[num]--;
			for (int i = N - 1; i > 0; i--) {
				if (cost[i] <= M) {
					have[i]++;
					M -= cost[i];
					flag = 0;
					break;
				}
			}
		}
	}
	int flag = 0;
	for (int i = 1; i < N; i++) {
		if (have[i]) {
			flag = 1;
			break;
		}
	}
	if (!flag) {
		cout << 0;
		return 0;
	}
	while (flag && have[num]) {
		flag = 0;
		for (int i = N - 1; i > num; i--) {
			if (cost[i] <= M + cost[num]) {
				flag = 1;
				have[num]--;
				have[i]++;
				M += cost[num];
				M -= cost[i];
				break;
			}
		}
	}
	for (int i = N - 1; i >= 0; i--) {
		while (have[i]) {
			cout << i;
			have[i]--;
		}
	}
	return 0;
}