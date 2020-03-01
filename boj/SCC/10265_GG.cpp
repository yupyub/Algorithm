// SCC : Tarjan Algorithm : O(V+E) 
// + 0-1Knapsack
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#define V_MAX 1001
using namespace std;
vector<vector<int> >graph;
vector<vector<int> > SCC;
stack<int> dfs_stack;
int dfs_order[V_MAX];
int finish[V_MAX];
int V,K;
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
	int a;
	scanf("%d %d",&V,&K);
	graph.resize(V+1);
	for(int i = 1;i<=V;i++){
		scanf("%d",&a);
		graph[i].push_back(a);
	}
	order = 1;
	for(int i = 1;i<=V;i++)
		dfs_order[i] = finish[i] = 0;
	for(int i = 1;i<=V;i++){
		if(!finish[i])
			Tarjan(i);
	}
	vector<int> weight; // same as 0-1 Knapsack problem
	for(int i = 0;i<SCC.size();i++)
		weight.push_back((int)SCC[i].size());
	int dp[1001];
	for(int i = 0;i<1001;i++)
		dp[i] = -1;
	dp[0] = 0;
	for(int w : weight){
		for(int i = K;i>=0;i--){
			if(i-w<0||dp[i-w] == -1)
				continue;
			dp[i] = max(dp[i-w]+w,dp[i]);
		}
	}
	int ans = 0;
	for(int i = 0;i<=K;i++)
		ans = max(ans,dp[i]);
	printf("%d\n",ans);
}