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
char str[1000][1001];
int alp[30];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		for(int i = 0;i<26;i++)
			alp[i] = 0;
		int n;
		scanf("%d",&n);
		for(int i = 0;i<n;i++){
			scanf("%s",str[i]);
		}
		for(int i = 0;i<n;i++){
			int l = strlen(str[i]);
			for(int j = 0;j<l;j++){
				alp[str[i][j]-'a']++;
			}
		}
		int ans = 0;
		for(int i = 0;i<26;i++){
			if(alp[i] == 0)
				continue;
			if(alp[i]%n != 0){
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