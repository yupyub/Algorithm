#include <cstdio>
#include <algorithm>
using namespace std;
// ~_bound(first,last,val) : An iterator to the ~_bound of val in the range [first,last)
// upper_bound(arr,arr+n,k) : k 초과인 수가 처음으로 등장하는 위치 (iterator)
// upper_bound(~) - arr : index
// lower_bound(vector.begin(),vector.end(),k) : k 이상인 수가 처음으로 등장하는 위치 (iterator)
// lower_bound(~) - vector.begin() : index
// 두 함수 모두 탐색을 성공하지 못한 경우, last 를 return 한다
int arr[500000];
int qu[500000];
int main(){
	int n,m;
	scanf("%d",&n);
	for(int i = 0 ;i<n;i++)
		scanf("%d",&arr[i]); 
	scanf("%d",&m);
	for(int i = 0;i<m;i++)
		scanf("%d",&qu[i]);
	sort(arr,arr+n);
	for(int i = 0;i<m;i++)
		printf("%d ",upper_bound(arr,arr+n,qu[i])-lower_bound(arr,arr+n,qu[i]));
}