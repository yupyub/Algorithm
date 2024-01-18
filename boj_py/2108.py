import sys
from collections import Counter
input = sys.stdin.readline


num = int(input())
l = []
for _ in range(num):
    l.append(int(input()))

print(int(round(1.0 * sum(l) / len(l))))

l.sort()
print(l[int(len(l)/2)])

common = Counter(l).most_common(2)
ans = common[0][0]
if len(common) > 1 and common[0][1] == common[1][1]:
    common.sort()
    ans = common[1][0]
print(ans)

print(l[-1] - l[0])
