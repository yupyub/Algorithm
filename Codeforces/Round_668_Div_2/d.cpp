#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
#include <tuple>
#include <climits>
#include <cmath>
#include <map>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = 987654321;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int N,M;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		priority_queue<int> pq;
		int n,a;
		scanf("%d",&n);
		for(int i = 0;i<n;i++){
			scanf("%d",&a);
			pq.push(a);
		}
		int ans = 0;
		while(!pq.empty()){
			int n1 = pq.top();
			pq.pop();
			ans = (ans+1)%2;
			if(pq.empty())
				break;
			int n2 = pq.top();
			pq.pop();
			ans = (ans+1)%2;
			n1--;
			n2--;
			if(n1 != 0)
				pq.push(n1);
			if(n2 != 0)
				pq.push(n2);
		}
		if(ans)
			printf("T\n");
		else
			printf("HL\n");
	}


}