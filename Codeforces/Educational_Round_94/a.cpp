#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
#include <tuple>
#include <functional>
using namespace std;
char arr[200];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		scanf("%s",arr);
		for(int i = 0;i<2*n-1;i+=2){
			printf("%c",arr[i]);
		}
		printf("\n");
	}
}