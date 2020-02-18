#include <cstdio>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;
int arr[3][500001];
int st[2][500001];
vector<int> tree;
vector<pair<int,int> > v;
int mini(int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return INF;
	if (left <= start && end <= right)
		return tree[node];
	return min(mini(node * 2, start, (start + end) / 2, left, right), mini(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}
void update(int node, int start, int end, int index, int diff) {
	if (index<start || index > end)
		return;
	tree[node] = min(tree[node],diff);
	if (start != end) {
		update(node * 2, start, (start + end) / 2, index, diff);
		update(node * 2+1, (start+end)/2+1, end, index, diff);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	tree.resize((n+1)*4);
	for(int i = 0;i<(n+1)*4;i++)
		tree[i] = INF;
	for(int i = 0;i<3;i++){
		for(int j = 1;j<=n;j++)
			scanf("%d",&arr[i][j]);
	}
	for(int i = 1;i<=n;i++){
		st[0][arr[1][i]] = i;
		st[1][arr[2][i]] = i;
	}
	int ans = 0;
	for(int i = 1;i<=n;i++){
		int nw = arr[0][i];
		if(mini(1,1,n,1,st[0][nw])>st[1][nw])
			ans++;
		update(1,1,n,st[0][nw],st[1][nw]);
	}
	printf("%d\n",ans);
	return 0;
}