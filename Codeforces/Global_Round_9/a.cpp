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
		int n;
		scanf("%d",&n);
		ll arr[100];
		for(int i = 0;i<n;i++)
			scanf("%lld",&arr[i]);
		vector<pair<ll,int> > v;
		for(int i = 0;i<n;i++){
			arr[i] = abs(arr[i]);
			v.push_back(make_pair(arr[i],i));
		}
		int A = 0;
		int B = 0;
		for(int i = 0;i<n-1;i++){
			if(arr[i+1]-arr[i]>0)
				A++;
			else if(arr[i+1] == arr[i]){
				A++;
				B++;
			}
			else
				B++;
		}
		sort(v.begin(),v.end());
		int i = n-1;
		while((A<(n-1)/2 || B<(n-1)/2) && i >= 0){
			arr[v[i].second] = -arr[v[i].second];
			i--;
			A = B = 0;
			for(int i = 0;i<n-1;i++){
				if(arr[i+1]-arr[i]>0)
					A++;
				else if(arr[i+1] == arr[i]){
					A++;
					B++;
				}
				else
					B++;
			}
		}
		for(int i = 0;i<n;i++){
			printf("%lld ",arr[i]);
		}
		printf("\n");
	}
}