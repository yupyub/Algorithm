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
		int n;
		scanf("%d", &n);
		char arr[201];
		scanf("%s", arr);
		string str(arr);
		int ans = 0;
		if (str.substr(0, 4).compare("2020") == 0)
			ans = 1;
		else if (str.substr(n - 4, n).compare("2020") == 0)
			ans = 1;
		else {
			string sp("2020");
			for (int i = 1; i < 4; i++) {
				if (str.substr(0, i).compare(sp.substr(0, i)) == 0)
					if (str.substr(n -4+i, n).compare(sp.substr(i, 4)) == 0)
						ans = 1;
			}

		}
		if (ans)
			printf("Yes\n");
		else
			printf("No\n");
	}
}