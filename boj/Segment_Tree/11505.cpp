#include <cstdio>
#include <algorithm>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;
vector<ll> tree;
ll arr[1000001];
ll mult(int node, int start, int end, int left, int right) {
	//printf("(0) %lld\n",tree[node]);
	if (left > end || right < start)
		return 1;
	if (left <= start && end <= right)
		return tree[node];
	
	return (mult(node * 2, start, (start + end) / 2, left, right) * mult(node * 2 + 1, (start + end) / 2 + 1, end, left, right))%MOD;
}
void update(int node, int start, int end, int index, ll diff) {
	if (index<start || index > end)
		return ;
	//printf("(1) %lld %lld %lld (%d,%d),(%d)\n",tree[node],before,diff,start,end,index);
	if(start == index && end == index)
		tree[node] = diff;
	if (start != end) {
		update(node * 2, start, (start + end) / 2, index,diff);
		update(node * 2+1, (start+end)/2+1, end, index,diff);
		tree[node] = (tree[node*2]*tree[node*2+1])%MOD;
	}
	//printf("(2) %lld\n",tree[node]);
}
int main(){
	int n,m,k;
	ll a,b,c;
	scanf("%d %d %d",&n,&m,&k);
	tree.resize((n+1) * 4 +1);
	for(int i = 1;i<=n;i++){
		scanf("%lld",&arr[i]);
		update(1,1,n,i,arr[i]);
	}
	for(int i = 0;i<m+k;i++){
		scanf("%lld %lld %lld",&a,&b,&c);
		if(a == 1){
			update(1,1,n,b,c);
			arr[b] = c;
		}
		else
			printf("%lld\n",mult(1,1,n,b,c));
		/*
		printf("\n ))");
		for (int i = 0; i <= (n + 1) * 4; i++)
			printf("%lld ",tree[i]);
		*/
	}
}