#pragma GCC optimize("O3")
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
const int MAXN = 800010;
int tree[MAXN * 4]; // 4*MAXN
int tree2[MAXN * 4]; // 4*MAXN
void update1(int idx, int v){
	tree[idx]=v;
	while(idx!=1){
		idx/=2;
		tree[idx]=tree[idx*2]+tree[idx*2+1];
	}
}
int tree_sum(int l, int r){
	int ret=0;
	while(l<=r){
		if(l%2==0) l/=2;
		else{
			ret+=tree[l];
			l=l/2+1;
		}
		if(r%2==0){
			ret+=tree[r];
			r=r/2-1;
		} else r/=2;
	}
	return ret;
}
void update2(int idx, int v){
	tree2[idx]=v;
	while(idx!=1){
		idx/=2;
		tree2[idx] = max(tree2[idx*2], tree2[idx*2+1] );
	}
}
int tree_max(int l, int r){
	int ret = -INF;
	while(l<=r){
		if(l%2==0) l/=2;
		else{
			ret = max( ret, tree2[l] );
			l=l/2+1;
		}
		if(r%2==0){
			ret = max( ret, tree2[r] );
			r=r/2-1;
		} else r/=2;
	}
	return ret;
}

int main(){
	int n,m;
	scanf("%d %d", &n, &m);
	vector<int> tmp;
	vector<tuple<int,int,int> > card;
	vector<tuple<int,int> > quary;
	vector<int> num;
	int a,b;
	for(int i = 0;i<n;i++){
		scanf("%d %d",&a,&b);
		card.push_back(make_tuple(a,b,0));
		tmp.push_back(a);
		tmp.push_back(b);
	}
	for(int j = 1;j<=m;j++){
		scanf("%d",&a);
		quary.push_back(make_tuple(a,j));
		tmp.push_back(a);
	}
	sort(tmp.begin(),tmp.end());
	for(int i : tmp){
		if(num.empty())
			num.push_back(i);
		else if(num[num.size()-1] != i)
			num.push_back(i);
	}
	int t = 1;
	n = num.size();
	while(n>t)
		t*=2;
	////////////////////////////////
	for(auto a : quary){
		int k = get<0>(a);
		int idx = get<1>(a);
		int tree_idx = lower_bound(num.begin(),num.end(),k)-num.begin();
		tree2[t+tree_idx]=max(tree2[t+tree_idx],idx);
	}
	for(int i=t; i<2*t; i++)
		update2(i, tree2[i]);
	for(int i = 0;i<card.size();i++){
		int min_idx = lower_bound(num.begin(),num.end(),min(get<0>(card[i]),get<1>(card[i])))-num.begin();
		int max_idx = lower_bound(num.begin(),num.end(),max(get<0>(card[i]),get<1>(card[i])))-num.begin();
		int last_idx = tree_max(t+min_idx,t+max_idx-1);
		card[i] = make_tuple(last_idx == -INF ? 0 : last_idx,get<0>(card[i]),get<1>(card[i]));
	}
	////////////////////////////////
	sort(card.begin(),card.end());
	for(auto a : quary){
		int k = get<0>(a);
		int idx = get<1>(a);
		int tree_idx = lower_bound(num.begin(),num.end(),k)-num.begin();
		tree[t+tree_idx]++;
	}
	for(int i = t;i<2*t;i++)
		update1(i,tree[i]);
	ll ans = 0;
	int del_idx = 1;
	for(int i = 0;i<card.size();i++){
		int idx = get<0>(card[i]);
		int front_val = get<1>(card[i]);
		int back_val = get<2>(card[i]);
		int max_idx = lower_bound(num.begin(),num.end(),max(front_val,back_val))-num.begin();
		if(idx != 0){
		for(int i = del_idx;i<=idx;i++){
			int tree_idx = lower_bound(num.begin(),num.end(),get<0>(quary[i-1]))-num.begin();
			tree[t+tree_idx]--;
			update1(t+tree_idx,tree[t+tree_idx]);
		}
		del_idx = idx+1;
		}
		//////
		int cnt = tree_sum(t+max_idx,t+num.size()-1);
		if(idx == 0){
			if(cnt%2)
				ans += back_val;
			else
				ans += front_val;
		}
		else{
			if(cnt%2)
				ans += (ll)min(front_val,back_val);
			else
				ans += (ll)max(front_val,back_val);
		}
	}	
	printf("%lld\n",ans);
}
