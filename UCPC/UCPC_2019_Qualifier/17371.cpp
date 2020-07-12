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
#include <functional>
using namespace std;
typedef long long ll;
pair<ll,ll> arr[10000];
ll dist(int i,int j){
	ll sum1 = arr[i].first-arr[j].first;
	ll sum2 = arr[i].second-arr[j].second;
	return sum1*sum1 + sum2*sum2;
}
int main(){
	int n;
	cin >> n;
	for(int i = 0;i<n;i++)
		cin >> arr[i].first >> arr[i].second;
	ll minsum = LLONG_MAX;
	int idx = 0;
	for(int i = 0;i<n;i++){
		ll maxi = -1;
		for(int j = 0;j<n;j++){
			if(i == j)
				continue;
			maxi = max(maxi,dist(i,j));
		}
		if(minsum > maxi){
			minsum = maxi;
			idx = i;
		}
	}
	cout << arr[idx].first << " " << arr[idx].second << endl;
}