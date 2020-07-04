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
int arr[300001];
vector<pair<int,int> >v;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i =0 ;i<n;i++){
			scanf("%d",&arr[i]);
			v.push_back(make_pair(arr[i],i));
		}
		sort(v.begin(),v.end());
		int ans = 0;
		for(int i = 0;i<n;i++){
			int x = v[i].first;
			int pos = v[i].second;
			//printf("__%d %d__\n",x,pos);
			if(pos>n-x){
				ans = 1;
				break;
			}
		}
		if(ans)
			printf("NO\n");
		else
			printf("YES\n");
	}
}