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
pair<int,int> arr[50001];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int a;
		for(int i = 0;i<n;i++){
			scanf("%d",&a);
			arr[i] = make_pair(a,i+1);
		}
		sort(arr,arr+n);
		if(((ll)arr[0].first+(ll)arr[1].first)>(ll)arr[n-1].first)
			printf("-1\n");
		else{
			printf("%d %d %d\n",arr[0].second,arr[1].second,arr[n-1].second);
		}
	}
}