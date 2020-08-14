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
int arr[100001];
int psum[100001];
int dp[100001];
int cnt = 0;
int f(int n){
    // printf("(%d) ",n);
    // if(cnt>10)
    //     return 0;
    // cnt++;
    if(n>N)
        return 0;
    if(dp[n] != -1)
        return dp[n];
    if(n+arr[n]-1>N)
        return 0;
    if(arr[n] == 0){
        int nx = n+1;
        while(nx<=N && arr[nx] == 0){
            nx++;
        }
        int zro = nx-n;
        if(nx<=N && arr[nx] != 0)
        return dp[n] = f(nx)+1;
    }
    else if(psum[n+arr[n]-1]-psum[n-1] == arr[n]){
        return dp[n] = f(n+arr[n])+1;
    }
    else{
        return dp[n] = f(n+1);
    }
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&N);
        psum[0] = 0;
        for(int i = 1;i<=N;i++){
            scanf("%1d",&arr[i]);
            psum[i] = arr[i] + psum[i-1];
            dp[i] = -1;
        }
        printf("%d\n",f(1));
	}
}