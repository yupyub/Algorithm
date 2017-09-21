#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int ch[100001][1001];
void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int gcd(int a, int b) {
	while (b != 0) {
		int temp = a%b;
		a = b;
		b = temp;
	}
	return abs(a);
}
int pita(int len) {
	int w, h;
	int gw, gh, g;
	int ans = 0;
	for (int i = 2; i < 10001; i++) {
		for (int j = 1; j < i; j++) {
			w = 2 * i*j;
			h = i*i - j*j;
			if (h < w)
				swap(&h, &w);
			g = gcd(h, w);
			gh = h / g;
			gw = w / g;
			if (ch[gh][gw] == 0) {
				ch[gh][gw] = 1;
				len -= 2 * (w+h);
				if (len >= 0)
					ans++;
				else
					return ans;
			}
		}
		//printf("%d\n", i);
	}
}
/*
int sol(int len) {
	int ans = 0;
	for (int i = 2; i < 1001; i++) {
		for (int j = 1; j < i; j++) {
			if (tri[i][j])
				len -= 2 * (2 * i*j + i*i - j*j);
			if (len >= 0)
				ans++;
			else
				return ans;	
		}
	}
}
*/
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%d\n",pita(n));
		memset(ch, sizeof(ch), 0);
	}

}