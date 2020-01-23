#include <cstdio>
int pos[10];
int main(){
	int n,num;
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
		scanf("%d",&num);
		for(int j = 0;j<n;j++){
			if(num == 0 && pos[j] == 0){
				pos[j] = i;
				break;
			}
			if(pos[j]==0) num--;
		}
	}
	for(int i = 0;i<n;i++)
		printf("%d ",pos[i]);
	printf("\n");
}