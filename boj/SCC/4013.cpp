// SCC : Tarjan Algorithm : O(V+E)
// + Topological Sort
#pragma GCC optimize("O3") 
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#define V_MAX 500001
using namespace std;
vector<vector<int> >graph;
vector<vector<int> > SCC;
vector<vector<int> > SCC_graph;
vector<int> SCC_money;
vector<int> SCC_rest;
vector<int> DFS_money;
stack<int> dfs_stack;
int dfs_order[V_MAX];
int finish[V_MAX];
int money[V_MAX];
int rest[V_MAX]; // restaurant
int V,E,S,P,SCC_start;
int order = 1;
int SCC_num[V_MAX];
int Tarjan(int node){
	dfs_order[node] = order++;
	dfs_stack.push(node);
	int min_order = dfs_order[node];
	for(int nxt : graph[node]){
		if(!dfs_order[nxt]) // 방문하지 않은 서브노드 방문
			min_order = min(min_order,Tarjan(nxt));
		else if(!finish[nxt]) // 아직 SCC에 포함되지 않은 노드 중 가장 높은 조상노드를 찾는다
			min_order = min(min_order,dfs_order[nxt]);
	}
	// 자신과 자신의 서브트리가 방문 가능한 가장 높은 노드가 자기 자신일 때, SCC 구성
	if(min_order == dfs_order[node]){
		vector<int> temp_SCC;
		int tot_money = 0,rest_exist = 0;
		while(1){
			int top = dfs_stack.top();
			dfs_stack.pop();
			temp_SCC.push_back(top);
			finish[top] = 1;
			tot_money += money[top];
			rest_exist += rest[top];
			if(top == node)
				break;
		}
		SCC.push_back(temp_SCC);
		SCC_money.push_back(tot_money);
		SCC_rest.push_back(rest_exist == 0 ? 0 : 1);
	}
	return min_order;
}
void DFS(int node,int tot_money){
	DFS_money[node] = tot_money+SCC_money[node];
	for(int nxt : SCC_graph[node]){
		if(DFS_money[nxt]<DFS_money[node]+SCC_money[nxt]){
			DFS(nxt,DFS_money[node]);	
		}
	}
}
int main(){
	int a,b;
	scanf("%d %d",&V,&E);
	graph.clear();
	graph.resize(V+1);
	SCC.clear();
	for(int i = 0;i<E;i++){
		scanf("%d %d",&a,&b);
		graph[a].push_back(b);
	}
	for(int i = 1;i<=V;i++)
		scanf("%d",&money[i]);
	scanf("%d %d",&S,&P);
	for(int i = 0;i<P;i++){
		scanf("%d",&a);
		rest[a] = 1;
	}
	for(int i = 1;i<=V;i++){
		if(!finish[i])
			Tarjan(i);
	}
	for(int i = 0;i<SCC.size();i++){
		for(int j : SCC[i]){
			SCC_num[j] = i;
			if(j == S)
				SCC_start = i;
		}
	}
	SCC_graph.resize(SCC.size());
	DFS_money.resize(SCC.size());
	for(int i = 1;i<=V;i++)
		for(int j : graph[i])
			if(SCC_num[i] != SCC_num[j])
				SCC_graph[SCC_num[i]].push_back(SCC_num[j]);
	DFS(SCC_start,0);
	int ans = -1;
	for(int i = 0;i<SCC.size();i++){
		if(SCC_rest[i] && DFS_money[i]>ans)
			ans = DFS_money[i];
	}
	printf("%d\n",ans);
}