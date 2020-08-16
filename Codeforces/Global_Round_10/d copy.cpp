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
char arr[200001];
int main(){
   int t;
   scanf("%d",&t);
   while(t--){
      int n;
	  int ans = 0;
	  scanf("%d",&n);
      scanf("%s",arr);
	  int num = 1;
	  int i;
	  for(i = n-1;i>0;i--){
		if(arr[i] != arr[0])
			break;
		num++;
		if(num == 3){
			num = 0;
			ans++;
		}
	  	
	  }
	  if(!i){
		  if(num)
		  	ans++;
		printf("%d\n",ans);
		continue;
	  }
	  for(int j = 1;j<=i;j++){
		  if(arr[j] == arr[j-1]){
			  num++;
			  if(num==3){
				  num = 0;
				  ans++;
			  }
		  }
		  else
		  	num = 1;
	  }
	  printf("%d\n",ans);
   }
}