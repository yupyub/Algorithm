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
const ll MOD = 1000000009;
ll A[1001];
ll B[1001];
ll dp[11][1001][1001];
ll Psum[11][1001][1001];
int main(){
    int N,M,K;
    scanf("%d %d %d",&N,&M,&K);
    for(int i = 0;i<N;i++)
        scanf("%lld",&A[i]);
    for(int j = 0;j<M;j++)
        scanf("%lld",&B[j]);
    sort(A,A+N);
    sort(B,B+M);
    for(int k = 0;k<K;k++){
        for(int i = 0;i<N;i++)
            for(int j = 0;j<M;j++)
                if(A[i]>B[j])
                    dp[k][i][j] = k == 0 ? 1 : Psum[k-1][i][j];
        for(int i = 1;i<=N;i++)
            for(int j = 1;j<=M;j++)
                Psum[k][i][j] = (Psum[k][i][j-1]+Psum[k][i-1][j] - Psum[k][i-1][j-1]+dp[k][i-1][j-1]+MOD)%MOD;
    }
    printf("%lld\n",Psum[K-1][N][M]);
}