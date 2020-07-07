#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
#include <tuple>
#include <functional>
using namespace std;
typedef long long ll;
int main(){
	int t;
	cin >> t;
	while(t--){
		ll a,b,c,d,ans;
		cin >> a >> b >> c >> d;
		ans = (c-a)*(d-b)+1;
		cout<<ans<<endl;
		
	}
}