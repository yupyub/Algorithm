#include <cstdio>
#include <set>
using namespace std;

int map[9][9];
int box[9] = {0, };
int row[9] = {0, };
int col[9] = {0, };

int _idx(int x, int y){
    return 3 * (x/3) + y/3;
}

bool dfs(int x, int y){
    if(x == 9){
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                printf("%d", map[i][j]);
            }
            printf("\n");
        }
        return true;
    }
    if(map[x][y]){
        if(y == 8){
            if(dfs(x+1, 0))
                return true;
        }
        else{
            if(dfs(x, y+1))
                return true;
        }
    }
    else{
        for(int val = 0; val < 9; val++){
            if(row[x] & (1 << val))
                continue;
            if(col[y] & (1 << val))
                continue;
            if(box[_idx(x, y)] & (1 << val))
                continue;
            map[x][y] = val + 1;
            row[x] |= (1 << val);
            col[y] |= (1 << val);
            box[_idx(x, y)] |= (1 << val);
            if(y == 8){
                if(dfs(x+1, 0))
                    return true;
            }
            else{
                if(dfs(x, y+1))
                    return true;
            }
            map[x][y] = 0;
            row[x] &= ~(1 << val);
            col[y] &= ~(1 << val);
            box[_idx(x, y)] &= ~(1 << val);
        }
    }
    return false;
}

int main(){
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            scanf("%1d", &map[i][j]);
        }
    }
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            if(map[i][j] != 0){
                box[_idx(i, j)] |= (1 << (map[i][j]-1));
                row[i] |= (1 << (map[i][j]-1));
                col[j] |= (1 << (map[i][j]-1));
            }
        }
    }
    dfs(0, 0);
    return 0;
}