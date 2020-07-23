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
int main(){
    int arr[1000];
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n);
    int ans = 0;
    for(int i = 0;i<k;i++){
        ans += arr[i];
    }
    printf("%d\n",ans);
}