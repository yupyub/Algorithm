// 2-SAT Algorithm (Using SCC) + Get Solution
// SCC : Tarjan Algorithm : O(V+E)
// + CCW & Line intersection
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#define V_MAX 2002 // True False 2경우의 Vertex 필요 (2~V*2+1 index 사용)
#define NUMBERING(x) ((x)<0?-(x)*2:(x)*2+1) // 1->3, -1->2 // 2->5, -2->4
#define OPPOSITE(x) ((x)%2?(x)-1:(x)+1)     // 3->2, 2->3  // 5->4, 4->5
#define ERR 1e-9
using namespace std;
typedef pair<double, double> dd;
vector<int>graph[V_MAX];
stack<int> dfs_stack;
int dfs_order[V_MAX];
int finish[V_MAX];
int SCC_num[V_MAX];
dd source[V_MAX];
vector<pair<int, dd> > line;
int V,E;
int order = 1,numb = 0;
int ccw(dd a, dd b, dd c){
	double t = a.first*b.second - a.second*b.first;
	t += b.first*c.second - b.second*c.first;
	t += c.first*a.second - c.second*a.first;
	if(t>0+ERR) return 1;
	else if(t<0-ERR) return -1;
	else return 0;
}
int isIntersect(pair<dd,dd> x,pair<dd,dd> y) {
    dd a = x.first;
    dd b = x.second;
    dd c = y.first;
    dd d = y.second;
    int ab = ccw(a, b, c)*ccw(a, b, d);
    int cd = ccw(c, d, a)*ccw(c, d, b);
    if (ab == 0 && cd == 0) {
        if (a > b)swap(a, b);
        if (c > d)swap(c, d);
        return c <= b&&a <= d;
    }
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
	double a,b;
	int s;
	scanf("%d %d",&V,&E);
	for(int i = 0;i<V;i++){
		scanf("%lf %lf",&a,&b);
		source[i+1] = make_pair(a,b);
	}
	for(int i = 0;i<E;i++){
		scanf("%d %lf %lf",&s,&a,&b);
		line.push_back(make_pair(s,make_pair(a,b)));
	}
	for(int i = 0;i<E;i++){
		for(int j = i+1;j<E;j++){
			if(line[i].first == line[j].first)
				continue;
			if(isIntersect(make_pair(source[line[i].first],line[i].second),make_pair(source[line[j].first],line[j].second))){
				int s1 = NUMBERING(i+1);
				int s2 = NUMBERING(j+1);
				graph[OPPOSITE(s1)].push_back(s2);
				graph[OPPOSITE(s2)].push_back(s1);
				graph[s1].push_back(OPPOSITE(s2));
				graph[s2].push_back(OPPOSITE(s1));
			}
		}
	}
	for(int i = 2;i<=E*2+1;i++){
		if(!finish[i])
			Tarjan(i);
	}
	// if answer is not exist
	for(int i = 1;i<=E;i++){
		if(SCC_num[NUMBERING(i)] == SCC_num[NUMBERING(-i)]){
			printf("impossible\n");
			return 0;
		}
	}
	printf("possible\n");
	return 0;
}