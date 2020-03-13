// 2-SAT Algorithm (Using SCC)
// SCC : Tarjan Algorithm : O(V+E)
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#define V_MAX 20002 // True False 2경우의 Vertex 필요 (2~V*2+1 index 사용)
#define NUMBERING(x) ((x)<0?-(x)*2:(x)*2+1) // 1->3, -1->2 // 2->5, -2->4
#define OPPOSITE(x) ((x)%2?(x)-1:(x)+1)     // 3->2, 2->3  // 5->4, 4->5
using namespace std;
vector<int>graph[V_MAX];
vector<vector<int> > SCC;
stack<int> dfs_stack;
int dfs_order[V_MAX];
int finish[V_MAX];
int SCC_num[V_MAX];
int V,E;
int order = 1;
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
	scanf("%d %d",&V,&E);
	for(int i = 0;i<E;i++){
		scanf("%d %d",&a,&b);
		a = NUMBERING(a);
		b = NUMBERING(b);
		graph[OPPOSITE(a)].push_back(b);
		graph[OPPOSITE(b)].push_back(a);
	}
	for(int i = 2;i<=V*2+1;i++){
		if(!finish[i])
			Tarjan(i);
	}
	for(int i = 0;i<SCC.size();i++)
		for(int j : SCC[i])
			SCC_num[j] = i;
	for(int i = 1;i<=V;i++){
		if(SCC_num[NUMBERING(i)] == SCC_num[NUMBERING(-i)]){
			printf("0\n");
			return 0;
		}
	}
	printf("1\n");
	return 0;
}