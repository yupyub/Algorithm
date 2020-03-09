// SCC : Tarjan Algorithm : O(V+E)
// + Topological Sort
#pragma GCC optimize("O3") 
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#define V_MAX 301
using namespace std;
vector<vector<int> >graph;
vector<vector<int> > SCC;
stack<int>dfs_stack;
int graph_arr[V_MAX][V_MAX];
int dfs_order[V_MAX];
int finish[V_MAX];
int SCC_num[V_MAX];
int SCC_graph[V_MAX][V_MAX];
int V;
int order = 1;
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
		scanf("%d",&V);
		graph.clear();
		graph.resize(V+1);
		SCC.clear();
		for(int i = 0;i<V;i++){
			for(int j = 0;j<V;j++){
				scanf("%1d",&graph_arr[i][j]);
				if(graph_arr[i][j])
					graph[i].push_back(j);
			}
		}
		order = 1;
		for(int i = 0;i<V;i++)
			dfs_order[i] = finish[i] = 0;
		for(int i = 0;i<V;i++)
			if(!finish[i])
				Tarjan(i);
		for(int i = 0;i<SCC.size();i++)
			for(int j : SCC[i])
				SCC_num[j] = i;
		for(int i = 0;i<V;i++)
			for(int j = 0;j<V;j++)
				SCC_graph[i][j] = 0;
		for(int i = 0;i<V;i++)
			for(int j = 0;j<V;j++)
				if(SCC_num[i]!=SCC_num[j]&&graph_arr[i][j])
					SCC_graph[SCC_num[i]][SCC_num[j]] = 1;
		for(int k = 0;k<SCC.size();k++)
			for(int i = 0;i<SCC.size();i++)
				for(int j = 0;j<SCC.size();j++)
					if(SCC_graph[i][j] && SCC_graph[i][k] && SCC_graph[k][j])
						SCC_graph[i][j] = 0;
		int ans = 0;
		for(auto temp : SCC)
			ans += temp.size() == 1 ? 0 : temp.size();
		for(int i = 0;i<SCC.size();i++)
			for(int j = 0;j<SCC.size();j++)
				ans += SCC_graph[i][j];
		printf("%d\n",ans);
		for(auto temp : SCC){
			if(temp.size() == 1)
				continue;
			for(int i = 1;i<temp.size();i++)
				printf("%d %d\n",temp[i-1]+1,temp[i]+1);
			printf("%d %d\n",temp[temp.size()-1]+1,temp[0]+1);
		}
		for(int i = 0;i<SCC.size();i++)
			for(int j = 0;j<SCC.size();j++)
				if(SCC_graph[i][j])
					printf("%d %d\n",SCC[i][0]+1,SCC[j][0]+1);
	}	
}