#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq2;
int ch[100000];
queue<int>q;
int main() {
	int n,a,b,d,ans = 0,num = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		pq.push(make_pair(a, i));
		pq.push(make_pair(b, i));
	}
	scanf("%d", &d);
	ch[pq.top().second] = 1;
	pq2.push(pq.top());
	pq.pop();
	while (!pq.empty()) {
		pair<int,int> tmp = pq.top();
		pq.pop();
		pq2.push(tmp);
		while (tmp.first - pq2.top().first>d) {
			if (ch[pq2.top().second] == 2)
				num--;
			ch[pq2.top().second] = 0;
			pq2.pop();
		}
		if (ch[tmp.second] == 0) {
			ch[tmp.second] = 1;
		}
		else if (ch[tmp.second] == 1) {
			ch[tmp.second] = 2;
			num++;
			ans = max(ans, num);
		}
	}
	printf("%d\n", ans);
}