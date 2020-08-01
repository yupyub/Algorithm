// SCC : Tarjan Algorithm : O(V+E)
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#define V_MAX 501
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
vector<vector<int> >graph;
vector<vector<int> > SCC;
int SCC_graph[V_MAX][V_MAX];
int SCC_visit[V_MAX];
stack<int> dfs_stack;
int dfs_order[V_MAX];
int SCC_indegree[V_MAX];
int finish[V_MAX];
int N;
int order = 1;
int SCC_num[V_MAX];
ll fact(int n){
	ll ret = 1;
	for(int i = 2;i<=n;i++)
		ret = (ret*i)%MOD;
	return ret;
}
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
	int a,b;
	scanf("%d",&N);
	graph.resize(N+1);
	for(int i = 1;i<=N;i++){
		for(int j = 1;j<=N;j++){
			scanf("%d",&a);
			if(a && j != i)
				graph[i].push_back(j);
		}
	}
	order = 1;
	for(int i = 1;i<=N;i++){
		if(!finish[i])
			Tarjan(i);
	}
	for(int i = 0;i<SCC.size();i++)
		for(int j : SCC[i])
			SCC_num[j] = i;
	ll ans = 1;
	for(int i = 1;i<=N;i++)
		for(int j : graph[i])
			if(SCC_num[i] != SCC_num[j])
				SCC_graph[SCC_num[i]][SCC_num[j]] = 1;
			
	for(int i = 0;i<SCC.size();i++)
		for(int j = 0;j<SCC.size();j++)
			if(SCC_graph[i][j])
				SCC_indegree[j]++;
	////
	queue<int>q;
	for(int i = 0;i<SCC.size();i++)
		if(SCC_indegree[i] == 0)
			q.push(i);

	while(!q.empty()){
		int n = q.front();
		q.pop();
		for(int i = 0;i<SCC.size();i++){
			if(SCC_graph[n][i]){
				//printf(">> %d %d %d\n",n,i,SCC_indegree[i]);
				SCC_indegree[i]--;
				if(!SCC_indegree[i]){
					ans = ans*((ll)(SCC[n].size()*SCC[i].size()))%MOD; 
					ans = ans % MOD;
					q.push(i);
				}
			}
		}
	}
	
	
	
	////
	for(int i = 0;i<SCC.size();i++){
		if(SCC[i].size()>1){
			ans = ((ll)(ans*fact(SCC[i].size()-1)))%MOD;
		}
	}
	printf("%lld\n",ans);
	
}