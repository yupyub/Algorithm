#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int notPrime[100000];
vector<int> prime;
vector<int>g[5000];
void checkPrime(){
	for(int i = 2;i<10000;i++){
		if(!notPrime[i]){
			int j = 2;
			while((i*j)<10000){
				notPrime[i*j]=1;
				j++;
				printf("%d %d\n",i*j,j);
				fflush(stdout);
			}
		}
	}
}
int similar(int a,int b){
	int tmp = b-a;
	if(tmp<10) return 1;
	else if(tmp<100 && tmp%10 == 0) return 1;
	else if(tmp<1000 && tmp%100 == 0) return 1;
	else if(tmp<10000 && tmp%1000 == 0) return 1;
	return 0;
}
int main(){
	checkPrime();
	/*
	for(int i = 1000;i<10000;i++)
		if(notPrime[i]) prime.push_back(i);
	for(int i = 0;i<prime.size();i++){
		for(int j = i+1;j<prime.size();j++){
			if(similar(prime[i],prime[j])){
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}
	int T,s,e;
	*/
}
	