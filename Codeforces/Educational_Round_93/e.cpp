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
#include <set>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = 987654321;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int N,M;
set<pair<int,int>,greater<pair<int,int> > > s;
int main(){
	scanf("%d",&N);
	int a,b;
	int one = 0;
	ll tot = 0;
	ll sumtot = 0;
	for(int i = 0;i<N;i++){
		scanf("%d %d",&a,&b);
		if(b>0){
			s.insert(make_pair(b,a));
			tot += (ll)b;
			one += a;
		}
		else{
			s.erase(s.find(make_pair(-b,a)));
			tot += (ll)b;
			one -= a;
		}
		set<pair<int,int> >:: iterator iter;
		int cnt = 0;
		sumtot = 0;
		int zro = INF;
		for(iter = s.begin(),cnt = 0;cnt<one && iter!=s.end();iter++,cnt++){
			if(iter == s.begin() && (*iter).second == 1){
				cnt--;
				//zro = (*iter).first;
			}
			else
				sumtot += (ll)((*iter).first);
		}
		// if(cnt<one && zro != INF)
		// 	sumtot += (ll)zro;
		printf("%lld\n",tot+sumtot);
	}


}