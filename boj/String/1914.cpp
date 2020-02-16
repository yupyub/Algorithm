#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
string dp[101];
void f(int a,int b,int c,int n){
	if(n == 1){
		printf("%d %d\n",a,c);
		return;
	}
	f(a,c,b,n-1);
	f(a,b,c,1);
	f(b,a,c,n-1);
}
string pl(string s){
	int l = s.length();
	string ret = "";
	int a,b = 1;
	for(int i = l-1;i>=0;i--){
		a = ((int)(s[i]-'0'))*2 + b;
		b = a/10;
		a %= 10;
		ret += (char)(a+'0');
	}
	if(b != 0) ret += (char)(b+'0');
	reverse(ret.begin(),ret.end());
	return ret;
}
int main(){
	int n;
	scanf("%d",&n);
	dp[1] = "1";
	for(int i = 2;i<=n;i++)
		dp[i] = pl(dp[i-1]);
	printf("%s\n",dp[n].c_str());
	if(n<=20)
		f(1,2,3,n);
	return 0;
}