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

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		char arr[10000];
		scanf("%d",&n);
		scanf("%s",arr);
		int Rodd = 0;
		int Beven = 0;
		for(int i = 0;i<n;i++){
			if(i%2 && arr[i]%2 == 0){
				Beven = 1;
			}
			if(i%2 == 0 && arr[i]%2){
				Rodd = 1;
			}
		}
		if(n%2){
			if(Rodd)
				printf("1\n");
			else
				printf("2\n");
			
		}
		else{
			if(Beven)
				printf("2\n");
			else
				printf("1\n");
		}
	}
}