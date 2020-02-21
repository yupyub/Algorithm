#include <cstdio>
#include <vector>
using namespace std;
int arr[1000001];
vector<char> siz;
int main(){
	int J,A,num;
	char c;
	scanf("%d %d",&J,&A);
	for(int i = 0;i<J;i++){
		scanf("\n%c",&c);
		siz.push_back(c);
	}
	int ans = 0;
	for(int i = 0;i<A;i++){
		scanf("\n%c %d",&c,&num);
		num--;
		if(arr[num]) continue;
		if(c == siz[num]){
			arr[num] = 1;
			ans++;
		}
		else if(c == 'M' && siz[num] == 'L'){
			arr[num] = 1;
			ans++;
		}
		else if(c == 'S') {
			arr[num] = 1;
			ans++;
		}
	}
	printf("%d\n",ans);
}