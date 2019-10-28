#include <cstdio>
#include <vector>
using namespace std;
int arr[11];
int calc[4];
int mini = 1000000001;
int maxi = -1000000001;
vector<int> v;
void f(int a,int t){
	if(a == t){
		int tot = arr[0];
		for(int i = 0;i<t;i++){
			switch(v[i]){
				case 0: tot += arr[i+1]; break;
				case 1: tot -= arr[i+1]; break;
				case 2: tot *= arr[i+1]; break;
				case 3: tot /= arr[i+1]; break;
			}
		} 
		if(tot<mini) mini = tot;
		if(tot>maxi) maxi = tot;
	}
	for(int i = 0;i<4;i++){
		if(calc[i] == 0) continue;
		calc[i]--;
		v.push_back(i);
		f(a+1,t);
		v.pop_back();
		calc[i]++;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
		scanf("%d",&arr[i]);
	for(int i = 0;i<4;i++)
		scanf("%d",&calc[i]);
	f(0,n-1);
	printf("%d\n%d\n",maxi,mini);
}