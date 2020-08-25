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
int f(int P,int F,int cntS,int cntW,int S,int W){
	int ans = 0;
	for(int i = 0;i<=cntS;i++){
		int cnt = i;
		int tmpP = P;
		int tmpF = F;
		if(i*S<=tmpP){
			tmpP -= i*S;
			int tmp = tmpP/W > cntW ? cntW : tmpP/W;
			cnt += tmp;
			int tmp1 = tmpF/S > (cntS-i) ? (cntS-i) : tmpF/S;
			tmpF -= tmp1*S;
			cnt += tmp1;
			int tmp2 = tmpF/W > (cntW-tmp) ? (cntW-tmp) : tmpF/W;
			cnt += tmp2;
		}
		else cnt = -1;
		//printf(">> %d %d\n",i,cnt);
		ans = max(ans,cnt);
	}
	return ans;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int P,F,cntS,cntW,S,W;
		scanf("%d %d %d %d %d %d",&P,&F,&cntS,&cntW,&S,&W);
		int ans1,ans2;
		if(S<W)
			ans1 = f(P,F,cntS,cntW,S,W);
		else
			ans1 = f(P,F,cntW,cntS,W,S);
		if(S<W)
			ans2 = f(F,P,cntS,cntW,S,W);
		else
			ans2 = f(F,P,cntW,cntS,W,S);
		printf("%d\n",max(ans1,ans2));
	}
}