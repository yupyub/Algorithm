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
int arr[100000];
int v[100000];
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n);
	for(int i = 0;i<n;i++){
		if(i%2)
			v[i] = arr[i/2];
		else
			v[i] = arr[n/2+i/2];
	}

	int ans = 0;
	for(int i = 1;i<n-1;i++){
		if(v[i-1]>v[i] && v[i]<v[i+1])
			ans++;
	}
	printf("%d\n",ans);
	for(int i = 0;i<n;i++){
		printf("%d ",v[i]);
	}
}