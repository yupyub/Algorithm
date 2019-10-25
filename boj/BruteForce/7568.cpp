#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,int> > v;
int ans[50];
int main(){
	int n,a,b;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d %d",&a,&b);
		v.push_back(make_pair(a,b));
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(v[i].first<v[j].first && v[i].second<v[j].second)
				ans[i]++;
		}
	}
	for(int i = 0;i<n;i++){
		printf("%d ",ans[i]+1);
	}
}
