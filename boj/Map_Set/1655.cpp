#include <cstdio>
#include <set>
using namespace std;
int main(){
	int n,a;
	multiset<int> ms;
	multiset<int>::iterator iter = ms.begin();
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d",&a);
		ms.insert(a);
		iter = ms.begin();
		advance(iter,i/2);
		printf("%d\n",*iter);
	}
}