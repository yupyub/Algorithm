#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	vector<int>v;
	int a,b,c;
	while(1){
		v.clear();
		scanf("%d %d %d",&a,&b,&c);
		if(a == 0) break;
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		sort(v.begin(),v.end());
		if(v[0]*v[0] +v[1]*v[1] == v[2]*v[2])
			printf("right\n");
		else printf("wrong\n");
	}
}
