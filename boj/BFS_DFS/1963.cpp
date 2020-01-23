#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int notPrime[100000];
vector<int> prime;
vector<vector<int> >g;
vector<int>chk;
int back[100000];
void checkPrime(){
	notPrime[1] = 1;
	for(int i = 2;i*i<10000;i++){ // 9999까지 소수를 찾는다
		if(!notPrime[i]){
			for(int j = i*i;j<10000;j+=i){
				notPrime[j] = 1;
			}
		}
	}
}
int similar(int a,int b){
	int cnt = 0;
	for(int i = 0;i<4;i++){
		if(a%10 != b%10) cnt++;
		a/=10;
		b/=10;
	}
	if(cnt == 1) return 1;
	else return 0;
}
int bfs(int s,int e){
	if(s == e)
		return 0;
	queue<pair<int,int> >q;
	chk[s] = 1;
	q.push(make_pair(s,0));
	while(!q.empty()){
		int n = q.front().first;
		int cnt = q.front().second;
		q.pop();
		for(int nx : g[n]){
			if(nx == e) return cnt+1;
			if(chk[nx] == 1) continue;
			chk[nx] = 1;
			q.push(make_pair(nx,cnt+1));
		}
	}
	return -1;
}		
int main(){
	checkPrime();
	for(int i = 1000;i<10000;i++)
		if(!notPrime[i]) prime.push_back(i);
	int siz = prime.size();
	g.clear();
	g.resize(siz);
	for(int i = 0;i<siz-1;i++){
		for(int j = i+1;j<siz;j++){
			if(similar(prime[i],prime[j])){
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}
	int T,s,e,sP,eP;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&sP,&eP);
		chk.clear();
		chk.resize(siz);
		for(int i = 0;i<siz;i++){
			if(prime[i] == sP) s = i;
			if(prime[i] == eP) e = i;
		}
		int ans = bfs(s,e);
		if(ans == -1) printf("Impossible\n");
		else printf("%d\n",ans);
	}
}