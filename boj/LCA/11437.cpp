#include <cstdio>
#include <algorithm>
#include <vector>
#define N_MAX 50001
#define POW_IS_N 25
using namespace std;
int depth[N_MAX];
int visit[N_MAX];
int parent[N_MAX][POW_IS_N]; // parent[i][j] : i 정점의 2^j 번쨰 조상노드
vector<int> tree[N_MAX];
void DFS(int now_node,int now_depth){
	visit[now_node] = 1;
	depth[now_node] = now_depth;
	for(int next_node : tree[now_node]){
		if(visit[next_node])
			continue;
		parent[next_node][0] = now_node;
		DFS(next_node,now_depth+1);
	}
}
void find_pow_parent(int node_num){
	for(int i = 1;i<POW_IS_N;i++)
		for(int j = 1;j<=node_num;j++)
			parent[j][i] = parent[parent[j][i-1]][i-1];
}
int LCA(int x,int y){
	if(depth[x]>depth[y])
		swap(x,y);
	for(int i = POW_IS_N-1;i>=0;i--){ // 두 정점의 높이를 맞춘다
		if(depth[y]-depth[x] >= (1<<i))
			y = parent[y][i];
	}
	if(x == y) // x 가 y의 LCA 인 경우
		return x;
	for(int i = POW_IS_N-1;i>=0;i--){
		// parent[x][i] == parent[y][i] 이면 공통조상이지만 최소공통조상이 아닐 수 있다.
		if(parent[x][i] != parent[y][i]){
			x = parent[x][i];
			y = parent[y][i];
		}
	}
	return parent[x][0];
}
int main(){
	int node_num,query_num,a,b;
	scanf("%d",&node_num);
	for(int i = 1;i<node_num;i++){
		scanf("%d %d",&a,&b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	parent[1][0] = 1;
	DFS(1,0);
	find_pow_parent(node_num);
	scanf("%d",&query_num);
	for(int i = 0;i<query_num;i++){
		scanf("%d %d",&a,&b);
		printf("%d\n",LCA(a,b));
	}
	return 0;	
}
	