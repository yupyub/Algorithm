#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>
using namespace std;
vector<pair<double,int> > g[102]; // time,node
pair<double,double> pos[102];
double dist[102];
double dist_c(int i,int j){
	double a = pos[i].first - pos[j].first;
	double b = pos[i].second - pos[j].second;
	return sqrt(a*a+b*b);
}
double dijk(int s,int e){
	priority_queue<pair<double,int>,vector<pair<double,int> >,greater<pair<double,int> > >pq;
	dist[s] = 0;
	pq.push(make_pair(0,s));
	while(!pq.empty()){
		double cost = pq.top().first;
		int n = pq.top().second;
		pq.pop();
		for(auto I : g[n]){
			double c = I.first;
			int nx = I.second;
			if(cost+c<dist[nx]){
				dist[nx] = cost+c;
				pq.push(make_pair(dist[nx],nx));
			}
		}
	}
	return dist[e];
}	
int main(){
	int n;
	for(int i = 0;i<2;i++)
		scanf("%lf %lf",&pos[i].first,&pos[i].second);
	scanf("%d",&n);
	for(int i = 2;i<n+2;i++)
		scanf("%lf %lf",&pos[i].first,&pos[i].second);
	for(int i = 2;i<n+2;i++){
		for(int j = i+1;j<n+2;j++){
			double d = fabs(dist_c(i,j)-50)+10;
			g[i].push_back(make_pair(d,j));
			g[j].push_back(make_pair(d,i));
		}
	}
	g[0].push_back(make_pair(dist_c(0,1),1));
	for(int i = 2;i<n+2;i++){
		g[0].push_back(make_pair(dist_c(0,i),i));
		g[i].push_back(make_pair(fabs(dist_c(i,1)-50)+10,1));
	}
	for(int i = 0;i<n+2;i++)
		dist[i] = 987654321;
	printf("%lf\n",dijk(0,1)/5);
}