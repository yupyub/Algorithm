// MO's Algorithm
// 그냥 시간복잡도는 O(N^2) 이지만 
// Sqrt decomposition 기법을 이용해 O(Q(N+Q)sqrt(N))으로 최적화 (Q:query수)
#include <cstdio>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cmath>
using namespace std;
typedef long long ll;
ll add_range(ll arr[],int count[],ll ret,int i){
	ret -= (ll)count[arr[i]]*(ll)count[arr[i]]*arr[i];
	count[arr[i]]++;
	ret += (ll)count[arr[i]]*(ll)count[arr[i]]*arr[i];
	return ret;
}
ll del_range(ll arr[],int count[],ll ret,int i){
	ret -= (ll)count[arr[i]]*(ll)count[arr[i]]*arr[i];
	count[arr[i]]--;
	ret += (ll)count[arr[i]]*(ll)count[arr[i]]*arr[i];
	return ret;	
}
ll init(ll arr[],int count[], ll ret,pair<int,int> qu){
	for(int i = qu.first;i<=qu.second;i++)
		ret = add_range(arr,count,ret,i);
	return ret;
}
ll update(ll arr[],int count[], ll ret,pair<int,int> qu1,pair<int,int>qu2){
	for(int i = qu1.first-1;i>=qu2.first;i--)
		ret = add_range(arr,count,ret,i);
	for(int i = qu1.first;i<qu2.first;i++)
		ret = del_range(arr,count,ret,i);
	for(int i = qu1.second+1;i<=qu2.second;i++)
		ret = add_range(arr,count,ret,i);
	for(int i = qu1.second;i>qu2.second;i--)
		ret = del_range(arr,count,ret,i);
	return ret;
}
int main(){
	int arr_size,query_size,qu1,qu2;
	ll ret = 0;
	ll arr[100000] = {0,};
	int count[1000001] = {0,};
	scanf("%d %d",&arr_size,&query_size);
	for(int i = 0;i<arr_size;i++)
		scanf("%lld",&arr[i]);
	vector<pair<int,int> > query;
	vector<tuple<int,int,int> >query_sort;
	vector<ll>ans;
	ans.resize(query_size);
	int sqrt_n = sqrt(arr_size);
	for(int i = 0;i<query_size;i++){
		scanf("%d %d",&qu1,&qu2);
		qu1--,qu2--;
		query.push_back(make_pair(qu1,qu2));
		query_sort.push_back(make_tuple(qu1/sqrt_n,qu2,i));
	}
	sort(query_sort.begin(),query_sort.end());
	ret = init(arr,count,ret,query[get<2>(query_sort[0])]);
	ans[get<2>(query_sort[0])] = ret;
	for(int i = 1;i<query_sort.size();i++){
		ret = update(arr,count,ret,query[get<2>(query_sort[i-1])],query[get<2>(query_sort[i])]);
		ans[get<2>(query_sort[i])] = ret;
	}
	for(int i = 0;i<query_size;i++)
		printf("%lld\n",ans[i]);
	return 0;
}