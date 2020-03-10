// 2-SAT Algorithm (Using SCC)
// SCC : Tarjan Algorithm : O(V+E)
#pragma GCC optimize("O3")
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#define V_MAX 500002 // True False 2경우의 Vertex 필요 (0~V*2+1 index 사용)
#define NUMBERING(x) ((x)<0?-(x)*2:(x)*2+1) // 1->3, -1->2 // 2->5, -2->4 // *** 0->0,1 ***
#define OPPOSITE(x) ((x)%2?(x)-1:(x)+1)     // 3->2, 2->3  // 5->4, 4->5  // *** 1->0, 0->1 ***
using namespace std;
vector<vector<int> >graph;
stack<int> dfs_stack;
int dfs_order[V_MAX];
int finish[V_MAX];
int SCC_num[V_MAX];
int N,M;
int order = 1,ans,numbering = 0;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
char map[500][500];
int Tarjan(int node){
	dfs_order[node] = order++;
	dfs_stack.push(node);
	int min_order = dfs_order[node];
	for(int nxt : graph[node]){
		if(!dfs_order[nxt])
			min_order = min(min_order,Tarjan(nxt));
		else if(!finish[nxt])
			min_order = min(min_order,dfs_order[nxt]);
	}
	if(min_order == dfs_order[node]){
		while(1){
			int top = dfs_stack.top();
			dfs_stack.pop();
			SCC_num[top] = numbering;
			finish[top] = 1;
			if(top == node)
				break;
		}
		numbering++;
	}
	return min_order;
}
void add_graph_B(int x,int y){
	int nxt,k;
	int ops = 0,odd = -1,even = -1; // map 범위를 벗어나는 명제인지 확인
	for(int i = 0;i<4;i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx<0||ny<0||nx>=N||ny>=M || map[nx][ny] !='W'){
			ops = (i+2)%4;
			if(ops%2)
				odd = ops;
			else
				even = ops;
			nx = x+dx[ops];
			ny = y+dy[ops];
			if(map[nx][ny] != 'W'){
				ans = 1;
				return;
			}
			k = NUMBERING(M*x+y);
			if(ops == 0||ops == 3)
				graph[OPPOSITE(k)].push_back(k);
			else
				graph[k].push_back(OPPOSITE(k));
		}
	}
	for(int i = 0;i<2;i++){
		if(odd!=-1&&i%2)
			continue;
		if(even!=-1&&(!(i%2)))
			continue;
		int nx = x+dx[i];
		int ny = y+dy[i];
		int a = NUMBERING(M*nx+ny);
		int nnx = x+dx[i+2];
		int nny = y+dy[i+2];
		int b = NUMBERING(M*nnx+nny);
		if(i%2){
			graph[OPPOSITE(b)].push_back(OPPOSITE(a));
			graph[a].push_back(b);
		}
		else{
			graph[OPPOSITE(a)].push_back(OPPOSITE(b));
			graph[b].push_back(a);
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&N,&M);
		int V = N*M-1;
		graph.clear();
		graph.resize(V*2+2);
		int W_num = 0,B_num = 0;
		for(int i = 0;i<N;i++)
			for(int j = 0;j<M;j++)
				scanf(" %c",&map[i][j]);
		ans = 0;
		for(int i = 0;i<N;i++){
			for(int j = 0;j<M;j++){
				if(map[i][j] == 'B'){
					add_graph_B(i,j);
					B_num++;
				}
				else if(map[i][j] == 'W')
					W_num++;
			}
		}
		if(ans || W_num != B_num*2){
			printf("NO\n");
			continue;
		}
		order = 1;
		numbering = 0;
		for(int i = 0;i<=V*2+1;i++)
			finish[i] = dfs_order[i] = 0;
		for(int i = 0;i<=V*2+1;i++){
			if(!finish[i])
				Tarjan(i);
		}
		for(int i = 0;i<=V;i++){
			if(SCC_num[NUMBERING(i)] == SCC_num[OPPOSITE(NUMBERING(i))]){
				ans = 1;
				break;
			}
		}
		for(int i = 0;i<=V*2+1;i++){
			printf("%d) ",i);
			for(int j : graph[i]){
				printf("%d, ",j);
			}
			printf("\n");
		}
		if(ans)
			printf("NO\n");
		else 
			printf("YES\n");
	}
}