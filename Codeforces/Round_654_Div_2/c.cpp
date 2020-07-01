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
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		ll a,b,n,m;
		scanf("%lld %lld %lld %lld",&a,&b,&n,&m);
		if(a+b < n+m){
			printf("No\n");
			continue;
		}
		ll minC = min(a,b);
		ll maxC = max(a,b);
		/*
		if(maxC-minC >= n && minC<m){
			printf("No\n");
			continue;
		}*/
		if(minC < m){
			printf("No\n");
			continue;
		}
		printf("Yes\n");
	}
}