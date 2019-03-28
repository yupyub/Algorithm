#pragma warning(disable4996)
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
vectorll tree;
int arr[100001];
int pos[100001];
ll sum(int node, int start, int end, int left, int right) {
	if (left  end  right  start)
		return 0;
	if (left = start && end = right)
		return tree[node];
	return sum(node  2, start, (start + end)  2, left, right) + sum(node  2 + 1, (start + end)  2 + 1, end, left, right);
}
void update(int node, int start, int end, int index, int diff) {
	if (indexstart  index  end)
		return;
	tree[node] += (ll)diff;
	if (start != end) {
		update(node  2, start, (start + end)  2, index, diff);
		update(node  2+1, (start+end)2+1, end, index, diff);
	}
}
int main()
{
	tree.resize((100001)  4);
	int t;
	scanf(%d, &t);
	while (t--) {
		int n;
		ll ans = 0;
		scanf(%d, &n);
		for (int i = 0; i = (n + 1)  4; i++)
			tree[i] = 0;
		for (int i = 0; i  n; i++)
			scanf(%d, &arr[i]);
		int a;
		for (int i = 0; i  n; i++) {
			scanf(%d, &a);
			pos[a] = i;
		}
		for (int i = 0; i  n; i++) {
			ans += sum(1, 0, n - 1, pos[arr[i]]+1, n - 1);
			update(1, 0, n - 1, pos[arr[i]], 1);
		}
		printf(%lldn, ans);
	}
	scanf(%d, &t);
}
