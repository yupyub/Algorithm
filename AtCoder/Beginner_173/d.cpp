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
int arr[200000];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
        scanf("%d",&arr[i]);
    sort(arr,arr+n);
    ll ans = 0;
    for(int i = 0;i<n;i++){
        ans += (ll)arr[n-(i/2)-1];
    }
    printf("%lld\n",ans-arr[n-1]);

}