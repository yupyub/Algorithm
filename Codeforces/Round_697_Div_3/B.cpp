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
		int temp;
		scanf("%d", &temp);
		int num = 2020;
		int n = 1;
		int flag = 0;
		while (1) {
			if (num + n >= temp && temp >= num ) {
				flag = 1;
				break;
			}
			num += 2020;
			n++;
			if (num > temp)
				break;
		}
		if (flag) 
			printf("YES\n");
		else
			printf("NO\n");
	}
}