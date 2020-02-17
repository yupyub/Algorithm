#include <cstdio>
int arr[10000];
void f(int l,int r){
	if(l>r) return;
	int nw = l;
	int s = l,e = r;
	while(arr[s]>=arr[nw]) s++;
	while(arr[e]>arr[nw]) e--;
	f(s,e);
	f(e+1,r);
	printf("%d\n",arr[nw]);
}
int main(){
	int n = 0;
	while(scanf("%d",&arr[n++]) != EOF)
		if(arr[n-1] == -1) break;
	f(0,n-2);
}