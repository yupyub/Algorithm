#include <cstdio>
#include <algorithm>
using namespace std;
int arr[10];
int pos[10];
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
		scanf("%d",&arr[i]);
	for(int i = 0;i<n;i++){
		int tot = 0;
		for(int j = 0;j<n;j++){
			if(pos[j] == 0)
				tot++;
			if(arr[i]==tot-1){
				pos[j] = i+1;
				break;
			}
		}
	}
	for(int i = 0;i<n;i++)
		printf("%d ",pos[i]);
}