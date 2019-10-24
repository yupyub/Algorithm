#include <cstdio>
#include <stack>
using namespace std;
int arr[1000000];
int nge[1000000];
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	stack<int> s;
	for(int i = n-1;i>=0;i--){
		while(!s.empty() && s.top()<=arr[i]) 
			s.pop();
		if(s.empty()) 
			nge[i] = -1;
		else 
			nge[i] = s.top();
		s.push(arr[i]);
	}
	for(int i = 0;i<n;i++)
		printf("%d ",nge[i]);
}