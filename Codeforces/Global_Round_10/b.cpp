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

int arr[200001];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d %d",&n,&m);
		int maxi = -1000000001;
		int mini = 1000000001;
		for(int i = 0;i<n;i++){
			scanf("%d",&arr[i]);
			maxi = max(maxi,arr[i]);
			mini = min(mini,arr[i]);
		}
		if(m%2){
			for(int i = 0;i<n;i++){
				printf("%d ",maxi-arr[i]);
			}
			printf("\n");
		}
		else{
			for(int i = 0;i<n;i++){
				printf("%d ",arr[i]-mini);
			}
			printf("\n");
		}
		
	}
}