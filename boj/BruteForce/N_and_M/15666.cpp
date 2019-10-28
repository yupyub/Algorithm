#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int arr[9];
vector<int> v,tmp;
set<vector<int> > s;
void f(int a,int b,int m){
	if(b == m){
		for(int i = 0;i<m-1;i++)
			if(arr[v[i]]>arr[v[i+1]]) return;
		tmp.clear();
		for(int i = 0;i<m;i++)
			tmp.push_back(arr[v[i]]);
		s.insert(tmp);
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
	set<vector<int> >::iterator iter;
	for(iter = s.begin();iter != s.end();iter++){
		for(int i = 0;i<(*iter).size();i++){
			printf("%d ",(*iter)[i]);
		}
		printf("\n");
	}
}