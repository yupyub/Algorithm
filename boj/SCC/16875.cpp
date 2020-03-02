// SCC : Tarjan Algorithm : O(V+E)
// + Topological Sort
#pragma GCC optimize("O3") 
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#define V_MAX 2501
using namespace std;
vector<vector<int> >graph;
vector<vector<int> > SCC;
vector<int> SCC_indegree;
vector<int> SCC_outeredge;
vector<int> SCC_inneredge;
stack<int> dfs_stack;
int dfs_order[V_MAX];
int finish[V_MAX];
int N;
int order = 1,site_counter = 0;
int SCC_num[V_MAX];
int SCC_graph[V_MAX][V_MAX];
queue<int> q,SCC_q;
int used_vertex;
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
		while(1){
			int top = dfs_stack.top();
			dfs_stack.pop();
			temp_SCC.push_back(top);
			finish[top] = 1;
			if(top == node)
				break;
		}
		SCC.push_back(temp_SCC);
	}
	return min_order;
}
int calculate(int SCC_n){
	int k = SCC[SCC_n].size();
	int ret = k*k - SCC_inneredge[SCC_n] - k;
	used_vertex += k;
	ret += k*(N-used_vertex) - SCC_outeredge[SCC_n];
	return ret;
}
int main(){
	int a;
	scanf("%d",&N);
	graph.resize(N+1);
	for(int i = 1;i<=N;i++){
		for(int j = 1;j<=N;j++){
			scanf("%1d",&a);
			if(a)
				graph[i].push_back(j);
		}
	}
	for(int i = 1;i<=N;i++){
		if(!finish[i])
			Tarjan(i);
	}
	for(int i = 0;i<SCC.size();i++)
		for(int j : SCC[i])
			SCC_num[j] = i;
	SCC_indegree.resize(SCC.size());
	SCC_outeredge.resize(SCC.size());
	SCC_inneredge.resize(SCC.size());
	for(int i = 1;i<=N;i++){
		for(int j : graph[i]){
			if(SCC_num[i] != SCC_num[j]){
				SCC_graph[SCC_num[i]][SCC_num[j]] = 1;
				SCC_outeredge[SCC_num[i]]++;
			}
			else{
				SCC_inneredge[SCC_num[i]]++;
			}
		}
	}
	for(int i = 0;i<SCC.size();i++)
		for(int j = 0;j<SCC.size();j++)
			if(SCC_graph[i][j] == 1)
				SCC_indegree[j]++;
	for(int i = 0;i<SCC.size();i++)
		if(SCC_indegree[i] == 0)
			SCC_q.push(i);
	int ans = 0;
	while(!SCC_q.empty()){
		int SCC_n = SCC_q.front();
		SCC_q.pop();
		for(int i = 0;i<SCC.size();i++){
			if(SCC_graph[SCC_n][i]){
				SCC_indegree[i]--;
				if(SCC_indegree[i] == 0)
					SCC_q.push(i);
			}
		}
		ans += calculate(SCC_n);
	}
	printf("%d\n",ans);
}