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
ll ans = 0;
void f(int n){
	ll tot = 0,ptot = 0;
	ll tmp = 0;
	for(auto nx : tree[n]){
		int nxt = nx.first;
		ll nxc = nx.second;
		if(!visit[nxt]){
			visit[nxt] = 1;
			f(nxt);
			tmp = ((cost[nxt]+1)*nxc)%MOD;
			tot = (tot + tmp)%MOD;
			ptot = (ptot + tmp*tmp)%MOD;
		}
	}
	cost[n] = tot;
	tmp = tot*tot-ptot;
	//(ab+ac+ad+bc+bd+cd) = ((a+b+c+d)^2-(a^2+b^2+c^2+d^2))/2 이용 O(k^2) 을 O(k)로 단축
	if(tmp%2)
		tmp = ((tmp+MOD)/2)%MOD;
	else
		tmp = tmp/2;
	ans =(((tmp+cost[n])%MOD)+ans)%MOD;
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
	f(1);
	printf("%lld",ans);
}