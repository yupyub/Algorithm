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
		vector<int> num;
		int n,a;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a);
			num.push_back(a);
		}
		sort(num.begin(), num.end());
		int flag = 0; // Alice
		ll Alice = 0;
		ll Bob = 0;
		while (!num.empty()) {
			if (flag) {
				int nn = num.back();
				num.pop_back();
				if (nn % 2)
					Bob += nn;
				flag = 0;
			}
			else {
				int nn = num.back();
				num.pop_back();
				if (nn % 2 == 0)
					Alice += nn;
				flag = 1;
			}
		}
		if (Alice == Bob)
			printf("Tie\n");
		else if (Alice > Bob)
			printf("Alice\n");
		else
			printf("Bob\n");
	}
}