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
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int k = 2;
		vector<int> v;	
		while(n!=1){
			if(k*k>n){
				v.push_back(n);
				break;
			}
			if(n%k == 0){
				v.push_back(k);
				n /=k;
			}
			else
				k++;
		}
		int num[2] = {1,1};
		for(int i = v.size()-1;i>0;i--){
			num[0] *= v[i];
			num[1] *= v[i];
		}
		int a,b;
		a = v[0]-1;
		b = 1;
		num[0] *= a;
		num[1] *= b;
		if(num[0]>num[1])
			swap(num[0], num[1]);
		printf("%d %d\n",num[0],num[1]);
	}
}