#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
#include <tuple>
#include <functional>
using namespace std;
typedef long long ll;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d %d",&n,&m);
		int ans = 0;
		if(n%2 == 0 || m%2 == 0)
			ans = (n*m)/2;
		else
			ans = ((n-1)*m)/2 + (m/2+1);
		printf("%d\n",ans);
	}
}