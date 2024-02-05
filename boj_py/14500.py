import sys
input = sys.stdin.readline

n, m = [int(x) for x in input().split()]
mmap = []
for i in range(n):
    mmap.append([int(x) for x in input().split()])

visit = [[0 for _ in range(m)] for _ in range(n)]
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]
ans = 0

def dfs(x, y, d, s):
    if d == 4:
        global ans
        ans = max(ans, s)
        return
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx >= n or nx < 0 or ny >= m or ny < 0:
            continue
        if visit[nx][ny]:
            continue
        visit[nx][ny] = 1
        dfs(nx, ny, d+1, s+mmap[nx][ny])
        visit[nx][ny] = 0

def shape2(x, y):
    vals = []
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx >= n or nx < 0 or ny >= m or ny < 0:
            continue
        vals.append(mmap[nx][ny])
    if len(vals) < 3:
        return
    st = 0
    if len(vals) == 4:
        vals.sort()
        st = 1
    tmp = mmap[x][y]
    for i in vals[st:]:
        tmp += i
    global ans
    ans = max(ans, tmp)

for i in range(n):
    for j in range(m):
        visit[i][j] = 1
        dfs(i, j, 1, mmap[i][j])
        visit[i][j] = 0
        shape2(i, j)

print(ans)