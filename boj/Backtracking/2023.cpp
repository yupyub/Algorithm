#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> ans;
int is_prime(int num){
	if(num == 1)
		return 0;
	int N = sqrt(num);
	int i = 2;
	while(i<=N){
		if(num%i == 0) 
			return 0;
		i++;
	}
	return 1;
}
void f(int mxn,int n,int num){
	if(mxn == n){
		ans.push_back(num);
		return;
	}
	for(int i = 1;i<10;i++){
		if(is_prime(num*10+i))
			f(mxn,n+1,num*10+i);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	f(n,0,0);
	sort(ans.begin(),ans.end());
	for(int i : ans)
		printf("%d\n",i);
}