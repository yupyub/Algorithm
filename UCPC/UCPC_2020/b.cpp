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
string blk_str[26];
int blk[26][200001];
string arr;
int main(){
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 0;i<k;i++)
		cin >> blk_str[i];
	cin >> arr;
	for(int i = 0;i<k;i++){
		int prev = -1;
		for(int j = 0;j<m;j++){
			if(blk_str[i][j] == 'U')
				prev = j;
			blk[i][j] = prev;
		}
	}
	int s,e;
	s = e = m-1; 
	ll ans = 0;
	for(int i = n-1;i>=0;i--){
		int num = arr[i]-'A';
		if(s != 0)
			s = blk[num][s-1]+1;
		if(i != n-1 && e != -1)
			e = blk[num][e];
		if(e == -1)
			continue;
		ans += (ll)(e-s+1);
	}
	printf("%lld\n",ans);
}