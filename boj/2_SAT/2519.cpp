// 2-SAT Algorithm (Using SCC) + Get Solution
// SCC : Tarjan Algorithm : O(V+E)
// + CCW & Line intersection
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#define V_MAX 6002 // True False 2경우의 Vertex 필요 (2~V*2+1 index 사용)
#define NUMBERING(x) ((x)<0?-(x)*2:(x)*2+1) // 1->3, -1->2 // 2->5, -2->4
#define OPPOSITE(x) ((x)%2?(x)-1:(x)+1)     // 3->2, 2->3  // 5->4, 4->5
using namespace std;
typedef pair<int, int> dd;
typedef pair<dd,dd> DD;
vector<int>graph[V_MAX];
stack<int> dfs_stack;
int dfs_order[V_MAX];
int finish[V_MAX];
int SCC_num[V_MAX];
DD line[V_MAX];
int SAT_ans[V_MAX];
int V,E;
int order = 1,numb = 0;
int ccw(dd a, dd b, dd c){
	int t = a.first*b.second - a.second*b.first;
	t += b.first*c.second - b.second*c.first;
	t += c.first*a.second - c.second*a.first;
	if(t>0) return 1;
	else if(t<0) return -1;
	else return 0;
}
int isIntersect(DD x,DD y) {
    dd a = x.first;
    dd b = x.second;
    dd c = y.first;
    dd d = y.second;
    int ab = ccw(a, b, c)*ccw(a, b, d);
    int cd = ccw(c, d, a)*ccw(c, d, b);
	/*
    if (ab == 0 && cd == 0) {
        if (a > b)swap(a, b);
        if (c > d)swap(c, d);
        return c <= b&&a <= d;
    }
	*/
    return ab <= 0 && cd <= 0;
}
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
int main(){
	int a,b,c,d,s;
	scanf("%d",&V);
	for(int i = 0;i<3*V;i++){
		scanf("%d %d %d %d",&a,&b,&c,&d);
		line[i] = make_pair(make_pair(a,b),make_pair(c,d));
	}
	int u,v;
	for(int i = 0;i<V;i++){
		for(int j = 0;j<3;j++){
			for(int k = 0;k<3;k++){
				if(k == j)
					continue;
				u = NUMBERING(3*i+j);
				v = NUMBERING(3*i+k);
				graph[OPPOSITE(v)].push_back(u);
				graph[OPPOSITE(u)].push_back(v);
			}
		}
	}
	for(int i = 0;i<3*V;i++){
		for(int j = i+1;j<3*V;j++){
			if(isIntersect(line[i],line[j])){
				u = NUMBERING(i);
				v = NUMBERING(j);
				graph[u].push_back(OPPOSITE(v));
				graph[v].push_back(OPPOSITE(u));
			}
		}
	}
	for(int i = 0;i<3*V*2;i++){
		if(!finish[i])
			Tarjan(i);
	}
	// if answer is not exist
	for(int i = 0;i<3*V;i++){
		if(SCC_num[NUMBERING(i)] == SCC_num[OPPOSITE(NUMBERING(i))]){
			printf("-1\n");
			return 0;
		}
	}
	memset(SAT_ans,-1,sizeof(SAT_ans));
	vector<pair<int,int> >topo;
	for(int i = 0;i<3*V*2;i++)
		topo.push_back(make_pair(SCC_num[i],i));
	sort(topo.begin(),topo.end());
	for(int i = topo.size()-1;i>=0;i--){
		int idx = topo[i].second;
		if(SAT_ans[idx/2] == -1)
			SAT_ans[idx/2] = !(idx%2);
	}
	vector<int> ans;
	for(int i = 0;i<3*V;i++)
		if(SAT_ans[i] == 0)
			ans.push_back(i+1);
	printf("%ld\n",ans.size());
	for(int i : ans)
		printf("%d ",i);
	return 0;
}