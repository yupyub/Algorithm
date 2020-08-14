#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
#include <tuple>
#include <climits>
#include <cmath>
#include <map>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = 987654321;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int N,M;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
        char arr[101];
		scanf("%s",arr);
        int tmp = 0;
        vector<int> num;
		for(int i = 0;i<strlen(arr);i++){
            if(arr[i] == '0'){
                if(tmp!=0)
                    num.push_back(tmp);
                tmp = 0;
            }
            else   
                tmp += 1;
        }
        if(tmp!=0)
            num.push_back(tmp);
        sort(num.begin(),num.end());
        int ans = 0;
        for(int i = num.size()-1;i>=0;i-=2){
            ans += num[i];
        }
        printf("%d\n",ans);
	}


}