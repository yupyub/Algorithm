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
typedef long long ll;
ll arr[200000];
int Lidx[200000];
int Ridx[200000];
int main(){
	int n;
	scanf("%d",&n);
	priority_queue<tuple<ll,ll,int>,vector<tuple<ll,ll,int> >, greater<tuple<ll,ll,int> > > pq;
	for(int i = 0;i<n;i++){
		scanf("%lld",&arr[i]);
	}
	if(n==1){
		printf("%lld\n",arr[0]);
		return 0;
	}
	Lidx[0] = n-1;
	Ridx[0] = 1;
	Lidx[n-1] = n-2;
	Ridx[n-1] = 0;
	for(int i = 1;i<n-1;i++){
		Lidx[i] = i-1;
		Ridx[i] = i+1;
	}
	for(int i = 0;i<n;i++){
		pq.push(make_tuple(arr[i],-(arr[Lidx[i]]+arr[Ridx[i]]),i));	
	}
	while(pq.size()>1 && n>3){
		int id = get<2>(pq.top());
		pq.pop();
		if(arr[id] <0)
			continue;
		if(Lidx[id] == id)
			continue;
		if(Ridx[id] == id)
			continue;
		
		int Li = Lidx[id];
		int Ri = Ridx[id];
		//printf("%lld %lld %lld\n",arr[Li],arr[id],arr[Ri]);
		arr[id] = arr[Li] + arr[Ri];
		arr[Li] = arr[Ri] = -1;
		Lidx[id] = Lidx[Li];
		Ridx[id] = Ridx[Ri];
		Ridx[Lidx[id]] = id;
		Lidx[Ridx[id]] = id;
		pq.push(make_tuple(arr[id],-(arr[Lidx[id]]+arr[Ridx[id]]),id));
		n-=2;
	}
	ll num[3];
	int cnt=  0;
	while(!pq.empty()){
		int id = get<2>(pq.top());
		pq.pop();
		if(arr[id] <0)
			continue;
		//printf("%lld ",arr[id]);
		num[cnt++] = arr[id];
	}
	sort(num,num+cnt);
	printf("%lld\n",num[1]+num[2]);
}