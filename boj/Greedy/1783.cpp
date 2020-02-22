#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int n,m,ans;
	scanf("%d %d",&n,&m);
	if(n == 1)
		ans = 1;
	else if(n == 2)
		ans = min(4,(m+1)/2);
	else{
		if(m<5)
			ans = m;
		else if(m == 5)
			ans = 4;
		else 
			ans = m-2;
	}
	printf("%d\n",ans);
}