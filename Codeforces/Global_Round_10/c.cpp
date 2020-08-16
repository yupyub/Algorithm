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
int arr[200001];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i = 0;i<n;i++){
			scanf("%d",&arr[i]);
		}
		ll ans = 0;
		for(int i = 1;i<n;i++){
			if(arr[i-1]>arr[i]){
				ans += (ll)(arr[i-1]-arr[i]);
			}
		}
		printf("%lld\n",ans);
	}
}