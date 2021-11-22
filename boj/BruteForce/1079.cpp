#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int guilty[16];
int R[16][16];
int dead[16];
int night(int N, int person, int mafia, int turn);
int day(int N, int person, int mafia, int turn);
int night(int N, int person, int mafia, int turn) {
	if (person == 2)
		return turn;
	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (dead[i] || i == mafia)
			continue;
		dead[i] = 1;
		for (int j = 0; j < N; j++)
			guilty[j] += R[i][j];
		ret = max(ret, day(N, person - 1, mafia, turn));
		dead[i] = 0;
		for (int j = 0; j < N; j++)
			guilty[j] -= R[i][j];
	}
	return ret;
}
int day(int N, int person, int mafia, int turn) {
	if (person == 1)
		return turn;
	int max_guilty = -987654321;
	int who = 0;
	for (int i = 0; i < N; i++) {
		if (dead[i])
			continue;
		if (guilty[i] > max_guilty) {
			max_guilty = guilty[i];
			who = i;
		}
	}
	if (who == mafia)
		return turn;
	dead[who] = 1;
	int ret = night(N, person - 1, mafia, turn+1);
	dead[who] = 0;
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> guilty[i];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> R[i][j];
	int mafia;
	cin >> mafia;
	if (N % 2)
		cout << day(N, N, mafia, 0);
	else
		cout << night(N, N, mafia, 1);
	return 0;
}