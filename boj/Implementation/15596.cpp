#include <cstdio>
#include <vector>
long long sum(std::vector<int> &a){
	long long su = 0;
	for(int i = 0;i<a.size();i++){
		su += a[i];
	}
	return su;
}