#include <cstdio>
int x[1001];
int y[1001];
int main(){
	int a,b;
	for(int i = 0;i<3;i++){
		scanf("%d %d",&a,&b);
		x[a]++;
		y[b]++;
	}
	for(int i = 0;i<1001;i++){
		if(x[i] == 1) {
			printf("%d ",i);
			break;
		}
	}
	for(int i = 0;i<1001;i++){
		if(y[i] == 1){
			printf("%d",i);
			break;
		}
	}
}