// SCC : Tarjan Algorithm : O(V+E)
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#define V_MAX 100001
using namespace std;
vector<vector<int> >graph;
vector<vector<int> > SCC;
stack<int> dfs_stack;
int dfs_order[V_MAX];
int finish[V_MAX];
int SCC_indegree[V_MAX];
int V,E;
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
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int a,b;
		scanf("%d %d",&V,&E);
		graph.clear();
		graph.resize(V+1);
		SCC.clear();
		for(int i = 0;i<E;i++){
			scanf("%d %d",&a,&b);
			graph[a].push_back(b);
		}
		order = 1;
		for(int i = 1;i<=V;i++)
			dfs_order[i] = finish[i] = 0;
		for(int i = 1;i<=V;i++){
			if(!finish[i])
				Tarjan(i);
		}
		int ans = 0;
		for(int i = 0;i<SCC.size();i++)
			SCC_indegree[i] = 0;
		for(int i = 0;i<SCC.size();i++)
			for(int j : SCC[i])
				SCC_num[j] = i;
		for(int i = 1;i<=V;i++)
			for(int j : graph[i])
				if(SCC_num[i] != SCC_num[j])
					SCC_indegree[SCC_num[j]]++;
		for(int i = 0;i<SCC.size();i++)
			if(!SCC_indegree[i])
				ans++;
		printf("%d\n",ans);
	}
}