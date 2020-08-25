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
char arr[100001];
int zro[100001];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int x;
		scanf("%s",arr);
		scanf("%d",&x);
		int n = strlen(arr);
		for(int i = 0;i<n;i++)
			zro[i] = 0;
		for(int i = 0;i<n;i++){
			if(arr[i] == '1')
				continue;
			if(i-x>=0)
				zro[i-x] = 1;
			if(i+x<n)
				zro[i+x] = 1;
		}
		int ans = 0;
		for(int i = 0;i<n;i++){
			if(arr[i] == '0')
				continue;
			int flag1 = 0;
			int flag2 = 0;
			if(i-x>=0){
				flag1++;
				if(zro[i-x])
					flag2++;
			}
			if(i+x<n){
				flag1++;
				if(zro[i+x])
					flag2++;
			}
			if(flag1==flag2){
				ans = 1;
				break;
			}
		}
		if(ans)
			printf("-1\n");
		else{
			for(int i = 0;i<n;i++){
				if(zro[i])
					printf("0");
				else
					printf("1");
			}
			printf("\n");
		}
	}
}