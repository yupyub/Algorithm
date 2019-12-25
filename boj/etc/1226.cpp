#include <cstdio>
#include <algorithm>
using namespace std;
int cache[300][100001];
int arr[300];
int back[300];
int n,tot;
int f(int po,int cp){
	if(cp>tot) return;
	if(cache[po][cp] != 0) return cache[po][cp];
	int &ret = cache[po][cp];
	for(int i = po+1;i<n;i++){
		cache[po][cp] = 
			///////////////////////////////////////////////
}
int main(){
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d",&arr[i]);
		tot += arr[i];
	}
	tot/=2;
	f(0,0);
}