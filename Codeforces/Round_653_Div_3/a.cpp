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

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int x,y,n;
		scanf("%d %d %d",&x,&y,&n);
		int p = n/x;
		int pp = n%x;
		int k = x*p+y;
		if(k>n)
			k-=x;
		printf("%d\n",k);
	}
}