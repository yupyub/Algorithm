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
	int n;
	ll a;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a);
		ll num = 1;
		int flag = 0;
		while (num <= a) {
			if (a == num) {
				flag = 1;
				break;
			}
			num *= 2;
		}
		if (flag)
			printf("NO\n");
		else
			printf("YES\n");
	}
}