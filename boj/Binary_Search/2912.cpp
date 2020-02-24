#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

int main(){
	int nan_num,color_num,color;
	scanf("%d %d",&nan_num,&color_num);
	vector<vector<int> >color_pos;
	vector<int> picture;
	color_pos.resize(color_num+1);
	for(int i = 0;i<nan_num;i++){
		scanf("%d",&color);
		picture.push_back(color);
		color_pos[color].push_back(i);
	}
	int query_num,qu1,qu2,get_random,random_color,random_color_num,ans;
	scanf("%d",&query_num);
	for(int i = 0;i<query_num;i++){
		scanf("%d %d",&qu1,&qu2);
		get_random = 30; // 임의의 횟수만큼 랜덤하게 원소를 뽑는다.
		ans = 0;
		while(get_random--){
			random_color = picture[rand()%(qu2-qu1+1)+qu1-1];
			random_color_num = upper_bound(color_pos[random_color].begin(),color_pos[random_color].end(),qu2-1)-lower_bound(color_pos[random_color].begin(),color_pos[random_color].end(),qu1-1);
			//printf("%d %d >> %d %d\n",qu1,qu2,random_color,random_color_num);
			if(random_color_num>(qu2-qu1+1)/2){
				ans = 1;
				break;
			}
		}
		if(ans)
			   printf("yes %d\n",random_color);
		else
			printf("no\n");
	}
}