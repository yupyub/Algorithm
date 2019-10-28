#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int arr[9];
vector<int> v;
void f(int a,int b,int m){
	if(b == m){
		for(int i = 0;i<m;i++)
			printf("%d ",arr[v[i]]);
		printf("\n");
		return;
	}
	b++;
	for(int i = 1;i<=a;i++){
			v.push_back(i);
			f(a,b,m);
			v.pop_back();
	}
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 1;i<=n;i++)
		scanf("%d",&arr[i]);
	sort(arr+1,arr+n+1);
	f(n,0,m);
}