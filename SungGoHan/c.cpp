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
ll A[500000];
ll B[500000];
int main(){
	scanf("%d",&N);
	for(int i = 0;i<N;i++){
		scanf("%lld",&A[i]);
	}
	for(int i = 0;i<N;i++){
		scanf("%lld",&B[i]);
	}
	for(int i = 0;i<N;i++){
		int tmp = upper_bound(B+i+1,B+N,A[i]) - B;
		printf("%d ",tmp-i-1);
	}
}