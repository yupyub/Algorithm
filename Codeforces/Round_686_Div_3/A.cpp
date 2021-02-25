#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%d ", n);
		for (int i = 1; i < n; i++) {
			printf("%d ", i);
		}
		printf("\n");
	}
}