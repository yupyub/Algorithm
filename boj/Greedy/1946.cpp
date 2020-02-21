#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int,int> > v;
priority_queue<int> pq;
int arr[100001];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,a,ans;
		v.clear();
		while(!pq.empty())
			pq.pop();
		scanf("%d",&n);
		ans = n;
		for(int i = 0;i<n;i++){
			scanf("%d %d",&a,&arr[i]);
			v.push_back(make_pair(a,i));
		}
		sort(v.begin(),v.end());
		for(int i = 0;i<n;i++){
			int a = v[i].second;
			if(!pq.empty() && -pq.top()<arr[a])
				ans--;
			pq.push(-arr[a]);
		}
		printf("%d\n",ans);
	}
}
			