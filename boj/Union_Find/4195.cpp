#include <cstdio>
#include <string>
#include <iostream>
#include <map>
using namespace std;

int parent[200001];
int counts[200001];
map<string, int> m;

int _find(int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = _find(parent[x]);
}

void _union(int x, int y){
    parent[_find(x)] = _find(y);
}

int get_iid(string name, int *iid){
    if(m[name] == 0){
        m[name] = (*iid)++;
    }
    return m[name];
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        int F;
        cin >> F;
        for(int i = 1; i<=2*F; i++){
            parent[i] = i;
            counts[i] = 1;
        }
        m.clear();
        int iid = 1;
        int x, y, cx, cy;
        string name1, name2;
        for(int i = 0; i<F;i++){
            cin >> name1 >> name2;
            x = get_iid(name1, &iid);
            y = get_iid(name2, &iid);
            if(_find(x) != _find(y)){
                cx = counts[_find(x)];
                cy = counts[_find(y)];
                _union(x, y);
                counts[_find(x)] = cx + cy;
            }  
            cout << counts[_find(x)] << '\n';  // endl은 시간초과 난다;;
        }
    }

    return 0;
}