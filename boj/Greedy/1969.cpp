#include <cstdio>
int main(void){
	char dna[1000][51];
	int alp[50][26] = {0,};
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 0;i<n;i++){
		scanf("%s",dna[i]);
	}
	for(int i = 0;i<n;i++)
		for(int j = 0;j<m;j++)
			alp[j][dna[i][j]-'A']++;
	int hamming = 0;
	for(int i = 0;i<m;i++){
		int max_num = -1;
		int alphabet = 0;
		for(int j = 0;j<26;j++){
			if(alp[i][j]>max_num){
				max_num = alp[i][j];
				alphabet = j;
			}
		}
		hamming += n-max_num;
		printf("%c",'A'+alphabet);
	}
	printf("\n%d\n",hamming);
}