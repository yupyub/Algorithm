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
int n;
int ans = 997654321;
void dfs(int x,int num, int i) {
	if (x > n)
		return;
	else if (x == n) {
		ans = min(ans, num);
		return;
	}
	if (i == 10)
		return;
	dfs(x, num, i + 1);
	dfs(x+i, num*10+i, i + 1);
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		ans = 997654321;
		scanf("%d", &n);
		dfs(0,0,1);
		if (ans == 997654321)
			printf("-1\n");
		else
			printf("%d\n", ans);
	}
}