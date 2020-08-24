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
int arr[300000];
int psum[300001];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n);
    for(int i = 0;i<n;i++){
        psum[i+1] = psum[i] + arr[i];
    }
    for(int i = 0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d\n",psum[b] - psum[a-1]);
    }

}