#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <tuple>
#include <string>
#include <functional>
#include <queue>
#include <stack>
#include <climits>
#include <iostream>
using namespace std;
#define CINOUT ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF INT_MAX/2-1
typedef long long ll;
map<vector<int>, int> dist;
int main() {
	int N;
	char c;
	scanf("%d", &N);
	vector<int> state;
	for (int i = 0; i < N*2; i++) {
		scanf(" %c", &c);
		state.push_back(c);

	}
	queue<pair<vector<int>, int> >q;
	q.push(make_pair(state, 1));
	while (!q.empty()) {
		vector<int> st = q.front().first;
		int n = q.front().second;
		q.pop();
		if (dist[st] != 0)
			continue;
		dist[st] = n;
		for (int i = 1; i < 2*N; i++) {
			vector<int> nxt;
			nxt.push_back(st[i]);
			for (int j = 0; j < 2*N; j++) {
				if (i != j)
					nxt.push_back(st[j]);
			}
			q.push(make_pair(nxt, n + 1));
		}
	}
	int ans = INF;
	for (auto st = dist.begin(); st != dist.end(); st++) {
		auto s = st->first;
		int point1 = 0;
		int point2 = 0;
		for (int i = 0; i < s.size();i+=2) {
			//printf("%c %c ", s[i], s[i + 1]);
			if (s[i] == s[i + 1])
				continue;
			else if (s[i] == 'O')
				point1++;
			else
				point2++;
		}
		if (point1 > point2)
			ans = min(ans, st->second);
	}
	printf("%d", ans-1);
	return 0;
}