#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
int arr[10];
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i = 0;i<n;i++)
		scanf("%d",&arr[i]);
	sort(arr,arr+n,greater<int>());
	int ans = 0;
	for(int i = 0;i<n;i++){
		if(k>=arr[i]){
			int tmp = k/arr[i];
			k=k%arr[i];
			ans += tmp;
		}
	}
	printf("%d\n",ans);
}
	