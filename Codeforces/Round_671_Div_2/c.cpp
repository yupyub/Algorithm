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
int arr[1001];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,x;
		scanf("%d %d",&n,&x);
		int flag = 0;
		int flag1 = 0;
		int tot = 0;
		for(int i = 0;i<n;i++){
			scanf("%d",&arr[i]);
			if(arr[i] != x)
				flag = 1;
			else
				flag1 = 1;
			
			tot += (arr[i] - x);
		}
		if(flag == 0)
			printf("0\n");
		else if(tot == 0 || flag1)
			printf("1\n");
		else
			printf("2\n");
	}
}