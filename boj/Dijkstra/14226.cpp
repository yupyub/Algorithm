#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <cstring>
#include <string>
#include <functional>
#include <tuple>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
int arr[2001];
int INF = 987654321;
int main() {
	int S;
	scanf("%d", &S);
	for (int i = 0; i < 2001; i++)
		arr[i] = INF;
	priority_queue<pair<int, int>,vector<pair<int, int> >, greater<pair<int, int> > > pq;
	arr[1] = 0;
	pq.push(make_pair(0, 1));
	int ans = 0;
	while (!pq.empty()) {
		int dist = pq.top().first;
		int num = pq.top().second;
		//printf("%d %d\n", num, dist);
		pq.pop();
		if (num == S) {
			ans = dist;
			break;
		}
		if (num - 1 > 0 && arr[num - 1] > dist + 1) {
			arr[num - 1] = dist + 1;
			pq.push(make_pair(dist + 1, num - 1));
		}
		int cnt = 2;
		while (1) {
			if (num * cnt > 2000)
				break;
			if (arr[num * cnt] > dist + cnt) {
				arr[num * cnt] = dist + cnt;
				pq.push(make_pair(dist + cnt, num * cnt));
			}
			cnt++;
		}
	}
	printf("%d\n", ans);
}