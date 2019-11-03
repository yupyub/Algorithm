#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
int main(){
	priority_queue<int> maxq;
	priority_queue<int,vector<int>,greater<int> > minq;
	int n,a,b;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d",&a);
		if(maxq.size()>minq.size())
			minq.push(a);
		else maxq.push(a);
		if(!minq.empty() && minq.top() < maxq.top()){
			a = minq.top();
			b = maxq.top();
			minq.pop();
			maxq.pop();
			minq.push(b);
			maxq.push(a);
		}
		printf("%d\n",maxq.top());
	}
}