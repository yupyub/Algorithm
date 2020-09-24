#pragma GCC optimize("O3") 
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
const int INF = 987654321;
int pSum[3002][3002];
int arr[3001][3001];
int R,C,H,W;
inline int ret(int i,int j,int X){
    return arr[i][j]<= X ? 1 : 0;
}
inline int retSum(int a,int b,int c,int d){
    return pSum[c][d]-pSum[a-1][d]-pSum[c][b-1]+pSum[a-1][b-1];
}
int func(int X){
    for(int i = 1;i<=R;i++){
        for(int j = 1;j<=C;j++){
            pSum[i][j] = pSum[i-1][j] + pSum[i][j-1] - pSum[i-1][j-1] + ret(i,j,X); 
        }
    }
    for(int i = 1;i<=R-H+1;i++){
        for(int j = 1;j<=C-W+1;j++){
            int tmp = retSum(i,j,i+H-1,j+W-1);
            if(tmp>=(H*W)/2+1)
                return 0;
        }
    }
    return 1;
}
int main(){
    scanf("%d %d %d %d",&R,&C,&H,&W);
    for(int i = 1;i<=R;i++)
        for(int j = 1;j<=C;j++)
            scanf("%d",&arr[i][j]);
    int s = 1;
    int e = R*C-(H*W)/2+2;
    int mid;
    int ans = INF;
    while(s<=e){
        mid = (s+e)/2;
        int tmp = func(mid);
        if(tmp){
            s = mid + 1;
        }
        else{
            e = mid - 1;
            ans = min(ans,mid);
        }
    }
    printf("%d\n",ans);
}