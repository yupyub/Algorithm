import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

n, m = [int(x) for x in input().split()]
_map = []
for i in range(n):
    _map.append(list(input().strip()))

visited = [[0 for _ in range(m)] for _ in range(n)]
for i in range(n):
    for j in range(m):
        if _map[i][j] == 'I':
            sx = i
            sy = j
            visited[i][j] = 1
        elif _map[i][j] == 'X':
            visited[i][j] = 1

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
def dfs(x, y):
    ans = 0
    if _map[x][y] == 'P':
        ans = 1
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or nx >= n or ny < 0 or ny >= m:
            continue
        if visited[nx][ny] == 0:
            visited[nx][ny] = 1
            ans += dfs(nx, ny)
    return ans

visited[sx][sy] = 1
ans = dfs(sx, sy)
if ans == 0:
    print('TT')
else:
    print(ans)