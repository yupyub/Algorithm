#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	char L[12], R[12];
	scanf("%s %s", L, R);
	int ans = 0;
	if (strlen(L) == strlen(R)) {
		int idx = 0;
		while (idx < strlen(L)) {
			if (L[idx] == R[idx] && L[idx] == '8')
				ans++;
			else if (L[idx] != R[idx])
				break;
			idx++;
		}
	}
	printf("%d", ans);
}