#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
const int INF = 2147483647;
int ch[10001];
int arr[10001];
vector<int>v[10001];
int ans = INF, pos = 0;
pair<int,int> dfs(int n) {
	int nn;
	priority_queue<pair<int, int>,vector<pair<int,int> >, greater<pair<int,int> > >pq;
	pair<int, int>tmp, tmp2;

	//printf(">> %d %d %d\n", n, ans, pos);
	for (int i = 0; i < v[n].size(); i++) {
		nn = v[n][i];
		if (ch[nn])
			continue;
		ch[nn] = 1;
		pq.push(dfs(nn));
		ch[nn] = 0;
	}
	//printf(">> %d %d %d %d\n", n, ans, pos,pq.size());
	if (pq.size() == 0) {
		return make_pair(arr[n], n);
	}
	else if (pq.size() == 1) {
		tmp = pq.top();
		if (ans > tmp.first + arr[n]) {
			ans = tmp.first + arr[n];
			pos = min(tmp.second, n);
		}
		else if (ans == tmp.first + arr[n]) {
			pos = min(pos,min(tmp.second, n));
		}
		if (tmp.first == 0)
			return make_pair(arr[n], min(n, tmp.second));
		else
			return make_pair(tmp.first + arr[n], tmp.second);
	}
	else {
		tmp = pq.top();
		pq.pop();
		tmp2 = pq.top();
		//printf("%d %d %d %d\n", tmp.first, tmp.second, tmp.first, tmp2.first, tmp2.second);
		if (ans > tmp.first + arr[n]) {
			ans = tmp.first + arr[n];
			pos = min(tmp.second, n);
		}
		else if (ans == tmp.first + arr[n]) {
			pos = min(pos, min(tmp.second, n));
		}
		if (ans > tmp.first + tmp2.first + arr[n]) {
			ans = tmp.first + tmp2.first + arr[n];
			pos = min(tmp.second, tmp2.second);
		}
		else if (ans == tmp.first + tmp2.first + arr[n]) {
			pos = min(pos, min(tmp.second, tmp2.second));
		}
		if (tmp.first == 0)
			return make_pair(arr[n], min(n, tmp.second));
		else
			return make_pair(tmp.first + arr[n], tmp.second);
	}
}
int main() {
	int n,a,b;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		arr[i] = -a;
	}
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	ch[1] = 1;
	pair<int,int> tmp = dfs(1);
	if (ans > tmp.first) {
		ans = tmp.first;
		pos = 1;
	}
	else if (ans == tmp.first + arr[n]) 
		pos = 1;
	printf("%d %d\n", -ans, pos);
}