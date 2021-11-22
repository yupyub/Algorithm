#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int parent[51];
int party[50][50];
int Find(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = Find(parent[x]);
}
void Union(int x, int y) {
	parent[Find(x)] = Find(y);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	int tperson_n, person_n, person;
	cin >> tperson_n;
	for (int i = 1; i <= N; i++)
		parent[i] = i;
	for (int i = 0; i < tperson_n; i++) {
		cin >> person;
		Union(person, 0);
	}
	for (int i = 0; i < M; i++) {
		cin >> person_n;
		cin >> party[i][0];
		for (int j = 1; j < person_n; j++) {
			cin >> party[i][j];
			if(Find(party[i][j]) != Find(party[i][0]))
				Union(party[i][j], party[i][0]);
		}
	}
	int ans = 0;
	for (int i = 0; i < M; i++) {
		if (Find(party[i][0]) != Find(0)) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}