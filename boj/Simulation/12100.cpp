#include <cstdio>
#include <algorithm>
using namespace std;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
// 상 하 좌 우
// 0 1 2 3
void copy_arr(int source[][20], int to[][20]){
    for(int i = 0; i<20; i++)
        for(int j = 0; j<20; j++)
            to[i][j] = source[i][j];
    return;
}

void _simulation(int N, int map[][20], int dir){
    int result[20][20] = {0, };
    if(dir == 0){ // 상
        for(int j = 0; j<N; j++){
            int result_idx = 0;
            int prev_val = 0;
            for(int i = 0; i<N; i++){
                if(map[i][j]){
                    if(map[i][j] == prev_val){
                        result[result_idx++][j] = map[i][j] * 2;
                        prev_val = 0;
                    }
                    else{
                        if(prev_val){
                            result[result_idx++][j] = prev_val;
                            prev_val = map[i][j];
                        }
                        else{
                            prev_val = map[i][j];
                        }
                    }
                }
            }
            if(prev_val){
                result[result_idx][j] = prev_val;
            }
        }
    }
    else if(dir == 1){ // 하
        for(int j = 0; j<N; j++){
            int result_idx = N-1;
            int prev_val = 0;
            for(int i = N-1; i>=0; i--){
                if(map[i][j]){
                    if(map[i][j] == prev_val){
                        result[result_idx--][j] = map[i][j] * 2;
                        prev_val = 0;
                    }
                    else{
                        if(prev_val){
                            result[result_idx--][j] = prev_val;
                            prev_val = map[i][j];
                        }
                        else{
                            prev_val = map[i][j];
                        }
                    }
                }
            }
            if(prev_val){
                result[result_idx][j] = prev_val;
            }
        }
    }
    else if(dir == 2){ // 좌
        for(int i = 0; i<N; i++){
            int result_idx = 0;
            int prev_val = 0;
            for(int j = 0; j<N; j++){
                if(map[i][j]){
                    if(map[i][j] == prev_val){
                        result[i][result_idx++] = map[i][j] * 2;
                        prev_val = 0;
                    }
                    else{
                        if(prev_val){
                            result[i][result_idx++] = prev_val;
                            prev_val = map[i][j];
                        }
                        else{
                            prev_val = map[i][j];
                        }
                    }
                }
            }
            if(prev_val){
                result[i][result_idx] = prev_val;
            }
        }
    }
    else if(dir == 3){ // 우
        for(int i = 0; i<N; i++){
            int result_idx = N-1;
            int prev_val = 0;
            for(int j = N-1; j>=0; j--){
                if(map[i][j]){
                    if(map[i][j] == prev_val){
                        result[i][result_idx--] = map[i][j] * 2;
                        prev_val = 0;
                    }
                    else{
                        if(prev_val){
                            result[i][result_idx--] = prev_val;
                            prev_val = map[i][j];
                        }
                        else{
                            prev_val = map[i][j];
                        }
                    }
                }
            }
            if(prev_val){
                result[i][result_idx] = prev_val;
            }
        }
    }
    copy_arr(result, map);
    return;
}

int simulation(int N, int map[][20], int turn, int dir){
    int ret = 0;
    if(dir > -1){
        _simulation(N, map, dir);
    }
    if(turn == 5){
        for(int i = 0; i<N; i++)
            for(int j = 0; j<N; j++)
                ret = max(ret, map[i][j]);
        return ret;
    }
    int backup[20][20];
    copy_arr(map, backup);
    for(int i = 0; i<4; i++){
        if(i != 0)
            copy_arr(backup, map);
        ret = max(ret, simulation(N, map, turn+1, i));
    }
    return ret;
}

int main(){
    int N;
    int map[20][20];
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            scanf("%d", &map[i][j]);
        }
    }
    int ans = simulation(N, map, 0, -1);
    printf("%d\n", ans);
    return 0;
}