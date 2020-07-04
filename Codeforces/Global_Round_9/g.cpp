#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
#include <tuple>
#include <functional>
using namespace std;
int sz[200001];
int visit[200001];
vector<int>adj[200001];
long long ans = 0;
int getSz(int here,int dad){
    sz[here]=1;
    for(auto there:adj[here]){
        if(there==dad)continue;
        sz[here]+=getSz(there,here);
    }
    return sz[here];
}
 
int get_centroid(int here,int dad,int cap){
    //cap <---- (tree size)/2
    for(auto there:adj[here]){
        if(there==dad)continue;
        if(sz[there]>cap) return get_centroid(there,here,cap);
    }
    return here;
}
void DFS(int here,int cnt){
	visit[here] = 1;
	if(cnt == 0)
		ans++;
	for(auto there:adj[here]){
		if(!visit[there])
			DFS(there,(cnt+1)%2);
	}
}
int main(){
	int n,a,b;
	scanf("%d",&n);
	for(int i = 0;i<n-1;i++){
		scanf("%d %d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int root=1;
    getSz(root,-1);
    int center=get_centroid(1,-1,sz[root]/2);
	DFS(center,0);
	printf("%lld\n",ans-1);
}