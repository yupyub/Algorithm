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
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n,a;
		int one = 0;
		int two = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a);
			if (a == 1)
				one++;
			else
				two++;
		}
		int ans = 0;
		if (two % 2) {
			if (one % 2 == 0 && one > 0)
				ans = 1;
		}
		else {
			if (one % 2 == 0)
				ans = 1;
		}
		if (ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
