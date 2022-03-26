#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int N;
		long long num;
		scanf("%d",&N);
		priority_queue<long long> pq;
		for(int i = 0;i<N;i++){
			scanf("%lld",&num);
			pq.push(-num);
		}
		long long ans = 1;
		while(pq.size() > 1){
			long long a = -pq.top();
			pq.pop();
			long long b = -pq.top();
			pq.pop();
			ans = (ans * ((a * b)%1000000007))%1000000007;
			pq.push(-(a*b));
		}
		printf("%lld\n",ans);
	}
	return 0;
}
