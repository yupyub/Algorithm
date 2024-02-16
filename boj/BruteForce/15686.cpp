#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int c;
    vector<pair<int, int> > house;
    vector<pair<int, int> > chick;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%1d", &c);
            if(c == 1){
                house.push_back(make_pair(i, j));
            }
            else if(c == 2){
                chick.push_back(make_pair(i, j));
            }
        }
    }
    int dist[100][13] = {0,};
    for(int i = 0; i<house.size(); i++){
        for(int j = 0; j<chick.size(); j++){
            dist[i][j] += abs(house[i].first - chick[j].first);
            dist[i][j] += abs(house[i].second - chick[j].second);
        }
    }
    int ans = 987654321;
    int count, total;
    int temp[50];
    for(int i = 0; i<(2<<14); i++){
        count = 0;
        for(int j = 0; j<chick.size(); j++)
            if(i & (1<<j))
                count += 1;
        if(count > m)
            continue;
        total = 0;
        for(int j = 0; j<house.size(); j++){
            temp[j] = 9876543;
            for(int k = 0; k<chick.size(); k++){
                if(i & (1<<k))
                    temp[j] = min(temp[j], dist[j][k]);
            }
            total += temp[j];
        }
        ans = min(ans, total);
    }
    printf("%d\n", ans);
    return 0;
}