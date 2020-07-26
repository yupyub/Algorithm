#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <queue>
#define FOR(i,n) for(int i=0; i<n ;i++)
using namespace std;

int n, t, nn;
vector< vector<int> > vv;
vector< int > res;
vector<int> vic;
void bfs(){
    queue<pair<int,int>> q;
	for(int i = 0;i<vic.size();i++){
	    q.push(make_pair(vic[i],0));
		res[vic[i]] = 0;
	}
    while(!q.empty()) {
        int front = q.front().first;
        int time = q.front().second;

        // if(res[front]!= -1)   res[front] = min(res[front],time);
        // else res[front] = time;

        q.pop();

        for (int i = 0; i < vv[front].size(); i++) {
            int sur = vv[front][i];
            if(res[sur] <= time && res[sur]!=-1) continue;
            /* 얼마나 감염? */
            int cnt = 0;
            for (int j = 0; j < vv[sur].size(); j++) {
                if (res[vv[sur][j]] != -1 && res[vv[sur][j]]<=time) cnt++;
            }

            /*update */
            if(cnt==0) continue;
            if (2*cnt >= (vv[sur].size()) ){
				if(res[sur] == -1){
                	q.push(make_pair(sur,time+1));
					res[sur] = time+1;
				}
            }
        }
    }
}

int main(){
    cin >> n;

    vv.resize(n+2);
    res.resize(n+2, -1);

    for(int i=1; i<=n ;i++){
        while(1){
            cin >> t;
            if(t==0) break;
            vv[i].push_back(t);
        }
    }

    cin >> nn;
    FOR(i,nn) {
        int rr;
        cin >> rr;
		vic.push_back(rr);
    }
	bfs();
    for(int i=1; i<=n ;i++){
        cout << res[i] << ' ';
    }
}