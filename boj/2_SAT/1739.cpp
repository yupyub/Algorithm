// 2-SAT Algorithm (Using SCC) + Get Solution
// SCC : Tarjan Algorithm : O(V+E)
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#define V_MAX 2000002 // True False 2경우의 Vertex 필요 (2~V*2+1 index 사용)
#define NUMBERING(x) ((x)<0?-(x)*2:(x)*2+1) // 1->3, -1->2 // 2->5, -2->4
#define OPPOSITE(x) ((x)%2?(x)-1:(x)+1)     // 3->2, 2->3  // 5->4, 4->5
using namespace std;
vector<vector<int> >graph;
stack<int> dfs_stack;
int dfs_order[V_MAX];
int finish[V_MAX];
int SCC_num[V_MAX];
int SAT_ans[V_MAX];
int V,E,N,M;
int order = 1,numb = 0;
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
			SCC_num[top] = numb;
			finish[top] = 1;
			if(top == node)
				break;
		}
		numb++;
	}
	return min_order;
}
void add_graph(int u,int v){
	graph[OPPOSITE(u)].push_back(v);
	graph[OPPOSITE(v)].push_back(u);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int a,b,c,d;
		int v1,v2,h1,h2;
		scanf("%d %d %d",&N,&M,&E);
		V = N*M;
		graph.clear();
		graph.resize(2*V+2);
		for(int i = 0;i<E;i++){
			scanf("%d %d %d %d",&a,&b,&c,&d);
			if(a == c && b ==d) // TC 오류인듯
				continue;
			if(a<=c)
				h1 = NUMBERING(N+b), h2 = NUMBERING(N+d);
			else
				h1 = NUMBERING(-(N+b)), h2 = NUMBERING(-(N+d));
			if(b<=d)
				v1 = NUMBERING(a), v2 = NUMBERING(c);
			else
				v1 = NUMBERING(-a), v2 = NUMBERING(-c);
			if(a == c)
				add_graph(v1,v2);
			else if(b == d)
				add_graph(h1,h2);
			else{
				add_graph(v1,h1);
				add_graph(v1,v2);
				add_graph(h1,h2);
				add_graph(h2,v2);
			}
		}
		for(int i = 2;i<2*V+2;i++)
			finish[i] = dfs_order[i] = 0;
		order = 1;
		numb = 0;
		for(int i = 2;i<2*V+2;i++){
			if(!finish[i])
				Tarjan(i);
		}
		int ans = 0;
		// if answer is not exist
		for(int i = 1;i<=V;i++){
			if(SCC_num[NUMBERING(i)] == SCC_num[OPPOSITE(NUMBERING(i))]){
				ans = 1;
				break;
			}
		}
		if(ans)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}