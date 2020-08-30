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
int plank[100001];
int Four = 0;
int Two = 0;
void addP(int x){
	if(plank[x]%2 == 1)
		Two++;
	if(plank[x]%4 == 3)
		Four++;
	plank[x]++;
}
void subP(int x){
	if(plank[x] >= 2 && plank[x]%2 == 0)
		Two--;
	if(plank[x] >= 4 && plank[x]%4 == 0)
		Four--;
	plank[x]--;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		int x;
		scanf("%d",&x);
		addP(x);
	}
	scanf("%d",&n);
	char c;
	int d;
	for(int i = 0;i<n;i++){
		scanf("\n%c %d",&c,&d);
		if(c == '+')
			addP(d);
		else
			subP(d);
		//printf("%d %d\n",Four,Two);
		if(Four>1)
			printf("YES\n");
		else if(Four>0 && (Two-Four*2)>1)
			printf("YES\n");
		else
			printf("NO\n");
	}
}