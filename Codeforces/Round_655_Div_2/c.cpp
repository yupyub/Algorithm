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
int arr[200000];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i = 0;i<n;i++)
			scanf("%d",&arr[i]);
		if(is_sorted(arr,arr+n)){
			printf("0\n");
			continue;
		}
		int flag1 = 0;
		int flag2 = 0;
		int ans = 1;
		for(int i = 0;i<n;i++){
			if(arr[i] != i+1){
				if(flag1 == 0){
					flag1 = 1;
					if(flag2)
						ans = 2;
				}
			}
			else{
				if(flag1){
					flag2 = 1;
					flag1 = 0;
				}
			}
		}
		printf("%d\n",ans);
	}
}