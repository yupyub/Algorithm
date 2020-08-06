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
typedef vector<vector<int> > vvi;
const int INF = 987654321;
const int MOD = 1000000007;
ll mat[105][105];
ll mmat[105][105];
void mulmat(ll a[105][105], ll b[105][105],int d) {
   ll c[105][105];
   memset(c, 0, sizeof(c));
   for (int i = 0; i < d; i++)
      for (int j = 0; j < d; j++)
         for (int k = 0; k < d; k++)
            c[i][j] = (c[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
   for (int i = 0; i < d; i++)
      for (int j = 0; j < d; j++)
         a[i][j] = c[i][j] % MOD;
}

int main(){
    ll N;
    int M;
    scanf("%lld %d",&N,&M);
    vvi arr = vvi(M+1,vector<int>(M+1));
    for(int i = 0;i<M+1;i++)
        mmat[i][i] = 1;
    for(int i = 0;i<M;i++)
        mat[i][i+1] = 1;
    mat[M][1] = mat[M][M] = 1;
    while(N){
        if(N%2)
            mulmat(mmat,mat,M+1);
        mulmat(mat,mat,M+1);
        N/=2;
    }
    printf("%lld\n",mmat[M][M]);
}