#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
int N;
ll cost[100001];
int visit[100001];
vector<pair<int,ll> > tree[100001];
ll f(int n){
	for(auto nx : tree[n]){
		int nxt = nx.first;
		if(!visit[nxt]){
			visit[nxt] = n;
			f(nxt);
		}
	}
	ll tot = 0,ptot = 0;
	for(auto nx : tree[n]){
		int nxt = nx.first;
		int nxc = nx.second;
		if(visit[nxt] != n)
			continue;
		
	}
}
int main(){
	int a,b;
	ll c;
	scanf("%d",&N);
	for(int i = 1;i<N;i++){
		scanf("%d %d %lld",&a,&b,&c);
		tree[a].push_back(make_pair(b,c));
		tree[b].push_back(make_pair(a,c));
	}
	visit[1] = 1;
	printf("%lld",f(1));
}