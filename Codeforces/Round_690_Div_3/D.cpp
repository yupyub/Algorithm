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
		int arr[3000];
		int sum = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			sum += arr[i];
		}
		for (int i = n; i >= 1; i--) {
			if (sum % i != 0)
				continue;
			int num = sum / i;
			int cnt = i;
			int tmp = 0;
			int flag = 0;
			for (int j = 0; j < n; j++) {
				tmp += arr[j];
				if (tmp > num) {
					flag = 1;
					break;
				}
				else if (tmp == num) {
					cnt--;
					tmp = 0;
				}
			}
			//printf("%d %d %d\n", i, flag, cnt);
			if (flag || cnt != 0)
				continue;
			else {
				printf("%d\n", n-i);
				break;
			}
		}
		
	}
}