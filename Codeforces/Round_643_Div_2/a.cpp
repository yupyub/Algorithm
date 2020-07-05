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
int ret_min(ll num){
	int arr[10] = {0,};
	while(num!=0){
		arr[num%10] = 1;
		num/=10;
	}
	for(int i = 0;i<10;i++)
		if(arr[i] == 1)
			return i;
}
int ret_max(ll num){
	int arr[10] = {0,};
	while(num!=0){
		arr[num%10] = 1;
		num/=10;
	}
	for(int i = 9;i>=0;i--)
		if(arr[i] == 1)
			return i;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		ll n,k;
		scanf("%lld %lld",&n,&k);
		k--;
		while(k--){
			int tmp = ret_min(n);
			tmp *= ret_max(n);
			if(tmp == 0)
				break;
			n+=tmp;
		}
		printf("%lld\n",n);
	}
}