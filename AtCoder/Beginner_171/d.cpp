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
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int num[100001];

int main(){
    int n,q;
    scanf("%d",&n);
    ll ans = 0;
    int a,b;
    for(int i = 0;i<n;i++){
        scanf("%d",&a);
        num[a]++;
        ans += a;
    }
    scanf("%d",&q);
    for(int i = 0;i<q;i++){
        scanf("%d %d",&a,&b);
        ans -= (ll)num[a]*a;
        ans += (ll)num[a]*b;
        num[b] += num[a];
        num[a] = 0;
        printf("%lld\n",ans);
    }
}