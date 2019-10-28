#include <cstdio>
#include <vector>
using namespace std;
int ch[9];
vector<int> v;
void f(int a,int b,int m){
	if(b == m){
		for(int i = 0;i<m;i++)
			printf("%d ",v[i]);
		printf("\n");
		return;
	}
	b++;
	for(int i = 1;i<=a;i++){
		if(ch[i] == 0){
			ch[i] = 1;
			v.push_back(i);
			f(a,b,m);
			ch[i] = 0;
			v.pop_back();
		}
	}
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	f(n,0,m);
}