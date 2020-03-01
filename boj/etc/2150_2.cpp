// SCC : Kosaraju Algorithm : O(V+E)
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#define V_MAX 10001
using namespace std;
vector<int>graph[2][V_MAX];
vector<vector<int> > SCC;
stack<int> dfs_stack;
int dfs_order[V_MAX];
int visit[V_MAX];
int V,E;
int ans_num;
// forward_dfs : 정방향 그래프를 DFS 수행하면서 끝나는 순서대로 stack에 삽입.
void forward_dfs(int node) {
	visit[node] = true;
	for(int nxt : graph[0][node])
		if(!visit[nxt])
			forward_dfs(nxt);
	dfs_stack.push(node);
}
// reverse_dfs : stack에서 pop하는 순서대로 역방향 그래프에 DFS를 수행하면서 한번 수행에 탐색되는 모든 정점들을 같은 SCC로 저장.
void reverse_dfs(int node,vector<int> &temp_SCC){
	visit[node] = false;
	temp_SCC.push_back(node);
	for(int nxt : graph[1][node])
		if(visit[nxt])
			reverse_dfs(nxt,temp_SCC);
}
int main(){
	int a,b;
	scanf("%d%d",&V,&E);
	for(int i = 0;i<E;i++){
		scanf("%d%d",&a,&b);
		graph[0][a].push_back(b);
		graph[1][b].push_back(a);
	}
	for(int i = 1;i<=V;i++){
		if(!visit[i])
			forward_dfs(i);
	}
	while(!dfs_stack.empty()){
		int s = dfs_stack.top();
		dfs_stack.pop();
		if(visit[s]){
			vector<int> tmp;
			reverse_dfs(s,tmp);
			SCC.push_back(tmp);
			ans_num++;
		}
	}
	for(int i = 0;i<ans_num;i++)
		sort(SCC[i].begin(),SCC[i].end());
	sort(SCC.begin(),SCC.end());
	printf("%d\n",ans_num);
	for(int i = 0;i<ans_num;i++){
		for(int j : SCC[i])
			printf("%d ",j);
		printf("-1\n");
	}
}