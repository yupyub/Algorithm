#include <cstdio>
#include <vector>
using namespace std;
vector<vector<int> > tree;
int score[100001];
int accum[100001];
void dfs(int n, int s){
	accum[n] = score[n] + s;
	for(int nxt : tree[n]){
		dfs(nxt, score[n] + s);
	}
}
int main(){
	int n,m,a,b;
	scanf("%d %d",&n,&m);
	tree.resize(n+1);
	scanf("%*d");
	for(int i = 2;i<=n;i++){
		scanf("%d",&a);
		tree[a].push_back(i);
	}
	for(int i = 0;i<m;i++){
		scanf("%d %d",&a, &b);
		score[a] += b;
	}
	dfs(1, 0);
	for(int i = 1;i<=n;i++)
		printf("%d ", accum[i]);
	return 0;
}
