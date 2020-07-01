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
int arr[200001];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		vector<int> v;
		scanf("%d %d",&n,&k);
		for(int i = 0;i<n;i++){
			scanf("%d",&arr[i]);
			v.push_back(k-(arr[i]%k));
		}
		sort(v.begin(),v.end());
		int i = 0;
		int ans = 0;
		int x = v[i];
		if(v[i] != k)
			ans += x +1;
		i++;
		x++;
		for(;i<n;){
			if(v[i] == k){
				i++;
				continue;
			}
			while(v[i]<x){
				v[i] += k;
				v.push_back(v[i]);
				i++;
				n++;
				continue;
			}
			ans += v[i]-x+1;
			x = v[i]+1;
			i++;
			
		}
		printf("%d\n",ans);
	}	
}