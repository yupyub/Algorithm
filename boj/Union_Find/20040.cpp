#include <cstdio>

int parent[500000];

int Find(int a){
    if(parent[a] == a)
        return a;
    return parent[a] = Find(parent[a]);
}

void Union(int a, int b){
    parent[Find(a)] = Find(b);
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i<n; i++)
        parent[i] = i;
    int a, b;
    int ans = 0;
    for(int i = 0; i<m; i++){
        scanf("%d %d", &a, &b);
        if(Find(a) == Find(b)){
            if(ans == 0)
                ans = i+1;
        }
        else{
            Union(a, b);
        }
    }
    printf("%d\n", ans);
}