import sys
from queue import Queue
input = sys.stdin.readline

n, m = [int(x) for x in input().split()]
ladder = {}
for i in range(n):
    x, y = [int(a) for a in input().split()]
    ladder[x] = y

for i in range(m):
    x, y = [int(a) for a in input().split()]
    ladder[x] = y

visit = [999999 for i in range(101)]
q = Queue()
q.put((1, 0))
visit[1] = 0
while not q.empty():
    x, d = q.get()
    for i in range(1, 7):
        nx = x + i
        if nx > 100:
            continue
        if visit[nx] > d+1:
            visit[nx] = d+1
            if nnx := ladder.get(nx, None):
                if visit[nnx] > d+1:
                    visit[nnx] = d+1
                    q.put((nnx, d+1))
            else:
                q.put((nx, d+1))

print(visit[100])