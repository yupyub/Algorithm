#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
#include <tuple>
#include <climits>
#include <cmath>
#include <map>
#include <functional>
using namespace std;
typedef long long ll;
const int INF = 987654321;
int parent[100001];
int siz[100001];
ll weight[100001];
pair<int,ll> Find(int a,ll tot){
	if(parent[a] == a)
		return make_pair(a,tot);
	return Find(parent[a],tot+weight[a]);
}
void Union(int a,int b,ll w){
	auto aa = Find(a,0);
	auto bb = Find(b,0);
	int pa = aa.first;
	int pb = bb.first;
	if(pa == pb)
		return;
	ll wa = aa.second;
	ll wb = bb.second;
	if(siz[pa]<siz[pb]){
		 weight[pa] = wb-wa-w;
		 parent[pa] = pb;
		 siz[pb] += siz[pa];
	}
	else{
		weight[pb] = wa-wb+w;
		parent[pb] = pa;
		siz[pa] += siz[pb];
	}
}

int main(){
    while(1){
        int N,M;
        scanf("%d %d",&N,&M);
		if(N == 0 && M == 0)
			break;
		for(int i = 1;i<=N;i++){
			parent[i] = i;
			weight[i] = 0;
			siz[i] = 1;
		}
        int a,b,w;
        char c;
        for(int i = 0;i<M;i++){
            scanf("\n%c",&c);
            if(c == '!'){
                scanf("%d %d %d",&a,&b,&w);
				Union(a,b,w);
            }
            else{
                scanf("%d %d",&a,&b);
				auto aa = Find(a,0);
				auto bb = Find(b,0);
				if(aa.first != bb.first)
					printf("UNKNOWN\n");
				else	
					printf("%lld\n",bb.second-aa.second);
            }
        }
    }
}
