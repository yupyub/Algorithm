// 2-SAT Algorithm (Using SCC) + Get Solution
// SCC : Tarjan Algorithm : O(V+E)
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#define V_MAX 202 // True False 2경우의 Vertex 필요 (2~V*2+1 index 사용)
#define NUMBERING(x) ((x)<0?-(x)*2:(x)*2+1) // 1->3, -1->2 // 2->5, -2->4
#define OPPOSITE(x) ((x)%2?(x)-1:(x)+1)     // 3->2, 2->3  // 5->4, 4->5
using namespace std;
vector<vector<int> >graph;
stack<int> dfs_stack;
int dfs_order[V_MAX];
int finish[V_MAX];
int SCC_num[V_MAX];
int SAT_ans[V_MAX];
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
			SCC_num[top] = numb;
			finish[top] = 1;
			if(top == node)
				break;
		}
		numb++;
	}
	return min_order;
}
int couple(int x,char c){
	if(c == 'h')
		return x*2;
	else
		return x*2+1;
}
int main(){
	while(1){
		int a,b;
		char c,d;
		scanf("%d %d",&V,&E);
		if(V == 0 && E == 0) 
			break;
		graph.clear();
		graph.resize(V*4);
		int h = NUMBERING(0); //h
		int w = NUMBERING(1);   //w
		graph[OPPOSITE(h)].push_back(h);
		graph[w].push_back(OPPOSITE(w));
		for(int i = 1;i<V;i++){ 
			// 0 to V-1 -> 0 to 2*V-1 -> NUMBERING -> 0 to 4*V-1
			h = NUMBERING(i*2);   //h
			w = NUMBERING(i*2+1); //w
			graph[OPPOSITE(w)].push_back(h);
			graph[OPPOSITE(h)].push_back(w);
			graph[h].push_back(OPPOSITE(w));
			graph[w].push_back(OPPOSITE(h));
		}
		for(int i = 0;i<E;i++){
			scanf("%d%c %d%c",&a,&c,&b,&d);
			a = couple(a,c);
			b = couple(b,d);
			a = NUMBERING(a);
			b = NUMBERING(b);
			graph[a].push_back(OPPOSITE(b));
			graph[b].push_back(OPPOSITE(a));
		}
		order = 1;
		numb = 0;
		for(int i = 0;i<V*4;i++)
			finish[i] = dfs_order[i] = 0;
		for(int i = 0;i<V*4;i++){
			if(!finish[i])
				Tarjan(i);
		}
		int ans = 0;
		// if answer is not exist
		for(int i = 0;i<2*V;i++){
			if(SCC_num[NUMBERING(i)] == SCC_num[OPPOSITE(NUMBERING(i))]){
				ans = 1;
				break;
			}
		}
		if(ans){
			printf("bad luck\n");
			continue;
		}
		memset(SAT_ans,-1,sizeof(SAT_ans));
		vector<pair<int,int> >topo;
		// 	SCC 의 넘버링 순서가 위상정렬시 stack에 넣는 순서와 같다.
		// 	즉 SCC 넘버링을 뒤집어 주면 위상정렬이 된다.
		for(int i = 0;i<V*4;i++)
			topo.push_back(make_pair(SCC_num[i],i));
		sort(topo.begin(),topo.end());
		for(int i = topo.size()-1;i>=0;i--){
			int idx = topo[i].second;
			if(SAT_ans[idx/2] == -1)
				SAT_ans[idx/2] = !(idx%2);
		}
		for(int i = 2;i<V*2;i++){
			if(SAT_ans[i] == 1)
				continue;
			int tmp = i/2;
			if(i%2)
				printf("%dw ",tmp);
			else
				printf("%dh ",tmp);
		}
		printf("\n");
	}
	return 0;
}