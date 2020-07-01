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
		char arr[100];
		scanf("%d",&n);
		scanf("%s",arr);
		stack<int>st;
		int maxi = 0;
		int temp = 0;
		for(int i = 0;i<n;i++){
			if(arr[i] == '(')
				st.push(1);
			else{
				if(!st.empty())
					st.pop();
				else
					temp++;
			maxi = max(maxi,temp);
			}
		}
		maxi = max(maxi,(int)st.size());
		printf("%d\n",maxi);
	}	
}