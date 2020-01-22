#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int notPrime[100000];
vector<int> prime;
vector<vector<int> >g;
vector<int>chk;
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
	int tmp = b-a;
	if(tmp<10) return 1;
	else if(tmp<100 && tmp%10 == 0) return 1;
	else if(tmp<1000 && tmp%100 == 0) return 1;
	else if(tmp<10000 && tmp%1000 == 0) return 1;
	return 0;
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
	for(int i = 0;i<siz;i++){
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
			else if(prime[i] == eP) e = i;
		}
		printf("%d\n",bfs(s,e));                   
	}
}
	