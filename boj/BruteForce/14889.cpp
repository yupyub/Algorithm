#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int arr[20][20];
vector<int>v1,v2;
int ans = 100000000;
void f(int a,int b){
	if(ans == 0) return;
	if(a == b){
		int sum = 0;
		for(int i = 0;i<b/2-1;i++){
			for(int j = i+1;j<b/2;j++){
				sum += arr[v1[i]][v1[j]] + arr[v1[j]][v1[i]];
				sum -= arr[v2[i]][v2[j]] + arr[v2[j]][v2[i]];
			}
		}
		ans = min(ans,abs(sum));
	}
	if(v1.size()<b/2){
		v1.push_back(a);
		f(a+1,b);
		v1.pop_back();
	}
	if(v2.size()<b/2){
		v2.push_back(a);
		f(a+1,b);
		v2.pop_back();
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
		for(int j = 0;j<n;j++)
			scanf("%d",&arr[i][j]);
	f(0,n);
	printf("%d",ans);
}