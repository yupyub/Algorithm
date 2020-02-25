// MO's Algorithm
// 그냥 시간복잡도는 O(N^2) 이지만 
// Sqrt decomposition 기법을 이용해 O(Q(N+Q)sqrt(N))으로 최적화 (Q:query수)
#pragma GCC optimize("O3")
#include <cstdio>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cmath>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
map<ll,int> number;
ll number_rev[100002];
vector<ll>tree;
int arr_size,query_size,qu1,qu2;
ll tree_max(int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[node];
	return max(tree_max(node * 2, start, (start + end) / 2, left, right), tree_max(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}
void tree_update(int node, int start, int end, int index, ll diff) {
	if (index<start || index > end)
		return ;
	if(start == end){
		tree[node] += diff;
		//printf("%d %d %lld >>  \n",node,index,diff);
		return;
	}
	
	tree_update(node * 2, start, (start + end) / 2, index, diff);
	tree_update(node * 2+1, (start+end)/2+1, end, index, diff);
	tree[node] = max(tree[node*2],tree[node*2+1]);
	//printf("%d %d %lld < %lld %lld > \n",node,index,diff, tree[node*2],tree[node*2+1]);
}
void add_range(int arr[],int count[],int i){
	count[arr[i]]++;
	tree_update(1,1,arr_size,arr[i],number_rev[arr[i]]);
	//printf("add >> %d %lld\n",i,number_rev[arr[i]]);
}
void del_range(int arr[],int count[],int i){
	count[arr[i]]--;
	tree_update(1,1,arr_size,arr[i],-number_rev[arr[i]]);
	//printf("del >> %d %lld\n",i,number_rev[arr[i]]);
}
void init(int arr[],int count[], pair<int,int> qu){
	for(int i = qu.first;i<=qu.second;i++)
		add_range(arr,count,i);
}
void update(int arr[],int count[], pair<int,int> qu1,pair<int,int>qu2){
	//printf("=== update ===(%d %d) (%d %d)\n",qu1.first,qu1.second,qu2.first,qu2.second);
	for(int i = qu1.first-1;i>=qu2.first;i--)
		add_range(arr,count,i);
	for(int i = qu1.first;i<qu2.first;i++)
		del_range(arr,count,i);
	for(int i = qu1.second+1;i<=qu2.second;i++)
		add_range(arr,count,i);
	for(int i = qu1.second;i>qu2.second;i--)
		del_range(arr,count,i);
}
int main(){
	ll num;
	int arr[100000] = {0,};
	int count[100001] = {0,};
	scanf("%d %d",&arr_size,&query_size);
	tree.resize((arr_size+1)*4);
	for(int i = 0;i<arr_size;i++){
		scanf("%lld",&num);
		if(number[num] == 0)
			number[num] = i+1;
		arr[i] = number[num];
		number_rev[number[num]] = num;
	}
	vector<pair<int,int> > query;
	vector<tuple<int,int,int> >query_sort;
	vector<ll>ans;
	ans.resize(query_size);
	//int sqrt_n = sqrt(arr_size);
	int sqrt_n = 200;
	for(int i = 0;i<query_size;i++){
		scanf("%d %d",&qu1,&qu2);
		qu1--,qu2--;
		query.push_back(make_pair(qu1,qu2));
		query_sort.push_back(make_tuple(qu1/sqrt_n,qu2,i));
	}
	sort(query_sort.begin(),query_sort.end());
	init(arr,count,query[get<2>(query_sort[0])]);
	ans[get<2>(query_sort[0])] = tree_max(1,1,arr_size,1,arr_size);
	//printf("ans >> %d %d %lld\n",query[get<2>(query_sort[0])].first,query[get<2>(query_sort[0])].second,ans[get<2>(query_sort[0])]);
	for(int i = 1;i<query_sort.size();i++){
		update(arr,count,query[get<2>(query_sort[i-1])],query[get<2>(query_sort[i])]);
		ans[get<2>(query_sort[i])] = tree_max(1,1,arr_size,1,arr_size);
		//printf("ans >> %d %d %lld\n",query[get<2>(query_sort[i])].first,query[get<2>(query_sort[i])].second,ans[get<2>(query_sort[i])]);
	}
	for(int i = 0;i<query_size;i++)
		printf("%lld\n",ans[i]);
	return 0;
}