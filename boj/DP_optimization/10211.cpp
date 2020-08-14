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
// Max_sum(i) = max(0<=k<=i){ Psum(i+1) - Psum(k) }
//            = Psum(i+1) - min(0<=k<=i){ Psum(k) }
// For all i<j, min(0<=k<=i){ Psum(k) } >= min(0<=k<=j){ Psum(k) }
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,a;
		int Psum1 = 0,Psum2 = 0,maxi = -INF;
		scanf("%d",&n);
		for(int i = 0;i<n;i++){
			scanf("%d",&a);
			Psum1 += a;
			maxi = max(maxi,Psum1 - Psum2);
			Psum2 = min(Psum2,Psum1);
		}
		printf("%d\n",maxi);
	}
}