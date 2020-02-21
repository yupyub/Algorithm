#include <cstdio>
#include <algorithm>
using namespace std;
int arr[510];
int main(){
	int n,m,k,num = 1;
	scanf("%d%d%d",&n,&m,&k);
	if(m*k<n || m+k-1>n){
		printf("-1\n");
		return 0;
	}
	int idx = 0,tmp;
	for(int i = 1;i<=m;i++){
		tmp = min(idx+k,n-m+i);
		for(int j = tmp-1;j>=idx;j--){
			arr[j] = num++;
		}
		idx = tmp;
	}
	for(int i = 0;i<n;i++)
		printf("%d ",arr[i]);
}