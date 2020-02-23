#include <cstdio>
#include <cstring>
#include <utility>
using namespace std;
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};
int dir_pair[] = {7,6,5,4,3,2,1,0};
pair<int,int> XO_counter(char str[],int map[][3]){
	int X_count = 0,O_count = 0;
	for(int i = 0;i<3;i++){
		for(int j = 0;j<3;j++){
			if(str[i*3+j] == 'X'){
				map[i][j] = 1;
				X_count++;
			}
			else if(str[i*3+j] == 'O'){
				map[i][j] = 2;
				O_count++;
			}
			else{
				map[i][j] = 0;
			}
		}
	}
	return make_pair(X_count,O_count);
}
int win_check(int map[][3],int visit[][3],int x,int y,int type,int cnt,int dir1,int dir2){
	//printf("(%d %d %d %d %d)",x,y,cnt,dir1,dir2);
	int total = 1;
	for(int i = 0;i<8;i++){
		if(i != dir1 && i!=dir2)
			continue;
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx<0 || ny<0 || nx>=3 || ny>=3) 
			continue;
		if(map[nx][ny] == type && visit[nx][ny] < cnt){
			visit[nx][ny] = cnt;
			total += win_check(map,visit,nx,ny,type,cnt,dir1,dir2);
		}
	}
	return total;
}
int valid_check(char str[]){
	int map[3][3];
	int visit[3][3] = {0,};
	pair<int,int> count = XO_counter(str,map); 
	if(count.first != count.second && count.first != count.second+1)
		return 0;
	int O_win = 0,cnt = 1,X_win = 0,temp,same_dir_win = 0;
	for(int k = 0;k<4;k++){
		same_dir_win = 0;
		for(int i = 0;i<3;i++){
			for(int j = 0;j<3;j++){
				if(map[i][j] != 0 && visit[i][j] <cnt){
					visit[i][j] = cnt;
					temp = win_check(map,visit,i,j,map[i][j],cnt,k,dir_pair[k]);
					//printf(" <%d %d %d> ",i,j,temp);
					if(temp==3){
						same_dir_win++;
						if(map[i][j] == 2)
							O_win++;
						else
							X_win++;
					}
				}
			}
		}
		cnt++;
		if(O_win*X_win != 0)
			return 0;
		if(same_dir_win>1)
			return 0;
	}
	//printf(">> %d %d %d %d ",X_win,O_win,count.first,count.second);
	if(X_win == 2)
		return 1;
	else if(O_win == 1 && count.first == count.second)
		return 1;
	else if(O_win == 0 && X_win == 0 && count.first == 5 &&count.second == 4)
		return 1;
	else if(X_win == 1 && count.first==count.second+1)
		return 1;
	return 0;
}
int main(){
	char str[10];
	while(1){
		scanf("%s",str);
		if(strcmp(str,"end") == 0)
			break;
		if(valid_check(str))
			printf("valid\n");
		else
			printf("invalid\n");
	}
}
	