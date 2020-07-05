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
		sort(arr,arr+n);
		int ans = 0;
		int i = 0;
		int team = 0;
		while(i<n){
			team++;
			if(team>=arr[i]){
				ans++;
				team = 0;
			}
			i++;
		}
		printf("%d\n",ans);
	
	}
}