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

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int temp = n;
		int a = 0,b = 0;
		while(temp%2 == 0){
			temp = temp/2;
			a++;
		}
		while(temp%3 == 0){
			temp = temp/3;
			b++;
		}
		if(temp!=1)
			printf("-1\n");
		else if(a>b)
			printf("-1\n");
		else
			printf("%d\n",b+b-a);
	}
}