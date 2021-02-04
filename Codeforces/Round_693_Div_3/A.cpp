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
		int w, h, n;
		scanf("%d %d %d", &w, &h, &n);
		int tot = 1;
		int ans = 0;
		while (1) {
			if (tot >= n) {
				ans = 1;
				break;
			}
			if (w % 2 == 0) {
				tot *= 2;
				w /= 2;
			}
			else if (h % 2 == 0) {
				tot *= 2;
				h /= 2;
			}
			else
				break;
		}
		if (ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
