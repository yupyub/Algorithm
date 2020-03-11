// 2-SAT Algorithm (Using SCC)
// SCC : Tarjan Algorithm : O(V+E)
#pragma GCC optimize("O3")
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#define V_MAX 1000002 
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
int ddx[] = {2,0,1,1};
int ddy[] = {0,2,1,-1};
char map[500][500];
int NUMBERING(int k,int p){
	return k*4+p;
}
int OPPOSITE(int k){
	return 4*(k/4)+(k+2)%4;
}
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
	int k = M*x+y;
	for(int i = 0;i<4;i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx<0||ny<0||nx>=N||ny>=M || map[nx][ny] !='W'){
			int ops = (i+2)%4;
			nx = x+dx[ops];
			ny = y+dy[ops];
			if(map[nx][ny] != 'W'){
				ans = 1;
				return;
			}
			switch (ops){
				case 0: 
					graph[NUMBERING(k,2)].push_back(NUMBERING(k,0));
					break;
				case 1:
					graph[NUMBERING(k,1)].push_back(NUMBERING(k,3));
					break;
				case 2:
					graph[NUMBERING(k,0)].push_back(NUMBERING(k,2));
					break;
				case 3:
					graph[NUMBERING(k,3)].push_back(NUMBERING(k,1));
					break;
			}
		}
	}
	for(int i = 0;i<4;i++){
		int nx = x+ddx[i];
		int ny = y+ddy[i];
		int a = k;
		int b = M*nx+ny;
		if(nx<0||ny<0||nx>=N||ny>=M || map[nx][ny] !='B')
			continue;
		switch(i){
			case 0:
				graph[NUMBERING(b,0)].push_back(NUMBERING(a,0));
				graph[NUMBERING(a,2)].push_back(NUMBERING(b,2));
				break;
			case 1:
				graph[NUMBERING(b,1)].push_back(NUMBERING(a,1));
				graph[NUMBERING(a,3)].push_back(NUMBERING(b,3));
				break;
			case 2:
				graph[NUMBERING(b,0)].push_back(NUMBERING(a,1));
				graph[NUMBERING(a,3)].push_back(NUMBERING(b,2));
				graph[NUMBERING(b,1)].push_back(NUMBERING(a,0));
				graph[NUMBERING(a,2)].push_back(NUMBERING(b,3));
				break;
			case 3:
				graph[NUMBERING(b,0)].push_back(NUMBERING(a,3));
				graph[NUMBERING(a,1)].push_back(NUMBERING(b,2));
				graph[NUMBERING(b,3)].push_back(NUMBERING(a,0));
				graph[NUMBERING(a,2)].push_back(NUMBERING(b,1));
				break;
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
		graph.resize(V*4+4);
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
		for(int i = 0;i<V*4+4;i++)
			finish[i] = dfs_order[i] = 0;
		for(int i = 0;i<V*4+4;i++){
			if(!finish[i])
				Tarjan(i);
		}
		for(int i = 0;i<=V;i++){
			if(SCC_num[NUMBERING(i,0)] == SCC_num[NUMBERING(i,2)]){
				ans = 1;
				break;
			}
			if(SCC_num[NUMBERING(i,1)] == SCC_num[NUMBERING(i,3)]){
				ans = 1;
				break;
			}
		}
		if(ans)
			printf("NO\n");
		else 
			printf("YES\n");
	}
}