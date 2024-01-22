import sys
input = sys.stdin.readline
round = lambda x : int(x+0.5)

num = int(input())
if num == 0:
    print(0)
    exit(0)
l = []
for i in range(num):
    l.append(int(input()))

s = round(num * 0.15)
l.sort()
ans = 1.0 * sum(l[s : num-s]) / (num - 2*s)
print(round(ans))