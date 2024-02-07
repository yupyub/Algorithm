import sys
from collections import deque 
input = sys.stdin.readline

def D(x):
    return (x*2) % 10000

def S(x):
    return 9999 if x == 0 else x - 1

def B(x):
    l = []
    dig = 1000
    for i in range(4):
        l.append(x//dig)
        x %= dig
        dig /= 10
    return l

def L(x):
    l = B(x)
    num = 0
    for i in l[1:]:
        num += i
        num *= 10
    num += l[0]
    return int(num)

def R(x):
    l = B(x)
    num = 0
    num += l[3]
    for i in l[:3]:
        num *= 10
        num += i
    return int(num)

op = {
    'D': [D(x) for x in range(10000)],
    'S': [S(x) for x in range(10000)],
    'L': [L(x) for x in range(10000)],
    'R': [R(x) for x in range(10000)]
}

def bfs(n, m, prev_op):
    q = deque()
    q.append(n)
    prev_op[n] = ('s', None)
    while q:
        x = q.popleft()
        if x == m:
            return
        for k in op.keys():
            nx = op[k][x]
            if prev_op[nx][0] != 'X':
                continue
            prev_op[nx] = (k, x)
            q.append(nx)

t = int(input().strip())
for _ in range(t):
    n, m = map(int, input().split())
    prev_op = [('X', None) for _ in range(10000)]
    bfs(n, m, prev_op)
    ans = []
    while prev_op[m][0] != 's':
        ans.append(prev_op[m][0])
        m = prev_op[m][1]
    for a in reversed(ans):
        print(a, end='')
    print()