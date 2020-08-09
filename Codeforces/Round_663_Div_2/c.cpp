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
const ll MOD = 1000000007LL;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int N,M;

int main(){
    scanf("%d",&N);
    ll a = 1;
    ll b = 1;
    for(int i = 1;i<=N;i++)
        a = (a*i)%MOD;
    for(int i = 1;i<N;i++)
        b = (b*2)%MOD;
    ll ans = (MOD+a-b)%MOD;
    printf("%lld\n",ans);
}