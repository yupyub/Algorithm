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
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		ll tot = 0;
		ll ans = 0;
		for(int i = 0;i<n;i++){
			scanf("%lld",&arr[i]);
			tot += arr[i];
			if(tot<0){
				ans -= tot;
				tot = 0;
			}
		}
		printf("%lld\n",ans);
	}
}