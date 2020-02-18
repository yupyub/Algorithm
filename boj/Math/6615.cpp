#include <cstdio>
#include <stack>
using namespace std;
typedef long long ll;
stack<ll> s1,s2;
int main(){
	while(1){
		ll n,m,a,b;
		scanf("%lld %lld",&n,&m);
		if(n == 0 && m == 0) 
			break;
		a = n;
		b = m;
		while(!s1.empty())
			s1.pop();
		while(!s2.empty())
			s2.pop();
		s1.push(n);
		s2.push(m);
		while(a!=1){
			if(a%2)
				a = a*3+1;
			else
				a = a/2;
			s1.push(a);
		}
		while(b!=1){
			if(b%2)
				b = b*3+1;
			else
				b = b/2;
			s2.push(b);
		}
		int st1 = s1.size();
		int st2 = s2.size();
		ll ans;
		while(!s1.empty() && !s2.empty() && s1.top() == s2.top()){
			ans = s1.top();
			s1.pop();
			s2.pop();
			st1--;
			st2--;
		}
		printf("%lld needs %d steps, %lld needs %d steps, they meet at %lld\n",n,st1,m,st2,ans);
	}
}