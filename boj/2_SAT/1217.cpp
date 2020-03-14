// 2-SAT Algorithm (Using SCC)
// SCC : Tarjan Algorithm : O(V+E)
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#define V_MAX 40002 // True False 2경우의 Vertex 필요 (2~V*2+1 index 사용)
#define NUMBERING(x) ((x)<0?-(x)*2:(x)*2+1) // 1->3, -1->2 // 2->5, -2->4
#define OPPOSITE(x) ((x)%2?(x)-1:(x)+1)     // 3->2, 2->3  // 5->4, 4->5
using namespace std;
vector<vector<int> > graph;
stack<int> dfs_stack;
int dfs_order[V_MAX];
int finish[V_MAX];
int SCC_num[V_MAX];
int V,E;
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
			finish[top] = 1;
			SCC_num[top] = numb;
			if(top == node)
				break;
		}
		numb++;
	}
	return min_order;
}
int main(){
	while(1){
		int a,b;
		scanf("%d %d",&E,&V);
		if(V == 0 && E == 0)
			break;
		graph.clear();
		graph.resize(V*2+2);
		for(int i = 0;i<E;i++){
			scanf("%d %d",&a,&b);
			a = NUMBERING(a);
			b = NUMBERING(b);
			graph[OPPOSITE(a)].push_back(b);
			graph[OPPOSITE(b)].push_back(a);
		}
		for(int i = 0;i<=V*2+1;i++)
			finish[i] = dfs_order[i] = 0;
		order = 1;
		numb = 0;
		for(int i = 2;i<=V*2+1;i++){
			if(!finish[i])
				Tarjan(i);
		}
		int ans = 0;
		for(int i = 1;i<=V;i++){
			if(SCC_num[NUMBERING(i)] == SCC_num[NUMBERING(-i)]){
				ans = 1;
				break;
			}
		}
		if(ans)
			printf("0\n");
		else
			printf("1\n");
	}
	return 0;
}