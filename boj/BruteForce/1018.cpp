#include <cstdio>
char arr[51][51];
char arr1[8][8];
char arr2[8][8];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 0;i<n;i++)
		scanf("%s",arr[i]);
	for(int i = 0;i<8;i++){
		for(int j = 0;j<8;j++){
			if((i+j)%2 == 0){
				arr1[i][j] = 'B';
				arr2[i][j] = 'W';
			}
			else{
				arr2[i][j] = 'B';
				arr1[i][j] = 'W';
			}
		}
	}
	int ans = 987654321;
	for(int i = 0;i<n-7;i++){
		for(int j = 0;j<m-7;j++){
			int sum1 = 0,sum2 = 0;
			for(int ii = i;ii<i+8;ii++){
				for(int jj = j;jj<j+8;jj++){
					if(arr[ii][jj] != arr1[ii-i][jj-j])
						sum1++;
					if(arr[ii][jj] != arr2[ii-i][jj-j])
						sum2++;
				}
			}
			if(sum1<ans)
				ans = sum1;
			if(sum2<ans)
				ans = sum2;
		}
	}
	printf("%d\n",ans);
}
	