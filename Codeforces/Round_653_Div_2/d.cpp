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
int arr[330][330];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d %d",&n,&k);
		for(int i = 0;i<n;i++)
			for(int j = 0;j<n;j++)
				arr[i][j] = 0;
		int x = 0;
		int i = 0;
		int j = 0;
		while(x<k){
			if(i==n)
				i = 0;
			if(j==n)
				j = 0;
			if(arr[i][j] == 1)
				i++;
			arr[i][j] = 1;
			i++;
			j++;
			x++;
		}
		int minR = 987654321,maxR = 0;
		int minC = 987654321,maxC = 0;
		for(int i = 0;i<n;i++){
			int tmpR = 0;
			for(int j = 0;j<n;j++){
				tmpR += arr[i][j];
			}
			minR = min(minR,tmpR);
			maxR = max(maxR,tmpR);
		}
		for(int i = 0;i<n;i++){
			int tmpC = 0;
			for(int j = 0;j<n;j++){
				tmpC += arr[j][i];
			}
			minC = min(minC,tmpC);
			maxC = max(maxC,tmpC);
		}
		int ans = 0;
		ans += (maxR-minR)*(maxR-minR);
		ans += (maxC-minC)*(maxC-minC);
		printf("%d\n",ans);
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				printf("%d",arr[i][j]);
			}
			printf("\n");
		}
	}
}