#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int cache[300][100001];
int arr[300];
int back[300];
int n,tot;
int f(int po,int cp){
	//printf("%d %d\n",po,cp);
	if(po==0) return 0;
	if(cp<=0) return 0;
	int &ret = cache[po][cp];
	if(ret != -1) return ret;
	for(int j = arr[po];j<=cp;j++){
		ret = max(f(po-1,j),f(po-1,j-arr[po])+arr[po]);
	}
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d",&arr[i]);
		tot += arr[i];
	}
	memset(cache,-1,sizeof cache);
	tot/=2;
	for(int i = tot;i<100001;i++){
		printf(">> %d\n",f(n-1,i));
	}
}