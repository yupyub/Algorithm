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
const int MOD = 1000000007;
int cache[10001];
int N,M;
int f(int n){
    int &ret = cache[n];
    if(ret != 0)
        return ret;
    if(n == 0)
        return 1;
    if(n<M)
        return ret = f(n-1);
    return ret = (f(n-1) + f(n-M))%MOD;
}
int main(){
    scanf("%d %d",&N,&M);
    printf("%d\n",f(N));
}