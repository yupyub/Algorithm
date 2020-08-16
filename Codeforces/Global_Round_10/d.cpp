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
char arr[200001];
char arr2[200001];
int dp[3][200001];
int f2(int idx){
	int ret = 0;
	if(arr[idx] != 'R')
		ret++;
	if(arr[idx+1] != 'L')
		ret++;
	return ret;
}
int f3(int idx){
	int ret = 0;
	if(arr[idx] != 'R')
		ret++;
	if(arr[idx+2] != 'L')
		ret++;
	return ret;
}
int f4(int idx){
	int ret1 = 0;
	int ret2 = 0;
	if(arr[idx] != 'R')
		ret1++,ret2++;
	if(arr[idx+1] != 'R')
		ret2++;
	else ret1++;
	if(arr[idx+2] != 'L')
		ret2++;
	else ret1++;
	if(arr[idx+3] != 'L')
		ret2++,ret2++;
	//return min(ret1,ret2);
	return ret2;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		scanf("%s",arr);
		dp[0][0] = dp[1][0] = dp[2][0] = 987654321;
		/////
		dp[0][1] = f2(0);
		dp[0][2] = f3(0);
		dp[0][3] = min(f2(2)+dp[0][1],f4(0));
		for(int i = 4;i<n;i++){
			dp[0][i] = min(dp[0][i-2]+f2(i-1),dp[0][i-3]+f3(i-2));
			dp[0][i] = min(dp[0][i],dp[0][i-4]+f4(i-3));
		}
		/////
		strcpy(arr2,arr);
		for(int i = 0;i<n-1;i++){
			arr[i] = arr2[i+1];
		}
		arr[n-1] = arr2[0];
		dp[1][1] = f2(0);
		dp[1][2] = f3(0);
		dp[1][3] = min(f2(2)+dp[1][1],f4(0));
		for(int i = 4;i<n;i++){
			dp[1][i] = min(dp[1][i-2]+f2(i-1),dp[1][i-3]+f3(i-2));
			dp[1][i] = min(dp[1][i],dp[1][i-4]+f4(i-3));
		}
		/////
		strcpy(arr2,arr);
		for(int i = 0;i<n-1;i++){
			arr[i] = arr2[i+1];
		}
		arr[n-1] = arr2[0];
		dp[2][1] = f2(0);
		dp[2][2] = f3(0);
		dp[2][3] = min(f2(2)+dp[2][1],f4(0));
		for(int i = 4;i<n;i++){
			dp[2][i] = min(dp[2][i-2]+f2(i-1),dp[2][i-3]+f3(i-2));
			dp[2][i] = min(dp[2][i],dp[2][i-4]+f4(i-3));
		}
		printf("%d\n",min(min(dp[0][n-1],dp[1][n-1]),dp[2][n-1]));
	}
}