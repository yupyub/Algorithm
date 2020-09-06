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
char arr[300001];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d %d",&n,&k);
		scanf("%s",arr);
		int num_0 = 0;
		int num_1 = 0;
		for(int i = 0;i<k;i++){
			if(arr[i] == '0')
				num_0++;
			else if(arr[i] == '1')
				num_1++;
		}
		if(num_0>k/2 || num_1>k/2){
			printf("NO\n");
			continue;
		}
		int ans = 0;
		for(int i = k;i<n;i++){
			if(arr[i] == '?'){
				arr[i] = arr[i-k];
			}
			else if(arr[i] == '0'){
				if(arr[i-k] == '1'){
					ans = 1;
					break;
				}
				else if(arr[i-k] == '?')
					num_0++;
			}
			else{
				if(arr[i-k] == '0'){
					ans = 1;
					break;
				}
				else if(arr[i-k] == '?')
					num_1++;
			}
			//printf("%d : %d %d\n",i,num_0,num_1);
			if(num_0>k/2 || num_1>k/2){
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