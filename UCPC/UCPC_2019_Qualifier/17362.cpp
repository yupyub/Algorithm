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
	int n;
	scanf("%d",&n);
	int ans;
	if(n < 2)
		ans = n;
	else{
		ans = (n-2)%8;
	switch(ans){
		case 0:
			ans = 2;
			break;
		case 1:
			ans = 3;
			break;
		case 2:
			ans = 4;
			break;
		case 3:
			ans = 5;
			break;
		case 4:
			ans = 4;
			break;
		case 5:
			ans = 3;
			break;
		case 6:
			ans = 2;
			break;
		case 7:
			ans = 1;
			break;
	}
	}
	printf("%d\n",ans);
}