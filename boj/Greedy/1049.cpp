#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int n,m;
	int nu1,nu2;
	nu1 = nu2 =987654321;
	scanf("%d %d",&n,&m);
	for(int i = 0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		nu1 = min(nu1,a);
		nu2 = min(nu2,b);
	}
	int ans = 0;
	if(nu1<nu2*6){
		ans += (n/6)*nu1;
		n = n%6;
		if(n*nu2>nu1){
			ans += nu1;
			n = 0;
		}
	}
	ans += n*nu2;	
	printf("%d\n",ans);
}