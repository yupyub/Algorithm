import sys
input = sys.stdin.readline

n = int(input())
paper = []
for i in range(n):
    l = input().strip().split()
    paper.append([int(x) for x in l])

'''

a,b        a,d



c,b        c,d

'''

def _sum(x, y):
    return (x[0] + y[0], x[1] + y[1])

def recur(paper, a, b, c, d):
    color = paper[a][b]
    split = False
    for i in range(a, c+1):
        for j in range(b, d+1):
            if paper[i][j] != color:
                split = True
    if not split:
        if color == 0:
            return (1, 0)
        else:
            return (0, 1)
    l = int((c-a+1)/2)
    ans = (0, 0)
    ans = _sum(ans, recur(paper, a, b, a+l-1, b+l-1))
    ans = _sum(ans, recur(paper, a, b+l, a+l-1, d))
    ans = _sum(ans, recur(paper, a+l, b, c, b+l-1))
    ans = _sum(ans, recur(paper, a+l, b+l, c, d))
    return ans

ans = recur(paper, 0, 0, n-1, n-1)
print(ans[0])
print(ans[1])
