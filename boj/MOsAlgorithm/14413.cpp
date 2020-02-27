// MO's Algorithm
// 그냥 시간복잡도는 O(N^2) 이지만 
// Sqrt decomposition 기법을 이용해 O(Q(N+Q)sqrt(N))으로 최적화 (Q:query수)
#include <cstdio>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cmath>
#include <map>
using namespace std;
int add_range(int arr[],int count[],int ret,int i){
	if(count[arr[i]] == 1) ret++;
	else if(count[arr[i]] == 2) ret--;
	count[arr[i]]++;
	return ret;
}
int del_range(int arr[],int count[],int ret,int i){
	if(count[arr[i]] == 3) ret++;
	else if(count[arr[i]] == 2) ret--;
	count[arr[i]]--;
	return ret;	
}
int init(int arr[],int count[], int ret,pair<int,int> qu){
	for(int i = qu.first;i<=qu.second;i++)
		ret = add_range(arr,count,ret,i);
	return ret;
}
int update(int arr[],int count[], int ret,pair<int,int> qu1,pair<int,int>qu2){
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
	int arr_size,query_size,qu1,qu2,ret = 0;
	int arr[500001] = {0,};
	int count[500001] = {0,};
	scanf("%d %d",&arr_size,&query_size);
	map<int,long long>number;
	long long num;
	for(int i = 0;i<arr_size;i++){
		scanf("%lld",&num);
		if(number[num] == 0)
			number[num] = i+1;
		arr[i] = number[num];
	}
	vector<pair<int,int> > query;
	vector<tuple<int,int,int> >query_sort;
	vector<int>ans;
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
		printf("%d\n",ans[i]);
	return 0;
}