#include <cstdio>
#include <vector>
using namespace std;
vector<int> v;
void f(int a,int b,int m){
	if(b == m){
		for(int i = 0;i<m-1;i++)
			if(v[i]>v[i+1]) return;
		for(int i = 0;i<m;i++)
			printf("%d ",v[i]);
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
	f(n,0,m);
}