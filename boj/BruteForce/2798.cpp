#include <cstdio>
int arr[100];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 0;i<n;i++)
		scanf("%d",&arr[i]);
	int ans, sum, mini = 987654321,tmp;
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			for(int k = j+1;k<n;k++){
				sum = arr[i] + arr[j] + arr[k];
				if(m>=sum && m-sum<mini){
					mini = m-sum;
					ans = sum;
				}
			}
		}
	}
	printf("%d",ans);
}