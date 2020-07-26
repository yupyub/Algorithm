#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
#include <tuple>
#include <climits>
#include <cmath>
#include <map>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = 987654321;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int N,M;
char str1[] = "1-3-5-7-10-13-16-19-22-\0";
char str2[] = "-2-4-6-8-11-14-17-20-23\0";
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int a,b;
		scanf("%d %d",&a,&b);
		if(a%2){// -> 아님
        /////
        //?????
        /////
			if(a>=21 || (b>0&&a>2) || (b>1)){
				for(int i = 0;i<17;i++){
					printf("%c",str1[i]);
				}
                printf("...");
			}
			else{
				int tmp = a*(b==0?1:10);
				for(int i = 0;i<tmp;i++){
					printf("%c",str1[i]);
				}
			}
		}
		else{
			if(a>=21 || (b>0&&a>2) || (b>1)){
				for(int i = 0;i<17;i++){
					printf("%c",str2[i]);
				}
                printf("...");
			}
			else{
				int tmp = a*(b==0?1:10);
				for(int i = 0;i<tmp;i++){
					printf("%c",str2[i]);
				}
			}
		}
		printf("\n");
	}
}