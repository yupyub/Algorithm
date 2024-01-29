import sys
from queue import Queue
input = sys.stdin.readline

n, m = [int(x) for x in input().split()]

map = []
for i in range(n):
    map.append(input().split())

for i in range(n):
    for j in range(m):
        if map[i][j] == '2':
            sx = i
            sy = j

q = Queue()
dist = [[-1 for _ in range(m)] for _ in range(n)]
dist[sx][sy] = 0
q.put((sx, sy, 0))
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
while not q.empty():
    x, y, d = q.get()
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if not (0 <= nx < n):
            continue
        if not (0 <= ny < m):
            continue
        if dist[nx][ny] != -1:
            continue
        if map[nx][ny] == '0':
            continue
        dist[nx][ny] = d + 1
        q.put((nx, ny, d+1))

for i in range(n):
    for j in range(m):
        print(dist[i][j] if map[i][j] != '0' else 0, end=' ')
    print()