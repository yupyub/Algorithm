#include <cstdio>
#include <algorithm>
using namespace std;
int weight[30];
int bead;
int weight_num,bead_num;
int measurable[15001][31];
void f(int tot_weight,int count){
	if(count > weight_num)
		return;
	if(measurable[tot_weight][count])
		return;
	measurable[tot_weight][count] = 1;
	f(tot_weight+weight[count],count+1);
	f(tot_weight,count+1);
	f(abs(tot_weight-weight[count]),count+1);
}
int main(){
	scanf("%d",&weight_num);
	for(int i = 0;i<weight_num;i++)
		scanf("%d",&weight[i]);
	f(0,0);
	scanf("%d",&bead_num);
	int ans = 0;
	for(int i = 0;i<bead_num;i++){
		scanf("%d",&bead);
		ans = 0;
		for(int j = 0;j<=weight_num;j++){
			if(bead<=15000 && measurable[bead][j]){
				ans = 1;
				break;
			}
		}
		if(ans)
			printf("Y ");
		else
			printf("N ");
	}
}