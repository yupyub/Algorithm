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
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		int a;
		vector<int>A;
		vector<int>B;
		vector<int>C;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a);
			C.push_back(a);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &a);
			if (a == 1)
				A.push_back(C[i]);
			else
				B.push_back(C[i]);
		}

		sort(A.begin(), A.end(),greater<>());
		sort(B.begin(), B.end(), greater<>());
		vector<ll>A_acc(A.size() + 1);
		A_acc[0] = 0;
		for (int i = 0; i < A.size(); i++) {
			A_acc[i+1] = A_acc[i] + A[i];
		}
		int ans = 987654321;
		int sum = 0;
		for (int i = 0; i <= B.size(); i++) {
			int s = 0, e = A.size();
			while (s <= e) {
				int mid = (s + e) / 2;
				if (A_acc[mid] + sum >= m) {
					ans = min(ans, mid + i * 2);
					e = mid - 1;
				}
				else 
					s = mid + 1;
			}
			if (i == B.size())
				break;
			sum += B[i];
		}
		if (ans == 987654321)
			printf("-1\n");
		else 
			printf("%d\n",ans);
	}
}