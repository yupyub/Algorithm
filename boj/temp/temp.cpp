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
// Maximum Subarray Problem
// Psum(0) = 0, Psum(i+1) = Psum(i) + Num(i);
// Max_sum(i) = max(0<=k<=i){ Psum(i+1) - Psum(k) }
//            = Psum(i+1) - min(0<=k<=i){ Psum(k) }
// For all i<j, min(0<=k<=i){ Psum(k) } >= min(0<=k<=j){ Psum(k) }
// We should choose Maximum Subarray which length is bigger then M
// Max_sum(i) = Psum(i+1) - min(0<=k<=i-M+1){ Psum(k) } : if(i >= M-1)
//            = 0 : if(i < M-1)
int Psum[100001];
int main(){
    int n,m,a;
    scanf("%d %d",&n,&m);
    Psum[0] = 0;
    for(int i = 1;i<=
	n;i++){
        scanf("%d",&a);
        Psum[i] = Psum[i-1] + a;
    }
    int maxi = -INF;
    int minPsum = 0;
    for(int i = m-1;i<=n;i++){
        maxi = max(maxi,Psum[i] - minPsum);
        minPsum = min(minPsum,Psum[i-m+1]);
    }
    printf("%d\n",maxi);
}
