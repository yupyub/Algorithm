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
char arr[101][101];


int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&N,&M);
        for(int i = 0;i<N;i++)
            scanf("%s",arr[i]);
        int ans = 0;
        for(int i = 0;i<N;i++){
            if(arr[i][M-1] == 'R')
                ans++;
        }
        for(int j = 0;j<M;j++){
            if(arr[N-1][j] == 'D')
                ans++;
        }
        printf("%d\n",ans);
    }
}