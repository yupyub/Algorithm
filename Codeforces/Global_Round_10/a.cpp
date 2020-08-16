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
		int n;
		scanf("%d",&n);
		for(int i = 0;i<n;i++){
			scanf("%d",&arr[i]);
		}
		int val = arr[0];
		int ans = 0;
		for(int i = 1;i<n;i++){
			if(arr[i] != val){
				ans = 1;
				break;
			}
		}
		if(ans == 1){
			printf("1\n");
		}
		else{
			printf("%d\n",n);
		}
	}
}