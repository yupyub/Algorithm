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
typedef long long ll;
char arr[101][101];
char f(char c){
	switch(c){
		case '.':
			return 46;
		case 'O':
			return 79;
		case '-':
			return '|';
		case '|':
			return '-';
		case '/':
			return '\\';
		case '\\':
			return '/';
		case 62:
			return 94;
		case 94:
			return 60;
		case 60:
			return 118;
		case 118:
			return 62;
	}
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 0;i<n;i++)
		scanf("%s",arr[i]);
	for(int j = m-1;j>=0;j--){
		for(int i = 0;i<n;i++){
			printf("%c",f(arr[i][j]));
		}
		printf("\n");
	}
}