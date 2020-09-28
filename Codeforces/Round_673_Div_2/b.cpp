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
typedef pair<int,int> ii;
const int INF = 987654321;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
pair<int,int> arr[100000];
int ans[100000];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d %d",&n,&m);
		for(int i = 0;i<n;i++){
			scanf("%d",&arr[i].first);
			arr[i].second = i;
			ans[i] = 0;
		}
		sort(arr,arr+n);
		for(int i = 0;i<n;i++){
			ans[i] = 
		}
	}
}