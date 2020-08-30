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
typedef pair<int,int> ii;
const int INF = 987654321;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int N,M;
ll arr[100000];
int main(){
	ll n;
	scanf("%lld",&n);
	for(ll i = 0;i<n;i++)
		scanf("%lld",&arr[i]);
	printf("1 1\n");
	printf("%lld\n",-arr[0]);
	if(n == 1){
		printf("1 1\n");
		printf("0\n");
		printf("1 1\n");
		printf("0\n");
		return 0;
	}
	printf("2 %lld\n",n);
	for(ll i = 1;i<n;i++){
		ll tot = 0;
		tot = (n-1) * (arr[i]%n);
		arr[i] += tot;
		printf("%lld ",tot);
	}
	printf("\n");
	printf("1 %lld\n0 ",n);
	for(int i = 1;i<n;i++){
		printf("%lld ",-arr[i]);
	}
	printf("\n");
}